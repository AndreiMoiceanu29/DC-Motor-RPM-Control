#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include "Proces.hpp"
#include "Regulator_PID.hpp"
#define ENCODEROUTPUT 420
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
String incrementSign;
//const int incrementVal = 5;
const int HALLSEN_A = 2;
const int MOTOR1A = 9;
const int EMERGENCY_STOP_BTN = 7;
const int INCREMENT_BTN = 6;
const int DECREMENT_BTN = 5;

volatile long encoderValue = 0;
int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;
double rpm = 0.0;
boolean measureRpm = false;
int sp = 150;
volatile byte state;
Proces *proces;
Regulator_PID *pid;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("  RPM Controll");
  lcd.setCursor(0,1);
  lcd.print("PV:");
  lcd.print(0);
  lcd.setCursor(7,1);
  lcd.print("SP:");
  lcd.print(sp);
  proces = new Proces(150.0);
  //pinMode(stateButton,INPUT_PULLUP);
  pinMode(MOTOR1A, OUTPUT);
  pinMode(INCREMENT_BTN,INPUT);
  pinMode(DECREMENT_BTN,INPUT);
  pinMode(EMERGENCY_STOP_BTN,INPUT);

  encoderValue = 0;
  previousMillis = millis();
  attachInterrupt(digitalPinToInterrupt(HALLSEN_A), updateEncoder, RISING);
  //pid = new Regulator_PID(0.6,0.001,0.00008);
 // pid = new Regulator_PID(13.6039250704919,1.87268116711016,20.1258379354778,42.732275692887);
    pid = new Regulator_PID(1.92618973060002,-0.141046343180695,0.04163423593456,0.691039508677056);
  //Comentariu aici
  //pid = new Regulator_PID(2.74931734050342,0.388980956243669,3.18688067029227,18.3486329442641);
  //pid = new Regulator_PID(6.5860852745968,4.26521868205626,4.11129582096853,0);
  //pid = new Regulator_PID(15.2186543643273,2.68099408028429,10.9306844375902,0);

}

void loop() {

//   if(proces->getState() == false){
//  lcd.print("  RPM Controll");
// }else{
//  lcd.print("  Poz Controll");
// }

  ///lcd.print("  ");

  currentMillis = millis();
  Semnal eroare = pid->calculeaza_eroare(proces->getPv(),proces->getSp());
  Semnal comanda = pid->genereaza_comanda(eroare);
  Serial.println(eroare.getVal());

  analogWrite(MOTOR1A,floor(comanda.getVal()));

  if(currentMillis - previousMillis > interval){
    previousMillis = currentMillis;

    rpm = (double)(encoderValue * 60 /(ENCODEROUTPUT));

    if(rpm > 0){
      proces->updatePv(rpm);
      lcd.setCursor(0,1);
      lcd.print("PV:");
      lcd.print((int)floor(proces->getPv().getVal()));
      lcd.setCursor(7,1);
      lcd.print("SP:");
      lcd.print((int)floor(proces->getSp().getVal()));

    }
    encoderValue = 0;
  }
  if(digitalRead(INCREMENT_BTN) == HIGH){
    proces->incrementSp(0);
    delay(100);
  }
  if(digitalRead(DECREMENT_BTN) == HIGH){
    proces->incrementSp(1);
    delay(100);
  }
  if(digitalRead(EMERGENCY_STOP_BTN) == HIGH){
    proces->setSp(0);
    proces->updatePv(0);
  }
  // put your main code here, to run repeatedly:

}

void updateEncoder()
{
  // Add encoderValue by 1, each time it detects rising signal
  // from hall sensor A
  encoderValue++;
}

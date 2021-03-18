#include "Regulator_PID.hpp"
#include "Interval.hpp"
#include "Semnal.hpp"

Regulator_PID::Regulator_PID(){
	this->Kp = 0;
	this->Kd = 0;
	this->Ki = 0;
	this->sum_err = 0;
	this->prev_err = 0;
	this->filtru = 0;
}

Regulator_PID::Regulator_PID(double Kp, double Kd, double Ki, double N){
	this->Kp = Kp;
	this->Kd = Kd;
	this->Ki = Ki;
	this->sum_err = 0;
	this->prev_err = 0;
	this->N = N;
	this->filtru = 0;
}

void Regulator_PID::setKp(double Kp){
	this->Kp = Kp;
}

void Regulator_PID::setKd(double Kd){
	this->Kd = Kd;
}
void Regulator_PID::setKi(double Ki){
	this->Ki = Ki;
}
void Regulator_PID::setN(double N){
	this->N = 0;
}

Semnal Regulator_PID::genereaza_comanda(Semnal eroare){
        Interval lim(0.0,255.0);
        Semnal comanda(lim);
        double u;
        double integrator = this->sum_err * Ki;
        if(integrator > 255){
        	integrator = 255;
        }
        if(integrator < 0){
        	integrator = 0;
        }
        u = eroare.getVal() * Kp + integrator + (Kd * eroare.getVal() - filtru) * N;
        this->sum_err += (1*eroare.getVal());

        this->prev_err = eroare.getVal();
        this->filtru += 1*(Kd * eroare.getVal() - filtru);
        comanda.setVal(u);
        return comanda;
}

Semnal Regulator_PID::calculeaza_eroare(Semnal pv, Semnal sp){
	Interval err(-180.0,180.0);
	Semnal eroare(err);
	eroare.setVal(sp.getVal() - pv.getVal());
	return eroare;
}

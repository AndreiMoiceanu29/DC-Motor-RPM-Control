#include "Regulator.hpp"
#include "Semnal.hpp"
#include "Interval.hpp"
#ifndef H_PID
#define H_PID
class Regulator_PID: public Regulator
{
	double sum_err;
	double prev_err;
	double Kp;
	double Ki;
	double Kd;
	double filtru;
	double N;
public:
	Semnal genereaza_comanda(Semnal eroare);
	Semnal calculeaza_eroare(Semnal sp, Semnal pv);
	Regulator_PID();
	Regulator_PID(double Kp, double Kd, double Ki, double N);
	void setKp(double Kp);
	void setKd(double Kd);
	void setKi(double Ki);
	void setN(double N);

	~Regulator_PID();
	
};
#endif
#include "Semnal.hpp"
#include "Interval.hpp"
#ifndef H_REGULATOR
#define H_REGULATOR
class Regulator
{
	virtual Semnal genereaza_comanda(Semnal) = 0;
	virtual Semnal calculeaza_eroare(Semnal, Semnal) = 0;
	
};
#endif
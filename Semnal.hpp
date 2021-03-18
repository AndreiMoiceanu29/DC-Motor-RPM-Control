#include "Interval.hpp"
#ifndef H_SEMNAL
#define H_SEMNAL
class Semnal
{

public:
	Interval gamma;
	double val;

	Semnal(Interval, double);
	Semnal(Interval);
	Semnal();
	~Semnal();
	double getVal();
	void setVal(double);

};
#endif

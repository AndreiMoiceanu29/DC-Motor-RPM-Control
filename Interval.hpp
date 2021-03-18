#ifndef H_INTERVAL
#define H_INTERVAL
class Interval
{
	double min;
	double max;
public:
	Interval(double, double);
	Interval();
	~Interval();
	double getMin();
	double getMax();
	void setMin(double);
	void setMax(double);
	
};
#endif
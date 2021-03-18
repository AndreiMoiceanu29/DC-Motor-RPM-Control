#include "Interval.hpp"

Interval::Interval(double min, double max){
	this->min = min;
	this->max = max;
}

Interval::~Interval(){
	this->min = 0;
	this->max = 0;
}
Interval::Interval(){
	
}

double Interval::getMin(){
	return this->min;
}

double Interval::getMax(){
	return this->max;
}

void Interval::setMin(double min){
	this->min = min;
}
void Interval::setMax(double max){
	this->max = max;
}
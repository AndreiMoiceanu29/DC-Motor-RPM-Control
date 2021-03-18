#include "Semnal.hpp"
//#include "Interval.hpp"

Semnal::Semnal(Interval gamma, double val){
	this->gamma = gamma;
	this->val = val;
}

Semnal::Semnal(Interval gamma){
	this->gamma = gamma;
}

double Semnal::getVal(){
	return this->val;
}

void Semnal::setVal(double val){
	if(val > this->gamma.getMax()){
		this->val = this->gamma.getMax();
	}else if(val < this->gamma.getMin()){
		this->val = this->gamma.getMin();
	}else{
		this->val = val;
	}
}
Semnal::~Semnal(){

}
Semnal::Semnal(){

}

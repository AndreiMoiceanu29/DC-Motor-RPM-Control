#include "Proces.hpp"

Proces::Proces(double initial_sp){

	Interval gamma(0,500.0);

	Semnal sp(gamma);
	this->sp = sp;
	this->sp.setVal(initial_sp);
	Semnal pv(gamma);
	this->pv = pv;
	this->pv.setVal(0);

}
Proces::~Proces(){

}

Semnal Proces::getPv(){
	return this->pv;
}
Semnal Proces::getSp(){
	return this->sp;
}
void Proces::incrementSp(bool sign){
	if(sign == 0){
		this->sp.setVal(this->sp.getVal() + this->val_increment);
	}else{
		this->sp.setVal(this->sp.getVal() - this->val_increment);
	}
}
void Proces::updatePv(double new_pv){
	this->pv.setVal(new_pv);
}

void Proces::setSp(double new_sp){
	this->sp.setVal(new_sp);
}

#include "Semnal.hpp"
#ifndef H_PROCES
#define H_PROCES
class Proces
{
	//volatile bool modOperare; // 0 - Controlul turatiei/1 - Controlul pozitiei.
    Semnal sp;
    Semnal pv;
    double val_increment;
public:
	Proces(double);
	~Proces();
	Semnal getSp();
	Semnal getPv();
	//bool getState();
	//void schimbaStare();
	void incrementSp(bool sign);
	void updatePv(double new_pv);
	void setSp(double new_sp);

};
#endif

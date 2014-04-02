//Klasyfikator.cpp
//Metody klasy Klasyfikator oraz przeciazenia operatorow tej klasy


#include <iostream>
#include "Sample.h"
#include "Klasyfikator.h"



void operator << (std::ostream & _o, Klasyfikator<Sample> & _k){
	_k.Wypisz(_o);
}

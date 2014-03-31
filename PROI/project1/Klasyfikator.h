//PROI
//Autor: Karol Katerzawa
//Projekt 1 - "Leniwy klasyfikator"


//Klasyfikator.h
//Deklaracja klasy Klasyfikator


#ifndef KLASYFIKATOR_H
#define KLASYFIKATOR_H

#include <iostream>
#include <vector>


class Klasyfikator{
	std::vector <Sample> v;		//przechowuje pewna liczbe probek
	//bool PorownajProbki(Sample& ,Sample& ,Sample&);
	void ZamienProbki(int,int); 
	
public:
	Klasyfikator();			//Konstruktor
	~Klasyfikator();		//Destruktor

	//Metody klasy klasyfikator
	void DodajProbki(int);		//WAZNE!!! DO POPRAWY!!!
	Sample& DodajKolejna(double*);
	Sample& WyszukajNajblizsza(Sample &);
	std::ostream & WypiszZawartosc(std::ostream& _o);
	bool Glosowanie(Sample&);

	//przeciazenia operatorow
	Klasyfikator& operator +(Klasyfikator&);
	Klasyfikator& operator +=(Klasyfikator&);
	Klasyfikator& operator =(Klasyfikator&);
	//friend std::ostream& operator <<(std::ostream&,Klasyfikator&);
};

void operator << (std::ostream & _o, Klasyfikator& _k);

#endif //KLASYFIKATOR_H



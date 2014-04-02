//Klasyfikator.h
//Deklaracja klasy Klasyfikator


#ifndef KLASYFIKATOR_H 
#define KLASYFIKATOR_H 


template<class T> class Klasyfikator; 
template<class T> 
void operator << (std::ostream&,Klasyfikator<T> &); 


template<class T>
class Klasyfikator{ 
	T* tablica; 
	int wielkosc; 
	std::ostream & Wypisz(std::ostream &); 
	void Zamien(int,int); 
public:
	//Konstruktory i destruktor
	Klasyfikator():wielkosc(0){ tablica = 0; };
	Klasyfikator(Klasyfikator<T> & );
	~Klasyfikator();

	//Metody klasy Klasyfikator
	T& Dodaj(const T&);
	void Usun(const T&);
	T& ZnajdzNajblizszy(const T&);
	//bool Glosowanie(const Sample&);
	int LiczbaElementow(); 
	T& operator [](int indeks);
	Klasyfikator<T>& operator += (Klasyfikator<T> &);
	Klasyfikator<T>& operator -= (Klasyfikator<T> &);
	Klasyfikator<T>& operator += (const T&);
	Klasyfikator<T>& operator -= (const T&);
	Klasyfikator<T>& operator + (Klasyfikator<T> &);
	Klasyfikator<T>& operator - (Klasyfikator<T> &);
	void friend operator << <>(std::ostream &, Klasyfikator<T> & _k);
};


#include "Klasyfikator_inl.h"

#endif //KLASYFIKATOR_H


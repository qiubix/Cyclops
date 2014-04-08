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
	Klasyfikator():wielkosc(0){ tablica = new T[wielkosc]; };
	Klasyfikator(const Klasyfikator<T> & );
	~Klasyfikator();

	//Metody klasy Klasyfikator
	void push_back(const T&);
	int size();
	bool find(const T&);
	void clear();
	void Usun(const T&);
	T& Dodaj(const T&);
	T& ZnajdzNajblizszy(const T&);
	int LiczbaElementow(); 
	T& operator [](const unsigned int& );
	Klasyfikator<T>& operator = (Klasyfikator<T> &);
	Klasyfikator<T>& operator += (Klasyfikator<T> &);
	Klasyfikator<T>& operator -= (Klasyfikator<T> &);
	Klasyfikator<T>& operator += (const T&);
	Klasyfikator<T>& operator -= (const T&);
	Klasyfikator<T> operator + (const Klasyfikator<T> &);
	Klasyfikator<T> operator - (const Klasyfikator<T> &);
	void friend operator << <>(std::ostream &, Klasyfikator<T> & _k);
};


#include "Klasyfikator_inl.h"

#endif //KLASYFIKATOR_H


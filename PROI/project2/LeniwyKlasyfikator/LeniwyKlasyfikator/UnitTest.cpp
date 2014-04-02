//UnitTest.cpp
//Definicje metod klasy Test
//odpowiadajacej za test modulowy Klasyfikatora


#include <iostream>
#include <sstream>
#include <string>
#include "Sample.h"
#include "Klasyfikator.h"
#include "UnitTest.h"


void Test::inicjalizuj(){
	for(int j=0; j<4; j++){
		double * tab = new double[MAX];
		for(int i=0; i<MAX; i++)
			tab[i] = i + j + 0.5;
		Sample s1(tab,true);
		Sample s2(tab,false);
		k1.Dodaj(s1);
		k1.Dodaj(s2);
		delete []tab;
	}
	//Klasyfikator<Sample> k4 = k1;
	//std::cout << "k1: \n\n" << k1;
	//std::cout << "\n\nk4: \n\n" << k4;
}


void Test::test_dodawania_elem(){
	std::stringstream ss1, ss2;
	ss1 << k1;
	double tab[MAX];
	for(int i=0; i<MAX; i++)
		tab[i] = i + 4.5;
	Sample s1(tab,true);
	k1.Dodaj(s1);
	ss2 << k1;
	ss1 << s1;
	ss1 << "\n";
	if(ss1.str() == ss2.str())
		wynik += "Test dodawania elementu.\n";
	else
		wynik += "Test dodawania elementu zakonczony niepowodzeniem!\n";
}


void Test::test_usuwania_elem(){
	std::stringstream ss1,ss2;
	ss1 << k1;
	double * tab = new double[MAX];
	for(int i=0; i<MAX; i++)
		tab[i] = i + 0.5;
	Sample s1(tab,true);
	delete []tab;
	k1.Usun(s1);
	ss2 << k1;
	if(ss1.str() == ss2.str())
		wynik += "Test odejmowania elementu zakonczony niepowodzeniem!\n";
	else
		wynik += "Test odejmowania elementu.\n";
}



void Test::test_odejmowania_elem(){
	double * tab = new double[MAX];
	for(int i=0; i<MAX; i++)
		tab[i] = i + 1.5;
	Sample s1(tab,true);
	delete []tab;
	k1 -= s1;
	//...
	wynik += "Test odejmowania elementu.\n";
}

void Test::test_znajdowania_najblizszego(){
	double * tab = new double[MAX];
	for(int i=0; i<MAX; i++)
		tab[i] = i + 1.3;
	Sample s1(tab,true);
	delete []tab;
	k1.ZnajdzNajblizszy(s1);
	wynik += "Test znajdowania najblizszego.\n";
}


void Test::test_glosowania(){
	//...
}


void Test::test_dodawania_klasyfikatorow(){
	double * tab = new double[MAX];
	for(int i=0; i<MAX; i++)
		tab[i] = i + 1.5;
	Sample s1(tab,true);
	Sample s2(tab,false);
	delete []tab;
	k2.Dodaj(s1);
	k2.Dodaj(s2);
	k1 += k2;
	wynik += "Test dodawania klasyfikatorow.\n";
}


void Test::test_odejmowania_klasyfikatorow(){
	double * tab = new double[MAX];
	for(int i=0; i<MAX; i++)
		tab[i] = i + 1.5;
	Sample s1(tab,true);
	Sample s2(tab,false);
	delete []tab;
	k3.Dodaj(s1);
	k3.Dodaj(s2);
	k1 -= k3;
	wynik += "Test odejmowania klasyfikarow.\n";
}


void Test::test_operatora_strumienia(){
	std::stringstream ss1;
	ss1 << "0";
	ss1 << k1;
	if(ss1.str() == "0")
		wynik += "Test operatora strumienia zakonczony niepowodzeniem!\n";
	else
		wynik += "Test operatora strumienia.\n";
}


void Test::wypisz_wynik(std::ostream &_o){
	_o << wynik;
	_o << "\n";
}

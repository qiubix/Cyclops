//PROI
//Autor: Karol Katerzawa
//Projekt 1 - "Leniwy klasyfikator"


//main.cpp
//Zawiera testy programu

#include <iostream>
#include <sstream>
#include <string>
#include "Samples.h"
#include "Klasyfikator.h"
using namespace std;

void inicjalizuj();
void test_dolaczania_nowej();
void test_wyszukania_najblizszej();
void test_glosowania();
void test_dodawania();
void test_przypisania_z_dodawaniem();
void test_przypisania();
void test_wypisania();

Klasyfikator k1;
Klasyfikator k2;
Klasyfikator k3;

int main(){
	
	inicjalizuj();
	test_dolaczania_nowej();
	test_wyszukania_najblizszej();
	test_glosowania();
	test_dodawania();
	test_przypisania_z_dodawaniem();
	test_przypisania();
	test_wypisania();
	

	return 0;
}


void inicjalizuj(){
	k1.DodajProbki(10);
	k2.DodajProbki(7);
	k3.DodajProbki(5);
}

void test_dolaczania_nowej(){
	std::stringstream ss1, ss2;
	ss1 << k2;
	double tab[MAX] = {1.6,5.4,10.2,2.4,5.5,2.7,3.1,9.0,21.4,11.3};
	ss2 << k2.DodajKolejna(tab);
	if(ss1.str() == ss2.str())
		cout << "Test dolaczania nowej zakonczono niepowodzeniem!\n";
	else 
		cout << "Test dolaczania nowej probki.\n";
	
}

void test_wyszukania_najblizszej(){
	Sample temp;
	double tab[MAX] = {1.6,5.4,10.2,2.4,5.5,2.7,3.1,9.0,21.4,11.3};
	temp.DodajNowa(tab);
	std::stringstream ss;
	ss << k1.WyszukajNajblizsza(temp);
	cout << "Test wyszukania najblizszej probki do podanego wektora.\n";

}

void test_glosowania(){
	Sample temp;
	double tab[MAX] = {1.6,5.4,10.2,2.4,5.5,2.7,3.1,9.0,21.4,11.3};
	temp.DodajNowa(tab);
	if(k1.Glosowanie(k1.WyszukajNajblizsza(temp)) == k1.WyszukajNajblizsza(temp).PokazKlase())
		cout << "Test glosowania.\n";
	else
		cout << "Test glosowania zakonczony niepowodzeniem.\n";
}

void test_dodawania(){
	std::stringstream ss1, ss2, ss3;
	ss1 << k1;
	ss2 << k3;
	ss3 << k1 + k3;
	if(ss1.str() == ss3.str())
		cout << "Test dodawania klasyfikatorow.\n";
	else
		cout << "Test dodawania klasyfikatorow zakonczono niepowodzeniem!\n";

}

void test_przypisania_z_dodawaniem(){
	std::stringstream ss1, ss2, ss3;
	ss1 << k1;
	ss2 << k3;
	k1 += k3;
	ss3 << k1;
	string line1, line2, line3;
	line3 = ss1.str();
	bool czy_dodac = true;
	while(getline(ss2,line2)){
		while(getline(ss1,line1)){
			if(line1 == line2){
				czy_dodac = false;
				break;
			}
		}
		if(czy_dodac)
			line3 += line2;
	} 
	if(line3 == ss3.str())
		cout << "Test operatora przypisania z dodawaniem.\n";
	else
		cout << "Test operatora przypisania z dodawaniem zakonczony niepowodzeniem!\n";
}

void test_przypisania(){
	std::stringstream ss1;
	ss1 << k1;
	k2 = k1;
	std::stringstream ss2;
	ss2 << k2;
	if(ss1.str() == ss2.str())
		cout << "Test operatora przypisania klasyfikatorow.\n";
	else
		cout << "Test operatora przypisania klasyfikatorow zakonczono niepowodzeniem!!\n";
}

void test_wypisania(){
	std::stringstream ss1;
	ss1 << "0";
	ss1 << k1;
	if(ss1.str() == "0")
		cout << "Test wypisania zakonczony niepowodzeniem!\n";
	else
		cout << "Test wypisania klasyfikatora.\n";
}

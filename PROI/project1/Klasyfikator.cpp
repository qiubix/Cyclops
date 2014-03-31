//PROI
//Autor: Karol Katerzawa
//Projekt 1 - "Leniwy klasyfikator"


//Klasyfikator.cpp
//Zawiera definicje skladowych funkcji klasy Klasyfikator


#include <iostream>
#include <vector>
#include "Samples.h"
#include "Klasyfikator.h"


//Konstruktor klasy Klasyfikator
Klasyfikator::Klasyfikator(){
	//...
}

//Destruktor klasy Klasyfikator
Klasyfikator::~Klasyfikator(){
	//...
}





//Metoda dodajaca probki w liczbie "ile"
//do wektora probek
//Zmienna "base" przechowuje dane o podstawie, z ktorej beda tworzone
//elementy tablicy probki
void Klasyfikator::DodajProbki(int ile){
	for(int i=0;i<ile;i++){
		double tab[MAX] = {0};
		for(int j=0;j<MAX;j++){
			tab[j] = (0.7*i) + (j*0.5);
		}
		Sample tmp;
		tmp.DodajNowa(tab);
		v.push_back(tmp);
	}
}


//Dodaje kolejna probke do klasyfikatora
//Dostaje znacznik do tablicy i liczbe elementow tablicy, 
//przypisuje je do tablicy wektor znajdujacej sie w klasie probka
//a potem dodaje probke do wektora w klasyfikatorze
Sample& Klasyfikator::DodajKolejna(double* tab){
	Sample temp;
	temp.DodajNowa(tab);
	v.push_back(temp);
	return v.back();
}


//Znajduje najblizszy wektor do podanego,
//i jednoczesnie znajduje 3 najblizsze wektory
//ustawiajac je w kolejnosci rosnacej na poczatku kontenera
Sample& Klasyfikator::WyszukajNajblizsza(Sample& x){
	for(int i=0; i<3; i++)
		for(int j=0; j < static_cast<int>(v.size())-1; j++)
			if(x.PorownajProbki(v[i],v[j]))		//probka v[j] jest blizej x niz probka v[i]
				ZamienProbki(i,j);
	return v[0];
}





//Zamienia miejscami 2 probki w kontenerze
void Klasyfikator::ZamienProbki(int a, int b){
	if(a<b){
		Sample temp = v[b];
		v.erase(v.begin()+b);
		v.insert(v.begin()+b,v[a]);
		v.erase(v.begin()+a);
		v.insert(v.begin()+a,temp);
	}
	else{
		Sample temp = v[a];
		v.erase(v.begin()+a);
		v.insert(v.begin()+a,v[b]);
		v.erase(v.begin()+b);
		v.insert(v.begin()+b,temp);
	}
}



//Wypisuje cala zawartosc wektora klasyfikatora
std::ostream & Klasyfikator::WypiszZawartosc(std::ostream & _o){
	if(v.empty())
		_o << "Ten klasyfikator nie posiada zadnej probki!\n";
	for(unsigned int i = 0; i < v.size(); i++){
		_o << v[i];
		_o << "\n";
		}
		//v[i].WypiszProbke(_o);
	_o << "\n\n";
	return _o;
}
		
//Przeprowadza glosowanie, czyli wybiera sposrod
//trzech probek najblizszej do podanej w sensie euklidesowym
//klase bedaca w wiekszosci
bool Klasyfikator::Glosowanie(Sample& x){
	WyszukajNajblizsza(x);
	int co_wypisac = 0;
	for(int i=0; i<3; i++)
		if (v[i].PokazKlase() == true)
			co_wypisac++;
	if(co_wypisac > 1)
		return true;
	else
		return false;
}




//Przeciazenie operatora dodawania klasyfikatorow
Klasyfikator& Klasyfikator::operator +(Klasyfikator & strona){
	bool czy_dodac = true;
	for(int i=0; i < static_cast<int>(strona.v.size()); i++){
		czy_dodac = true;
		for(int j=0; j < static_cast<int>(v.size()); j++)
			if(v[j] == strona.v[i]){
				czy_dodac = false;
				break;
			}
		if(czy_dodac)
			v.push_back(strona.v[i]);
	}
	return *this;
}



//Operator przypisania z dodawaniem. 
//Kazdy z dodawanych wektorow jest najpierw sprawdzany,
//czy juz taki nie istnieje
Klasyfikator& Klasyfikator::operator +=(Klasyfikator &dodawany){
	bool czy_dodac = true;
	for(int i=0; i < static_cast<int>(dodawany.v.size()); i++){
		czy_dodac = true;
		for(int j=0; j < static_cast<int>(v.size()); j++)
			if(dodawany.v[i] == v[j]){
				czy_dodac = false;
				break;
			}
		if(czy_dodac == true)
			v.push_back(dodawany.v[i]);
	}
	return *this;
}


Klasyfikator& Klasyfikator::operator =(Klasyfikator &strona){
	if(v.empty())
		for(int i=0; i < static_cast<int>(strona.v.size()); i++)
			v.push_back(strona.v[i]);
	else{
		v.clear();
		for(int i=0; i < static_cast<int>(strona.v.size()); i++)
			v.push_back(strona.v[i]);
	}
	return *this;
}


void operator << (std::ostream & _o, Klasyfikator & _k){
	_k.WypiszZawartosc(_o);
}

/*
std::ostream& operator <<(std::ostream& out,Klasyfikator& k){
	if(k.v.empty())
		out << "Ten klasyfikator nie posiada zadnej probki!\n";
	for(int i=0; i < static_cast<int>(k.v.size()); i++){
		for(int j=0; j<MAX; j++)
			out << k.v[i].wektor[j] << "\t";
		out << "Klasa probki " << k.v[i].klasa << "\n\n\n";
	}
	return out;
}
*/

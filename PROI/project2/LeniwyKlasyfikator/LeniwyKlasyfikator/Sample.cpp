//Sample.cpp
//Definicje metod klasy Sample oraz przeciazen operatorow


#include <iostream>
#include <cmath>		//sqrt
#include "Sample.h"
 

Sample::Sample(){
	//..
}

//Konstruktor domyslny
Sample::Sample(bool k = false){
	wektor[MAX] = 0;
	klasa = k;
}


//Konstruktor kopiujacy
Sample::Sample(double* tab, bool k = false){
	for(int i=0; i<MAX; i++)
		wektor[i] = tab[i];
	klasa = k;
}

//Zwraca klase probki
bool Sample::PokazKlase(){
	return klasa;
}


//Obliczenie odleglosci wektorow w sensie euklidesowym
//Skorzystanie ze wzoru: d(x,y) = ||x-y|| - norma roznicy wektorow x i y
//d(x,y) = sqrt( (x1-y1)^2 + (x2-y2)^2 + ... + (xn-yn)^2 )
double Sample::OdlegloscWektorow(const Sample & x){
	double sum = 0.0;
	for(int i=0; i<MAX; i++)
		sum += (x.wektor[i] - wektor[i])*(x.wektor[i] - wektor[i]);
	return sqrt(sum);
}


//Wypisanie probki do strumienia
std::ostream & Sample::WypiszProbke(std::ostream &_o){
	for(int i=0; i<MAX; i++)
		_o << wektor[i] << "\t";
	_o << "\nKlasa probki: " << klasa << "\n";
	return _o;
}


//Przeciazenie operatora strumienia dla klasy Sample
void operator << (std::ostream & _o, Sample & _s){
	_s.WypiszProbke(_o);
}


bool operator == (const Sample & lewa, const Sample & prawa){
	bool czy_rowne = true;
	for(int i=0; i<MAX; i++)
		if(lewa.wektor[i]!=prawa.wektor[i]){
			czy_rowne = false;
			break;
		}
	if(czy_rowne)
		if(lewa.klasa == prawa.klasa)
			return true;
		else
			return false;
	else
		return false;
}


double operator -(const Sample & lewa, Sample & prawa){
	return prawa.OdlegloscWektorow(lewa);
}


void Sample::DodajNowa(double *tab, bool k = false){
	for(int i=0; i<MAX; i++)
		wektor[i] = tab[i];
	klasa = k;
}

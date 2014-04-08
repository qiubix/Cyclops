//Sample.cpp
//Definicje metod klasy Sample oraz przeciazen operatorow


#include <iostream>
#include <cmath>		//sqrt

#include "Sample.h"
#include "text_cast.h"



//Konstruktor domyslny
Sample::Sample(){}

Sample::Sample(const Sample & element){
	for(int i=0; i<MAX; i++)
		wektor[i] = element.wektor[i];
}

 
//Konstruktor 
Sample::Sample(double* tab){
	for(int i=0; i<MAX; i++)
		wektor[i] = tab[i];
}


Sample::Sample(const std::vector<std::string> & _input){
	for(int i=0; i<MAX; i++)
		wektor[i] = text_cast<double>(_input[i]);
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
	return _o;
}


//Przeciazenie operatora strumienia dla klasy Sample
void operator << (std::ostream & _o, Sample & _s){
	_s.WypiszProbke(_o); 
}


Sample & Sample::operator =(const Sample & element){
	for(int i=0; i<MAX; i++)
		wektor[i] = element.wektor[i];
	return *this; 
}


bool operator == (const Sample & lewa, const Sample & prawa){
	bool czy_rowne = true;
	for(int i=0; i<MAX; i++)
		if(lewa.wektor[i]!=prawa.wektor[i]){
			czy_rowne = false;
			break;
		}
	if(czy_rowne)
		return true;
	else
		return false;
}


double operator -(const Sample & lewa, Sample & prawa){
	return prawa.OdlegloscWektorow(lewa);
}


void Sample::DodajNowa(double *tab){
	for(int i=0; i<MAX; i++)
		wektor[i] = tab[i];
}

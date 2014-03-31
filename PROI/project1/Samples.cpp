//PROI
//Autor: Karol Katerzawa
//Projekt 1 - "Leniwy klasyfikator"


//Samples.cpp
//Definicje metod klasy Sample
//zdefiniowanej w Samples.h


#include <iostream>
#include <cmath>		//sqrt
#include <cstdlib>
#include <ctime>
#include "Samples.h"



//Konstruktor klasy Sample
Sample::Sample(){
	wektor[MAX] = 0;
	klasa = 0;
}


//Destruktor klasy Sample
Sample::~Sample(){
	//std::cout << "//------------Destruktor klasy Sample. " << this << "\n";
}

//Funkcja skladowa klasy Samples wypelniajaca wektor wewnatrz tej klasy
//danymi z wektora, na ktory przekazywany jest wskaznik
void Sample::DodajNowa(double* tab){
	for(int i=0; i < MAX; i++)
		wektor[i] = tab[i];
	UstawKlase();
}


//Obliczenie odleglosci wektorow w sensie euklidesowym
//Skorzystanie ze wzoru: d(x,y) = ||x-y|| - norma roznicy wektorow x i y
//d(x,y) = sqrt( (x1-y1)^2 + (x2-y2)^2 + ... + (xn-yn)^2 )
double Sample::OdlegloscWektorow(double* x){
	double sum = 0.0;
	for(int i=0;i<MAX;i++)
		sum += (x[i]-wektor[i])*(x[i]-wektor[i]);
	return sqrt(sum);
}


//Sprawdza, ktora z dwoch probek a i b jest blizej probki x
bool Sample::PorownajProbki(Sample& a, Sample& b){
	if(a.OdlegloscWektorow(wektor) > b.OdlegloscWektorow(wektor)) return true;		//wektor z probki b jest blizej wektora x niz wektor z probki a
	return false;
}





//Funkcja skladowa klasy Samples odpowiadajaca za ustawienie klasy probki
void Sample::UstawKlase(){
	srand(static_cast<int>(time(NULL)));
	if(rand()%2)
		klasa = true;
	else
		klasa = false;
}  



//Zwraca klase probki
bool Sample::PokazKlase(){
	return klasa;
} 



//Wypisuje probke oraz jej klase
std::ostream& Sample::WypiszProbke(std::ostream& _o){
	//_o << "Probka numer " << numer << "\n";
	for(int i = 0; i < MAX; i++)
		_o << wektor[i] << "\t";
	//_o << "Klasa probki :" << klasa << "\n\n";
	return _o;
}



//========================================================
//============= Przeciazenia operatorow ==================

//Operator przyrownania (==) dla probek
bool operator ==(Sample& lewy, Sample& prawy){
	bool rowne = true;
	for(int i=0; i < MAX; i++)
		if(lewy.wektor[i] != prawy.wektor[i]){
			rowne = false;
			break;
		}
	if(lewy.klasa != prawy.klasa)
		rowne = false;
	return rowne? true : false;
}


//Operator << dla probek
/*std::ostream& operator <<(std::ostream& out,Sample& probka){
	for(int i=0; i<MAX; i++)
		out << probka.wektor[i] << "\t";
	out << "Klasa probki: " << probka.klasa << "\n\n";
	return out;
}*/


void operator << (std::ostream& _o, Sample& _s){
	_s.WypiszProbke(_o);
}

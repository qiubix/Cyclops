//Klasyfikator-inl.h
//Metody klasy szablonowej Klasyfikator


#ifndef KLASYFIKATOR_INL_H
#define KLASYFIKATOR_INL_H

#include <iostream>
#include <cstdlib>

//Konstruktor kopiujacy
template<class T>
Klasyfikator<T>::Klasyfikator(const Klasyfikator<T> & strona): wielkosc(strona.wielkosc){
	delete []tablica;
	tablica = new T[strona.wielkosc];
	for(int i=0; i<strona.wielkosc; i++)
		tablica[i] = strona.tablica[i];
}



//Destruktor klasyfikatora
template<class T>
Klasyfikator<T>::~Klasyfikator(){
	if(tablica != 0)
		delete []tablica;
}




//Dodanie elementu do zbioru przechowywanego przez Klasyfikator
template<class T>
T& Klasyfikator<T>::Dodaj(const T & element){
	//Sprawdzenie, czy dodawany element nie nalezy juz do klasyfikatora
	bool czy_dodac = true;
	int flaga = -1;
	for(int i=0; i<wielkosc; i++)
		if(tablica[i] == element){
			czy_dodac = false;
			flaga = i;
			break;
		}
	//Jesli w klasyfikatorze nie ma elementu, to dodajemy
	if(czy_dodac){
		int nowa_wielkosc = wielkosc + 1;		//Nowa wielkosc o jeden wieksza
		T* temp = new T[nowa_wielkosc];		//Nowa, wieksza tablica pomocnicza
		for(int i=0; i<wielkosc; i++)			//Kopiujemy dotychczasowa zawartosc
			temp[i] = tablica[i];
		temp[wielkosc] = element;			//Dodajemy element na koniec tablicy

		//Usuwamy niepotrzebna rzeczy i nadajemy nowe wartosci tablicy i rozmiarowi
		delete []tablica;						
		wielkosc = nowa_wielkosc;
		tablica = temp;
		return tablica[0];
	}
	else
		return tablica[flaga];
}




//Dodanie elementu do zbioru przechowywanego przez Klasyfikator
template<class T>
void Klasyfikator<T>::push_back(const T & element){
	//Sprawdzenie, czy dodawany element nie nalezy juz do klasyfikatora
	bool czy_dodac = true;
	for(int i=0; i<wielkosc; i++)
		if(tablica[i] == element){
			czy_dodac = false;
			break;
		}
	//Jesli w klasyfikatorze nie ma elementu, to dodajemy
	if(czy_dodac){
		int nowa_wielkosc = wielkosc + 1;		//Nowa wielkosc o jeden wieksza
		T* temp = new T[nowa_wielkosc];		//Nowa, wieksza tablica pomocnicza
		for(int i=0; i<wielkosc; i++)			//Kopiujemy dotychczasowa zawartosc
			temp[i] = tablica[i];
		temp[wielkosc] = element;			//Dodajemy element na koniec tablicy

		//Usuwamy niepotrzebna rzeczy i nadajemy nowe wartosci tablicy i rozmiarowi
		delete [](tablica);						
		wielkosc = nowa_wielkosc;
		tablica = temp;
	}
}


//Zwraca rozmiar kontenera
template<class T>
int Klasyfikator<T>::size(){
	return wielkosc;
}


//Sprawdzenie, czy element istnieje juz w kontenerze
template<class T>
bool Klasyfikator<T>::find(const T& element){
	for(int i=0; i<wielkosc; i++)
		if(tablica[i] == element)
			return true;
	return false;
}

template<class T>
void Klasyfikator<T>::clear(){
	delete []tablica;
	wielkosc = 0;
	tablica = new T[wielkosc];
}


//Usuniecie okreslonego elementu
template<class T>
void Klasyfikator<T>::Usun(const T & element){
	//Sprawdzenie, czy elemenet, ktory chcemy usunac jest w klasyfikatorze
	int do_usuniecia = -1;
	for(int i=0; i<wielkosc; i++)
		if(tablica[i] == element){
			do_usuniecia = i;
			break;
		}
	if(do_usuniecia >= 0){
		T* temp = new T[wielkosc - 1];
		for(int i=0; i<do_usuniecia; i++)
			temp[i] = tablica[i];
		for(int i=do_usuniecia+1; i<wielkosc; i++)
			temp[i-1] = tablica[i];
		delete []tablica;
		tablica = temp;
		--wielkosc;
	}
}



//Znalezienie w klasyfikatorze najblizszego elementu do podanego
template<class T>
T& Klasyfikator<T>::ZnajdzNajblizszy(const T & x){
	for(int i=0; i<3; i++)
		for(int j=0; j<wielkosc-1; j++){
			if((x-tablica[j]) < (x-tablica[i]))
				Zamien(i,j);
		}
	return tablica[0];
}




//Zamienia miejscami dwa elementy tablicy
template<class T>
void Klasyfikator<T>::Zamien(const int a, const int b){
	T& temp = tablica[a];
	tablica[a] = tablica[b];
	tablica[b] = temp;
}




//Przeciazenie operatora [] dla Klasyfikatora
//Mozliwosc dostepu do elementu tablicy przechowujacej probki przez indeksowanie
template<class T>
T& Klasyfikator<T>::operator [](const unsigned int& indeks){
	if(indeks>=(unsigned)wielkosc){
		std::cerr << "Przekroczenie tablicy!\n";
		exit(0);
	}
	return tablica[indeks];
}



//Zwraca liczbe elementow klasyfikatora
template<class T>
int Klasyfikator<T>::LiczbaElementow(){
	return wielkosc;
}


//Wypisuje do strumienia zawartosc tablicy klasyfikatora
template<class T>
std::ostream & Klasyfikator<T>::Wypisz(std::ostream & _o){
	for(int i=0; i<wielkosc; i++){
		_o << tablica[i];
		_o << "\n";
	}
	return _o;
}


template<class T>
Klasyfikator<T> & Klasyfikator<T>::operator =(Klasyfikator<T> & strona){
	delete []tablica;
	tablica = new T[strona.wielkosc];
	for(int i=0; i<strona.wielkosc; i++)
		tablica[i] = strona.tablica[i];
	wielkosc = strona.wielkosc;
	return *this;
}



//Przeciazenie operatora += pozwalajace na dodawanie do siebie klasyfikatorow
template<class T>
Klasyfikator<T> & Klasyfikator<T>::operator +=(Klasyfikator<T> & strona){
	for(int i=0; i<strona.wielkosc; i++)
		Dodaj(strona[i]);
	return *this;
}


//Przeciazenie operatora -= pozwalajace na odejmowanie od siebie klasyfikatorow
template<class T>
Klasyfikator<T> & Klasyfikator<T>::operator -=(Klasyfikator<T> & strona){
	for(int i=0; i<strona.wielkosc; i++)
		Usun(strona[i]);
	return *this;
}


//Przeciazenie operatora += pozwalajace dodawac nowy element do klasyfikatora
template<class T>
Klasyfikator<T>& Klasyfikator<T>::operator +=(const T & strona){
	Dodaj(strona);
	return *this;
}


//Przeciazenie operatora -= pozwalajace odejmowac element od klasyfikatora
template<class T>
Klasyfikator<T> & Klasyfikator<T>::operator -=(const T & strona){
	Usun(strona);
	return *this;
}


//Przeciazenie operatora + dla klasyfikatorow
template<class T>
Klasyfikator<T> Klasyfikator<T>::operator + (const Klasyfikator<T> & strona){
	Klasyfikator<T> tmp;
	tmp = *this;
	for(int i=0; i<strona.wielkosc; i++)
		tmp += strona.tablica[i];
	return tmp;
}



//Przeciazenie operatora - dla klasyfikatorow
template<class T>
Klasyfikator<T> Klasyfikator<T>::operator - (const Klasyfikator<T> & strona){
	Klasyfikator<T> tmp;
	tmp = *this;
	for(int i=0; i<strona.wielkosc; i++)
		tmp.Usun(strona.tablica[i]);
	return tmp;
}



template<class T>
void operator << (std::ostream & _o, Klasyfikator<T> & _k){
	_k.Wypisz(_o);
}


#endif //KLASYFIKATOR_INL_H

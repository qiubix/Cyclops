//Klasyfikator-inl.h
//Metody klasy szablonowej Klasyfikator


#ifndef KLASYFIKATOR_INL_H
#define KLASYFIKATOR_INL_H



//Konstruktor kopiujacy
template<class T>
Klasyfikator<T>::Klasyfikator(Klasyfikator<T> & strona){
	this->tablica = strona.tablica;
	this->wielkosc = strona.wielkosc;
}



//Destruktor klasyfikatora
template<class T>
Klasyfikator<T>::~Klasyfikator(){
	if(tablica != 0)
		delete [](tablica);
	std::cout << "~Klasyfikator()\n";
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
		T* temp = new T[nowa_wielkosc];			//Nowa, wieksza tablica pomocnicza
		for(int i=0; i<wielkosc; i++)			//Kopiujemy dotychczasowa zawartosc
			temp[i] = tablica[i];
		temp[wielkosc] = element;				//Dodajemy element na koniec tablicy

		//Usuwamy niepotrzebna rzeczy i nadajemy nowe wartosci tablicy i rozmiarowi
		delete [](tablica);
		std::cout << "delete []tablica\n";
		wielkosc = nowa_wielkosc;
		tablica = temp;

		return tablica[wielkosc-1];
	}
	else
		return tablica[flaga];
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



/*
template<>
bool Klasyfikator<Sample>::Glosowanie(const Sample& x){
	this->ZnajdzNajblizszy(x);
	int ile = 0;
	for(int i=0; i<3; i++)
	    if(tablica[i].PokazKlase() == true) ile++;
	if(ile>1)
	    return true;
	else
	    return false;
}
*/



//Przeciazenie operatora [] dla Klasyfikatora
//Mozliwosc dostepu do elementu tablicy przechowujacej probki przez indeksowanie
template<class T>
T& Klasyfikator<T>::operator [](int indeks){
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



//Przeciazenie operatora += pozwalajace na dodawanie do siebie klasyfikatorow
template<class T>
Klasyfikator<T> & Klasyfikator<T>::operator +=(Klasyfikator<T> & strona){
	for(int i=0; i<strona.wielkosc; i++){
		bool czy_dodac = true;
		for(int j=0; j<wielkosc; j++)
			if(tablica[i] == strona.tablica[j]){
				czy_dodac = false;
				break;
			}
		if(czy_dodac)
			Dodaj(strona[i]);
	}
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
	bool czy_dodac = true;
	for(int i=0; i<wielkosc; i++)
		if(tablica[i] == strona){
			czy_dodac = false;
			break;
		}
	if(czy_dodac)
		Dodaj(strona);
	return *this;
}


//Przeciazenie operatora -= pozwalajace odejmowac element od klasyfikatora
template<class T>
Klasyfikator<T> & Klasyfikator<T>::operator -=(const T & strona){
	bool czy_odjac = false;
	for(int i=0; i<wielkosc; i++)
		if(tablica[i] == strona){
			czy_odjac = true;
			break;
		}
	if(czy_odjac)
		Usun(strona);
	return *this;
}


//Przeciazenie operatora + dla klasyfikatorow
template<class T>
Klasyfikator<T> & Klasyfikator<T>::operator + (Klasyfikator<T> & strona){
	for(int i=0; i<strona.wielkosc; i++)
		Dodaj(strona[i]);
	return *this;
}



//Przeciazenie operatora - dla klasyfikatorow
template<class T>
Klasyfikator<T> & Klasyfikator<T>::operator - (Klasyfikator<T> & strona){
	for(int i=0; i<strona.wielkosc; i++)
		Usun(strona[i]);
	return *this;
}



template<class T>
void operator << (std::ostream & _o, Klasyfikator<T> & _k){
	_k.Wypisz(_o);
}


#endif //KLASYFIKATOR_INL_H

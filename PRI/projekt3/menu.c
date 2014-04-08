#include <stdio.h>
#include "funkcje.h"
#include "def.h"


void powitanie();
void menu();
void wczytaj_dane();
void menu_sort();
void zakoncz();




/*komunikat poczatkowy*/
void powitanie()
{
printf("Witaj w bazie danych przedmiotow WEiTI.\n\n");
menu();
}/*======================================= koniec powitanie() */



/*glowne menu, wyswietlane na poczatku, i po kazdym wprowadzeniu danych.*/
void menu()
{
char c=0;
char wybor;
int i=0;

printf("Menu:\n"
"(1) Wprowadz dane.\n"
"(2) Edytuj dane.\n"
"(3) Wypisz dane.\n"
"(4) Sortuj dane.\n"
"(5) Zapisz dane do pliku.\n"
"(6) Zakoncz program.\n");

while(1) {
	i = 0;
	wybor = 0;
	while(c=getchar()) {
		if(i==0){
			if(c>='1'&&c<='6') wybor = c;
			else wybor = 0;
			i++;
		}
		else {
			if(c=='\n'&&i==1&&wybor) 
				switch(wybor) {
				case '1': wczytaj_dane(); break;
				case '2': edytuj(); break;
				case '3': wypisz(); break;
				case '4': menu_sort(); break;
				case '5': zapisz(); break;
				case '6': zakoncz(); break;
				}
			else 
				if(c=='\n') {printf("Niepoprawna komenda! Wybierz jeszcez raz.\n");i=0;}
				else i++;
		}
	}
}/*while(1) */
}/*=================================================koniec menu() */



void wczytaj_dane()
{
char c;
char wybor;
int i;

printf("W jakich sposob chcesz wczytac dane dotyczace kolejnego przedmiotu?\n"
"(1) Wpisz recznie.\n"
"(2) Wczytaj z pliku.\n"
"(3) Powrot do menu glownego.\n\n"
"Uwagi: Przy recznym wpisywaniu danych kod przedmiotu moze skladac sie \n"
"tylko z wielkich liter i cyfr, JD, ECTS i JK musza byc liczbami, \n"
"a klasa przedmiotu to litera A-E.\n\n");

while(1) {
	i = 0;
	wybor = 0;
	while(c=getchar()) {
		if(i==0){
			if(c>='1'&&c<='6') wybor = c;
			else wybor = 0;
			i++;
		}
		else {
			if(c=='\n'&&i==1&&wybor) 
				switch(wybor) {
				case '1': buduj_liste(0); break;
				case '2': buduj_liste(1); break;
				case '3': menu(); break;
				}
			else 
				if(c=='\n') {printf("Niepoprawna komenda! Wybierz jeszcez raz.\n");i=0;}
				else i++;
		}
	}
}/*while(1) */
}



/*Menu pytajace o zadane pole sortowania. Po odpowiednim wyborze odsyla do funkcji sortujacej po wlasciwym kryterium. */
void menu_sort()
{
char c;
char wybor;
int i;


printf("W jaki sposob chcesz posortowac dane?\n"
"(1) Sortuj wedlug nazwy przedmiotu.\n"
"(2) Sortuj wedlug kodu przedmiotu.\n"
"(3) Sortuj wedlug jednostek dydaktycznych.\n"
"(4) Sortuj wedlug ECTS.\n"
"(5) Sortuj wedlug JK.\n"
"(6) Sortuj wedlug prowadzacego.\n"
"(7) Sortuj wedlug klasy przedmiotu.\n"
"(8) Powrot do menu glownego.\n");

while(1) {
	i = 0;
	wybor = 0;
	while(c=getchar()) {
		if(i==0){
			if(c>='1'&&c<='8') wybor = c;
			else wybor = 0;
			i++;
		}
		else {
			if(c=='\n'&&i==1&&wybor) 
				switch(wybor) {
				case '1': sort_nazwa(); break;
				case '2': sort_kod(); break;
				case '3': sort_JD(); break;
				case '4': sort_ECTS(); break;
				case '5': sort_JK(); break;
				case '6': sort_prowadzacy(); break;
				case '7': sort_klasa(); break;
				case '8': menu(); break;
				}
			else 
				if(c=='\n') {printf("Niepoprawna komenda! Wybierz jeszcez raz.\n");i=0;}
				else i++;
		}
	}
}/*while(1) */
}/*==================================koniec menu_sort() */



void zakoncz()
{
char c;
printf("Dziekuje za skorzystanie z programu.\n"
"Aby kontynuowac, nacisnij dowolny klawisz...\n");
c = getchar();
exit(0);
}


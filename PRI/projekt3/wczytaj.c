/*Plik naglowkowy zawierajacy ciala funkcji odpowiedzialnych za wczytywanie danych.*/
#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#include "def.h"



void buduj_liste(int );
int wpisz_przedmiot(przedmiot *);
int odczytaj_przedmiot(przedmiot *, FILE *);
void wczytaj_plik();





struct element{
przedmiot p;
struct element *poprzedni, *nastepny;
};


struct element *poczatek = NULL;
struct element *koniec = NULL;


struct element *wsk, *aktualny, *poprzedni;
przedmiot temp;

int N=0; /*zlicza wprowadzone przedmioty*/






/*Dodaje kolejne elementy listy*/
void buduj_liste(int a)
{
FILE *f;

if(a==0){

while(wpisz_przedmiot(&temp))
{
	wsk = (struct element *) malloc (sizeof(struct element));
	if(wsk==NULL) break;
	wsk->p = temp;
	aktualny = poczatek;
	poprzedni = NULL;
	
	while(aktualny&&aktualny->p.JD<temp.JD)
	{
         poprzedni=aktualny;
         aktualny=aktualny->nastepny;                                       
         }
	
	if(poprzedni==NULL)
	{
		wsk->nastepny=poczatek;
		wsk->poprzedni=NULL;
		if(poczatek!=NULL)poczatek->poprzedni=wsk;
		poczatek=wsk;
	}
	else
	{
		wsk->nastepny=poprzedni->nastepny;
		poprzedni->nastepny=wsk;
		wsk->poprzedni=poprzedni;
	}
	if(aktualny!=NULL) aktualny->poprzedni=wsk;
	
	N++;
}/*while(wpisz_przedmiot....*/

}/*koniec przypadku, gdy a==0, czyli uzytkownik wybral opcje wpisywania przedmiotu recznie*/


else{
wczytaj_plik();
f = fopen("baza.txt","r");

while(odczytaj_przedmiot(&temp,f))
{
	wsk = (struct element *) malloc (sizeof(struct element));
	if(wsk==NULL) break;
	wsk->p = temp;
	aktualny = poczatek;
	poprzedni = NULL;
	
	while(aktualny&&aktualny->p.JD<temp.JD)
	{
         poprzedni=aktualny;
         aktualny=aktualny->nastepny;                                       
         }
	
	if(poprzedni==NULL)
	{
		wsk->nastepny=poczatek;
		wsk->poprzedni=NULL;
		if(poczatek!=NULL)poczatek->poprzedni=wsk;
		poczatek=wsk;
	}
	else
	{
		wsk->nastepny=poprzedni->nastepny;
		poprzedni->nastepny=wsk;
		wsk->poprzedni=poprzedni;
	}
	if(aktualny!=NULL) aktualny->poprzedni=wsk;
	
	N++;
}/*while(wpisz_przedmiot....*/
fclose(f);
}/*else*/

menu();
}/*====================================== koniec buduj_liste() */



/*Funkcja pobiera wskaznik na przedmiot i wypelnia go danymi z klawiatury. 
Zwraca 1 po wypelnieniu wszystkich pol danego przedmiotu, a 0, gdy nie zostal podany zadnen przedmiot.*/
int wpisz_przedmiot(przedmiot *a)
{
    printf("\nPodaj nazwe przedmiotu: ");
    gets(a->nazwa);
    if(a->nazwa[0]=='\0') return 0; /*Jesli uzytkownik nie wpisze zadnej nazwy, tylko od razu [ENTER], to funkcja zwraca 0*/


    printf("Podaj kod przedmiotu: ");
    gets(a->kod);

    printf("Podaj JD przedmiotu: ");
    scanf("%d",&a->JD);

    printf("Podaj ECTS przedmiotu: ");
    scanf("%d",&a->ECTS);

    printf("Podaj JK przedmiotu: ");
    scanf("%d",&a->JK);
    while(getchar()!='\n');

    printf("Podaj prowadzacego przedmiot: ");
    gets(a->prowadzacy);

    printf("Podaj klase przedmiotu: ");
    a->klasa=getchar();
    while(getchar()!='\n');

    printf("Podaj opis przedmiotu: ");
    gets(a->opis);

return 1;
}/*===================================koniec wpisz_przedmiot()*/



/* Funkcja otwiera plik wskazany przez uzytkownika.*/
void wczytaj_plik()
{
printf("Otworzylem plik.\n\n");

}/*==================================koniec wczytaj_plik()*/


/*Funkcja czyta przedmiot z pliku*/
int odczytaj_przedmiot(przedmiot *a, FILE *f)
{
    if(fscanf(f,"%s",a->nazwa)==EOF) return 0;
    /*if(==NULL) return 0;*/
    /*if(a->nazwa[0]=='\n') return 0;*/
    printf("Tu doszedlem\n");
    fscanf(f,"%s",a->kod);
    fscanf(f,"%d",&a->JD);
    fscanf(f,"%d",&a->ECTS);
    fscanf(f,"%d",&a->JK);
    fscanf(f,"%s",a->prowadzacy);
    fscanf(f,"%s",a->klasa);
    fscanf(f,"%s",a->opis);
    
    return 1;
    
}



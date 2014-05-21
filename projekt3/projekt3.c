/*******************Projekt 3.13***********************/
/*Baza danych*/


#include <stdio.h>
#include <stdlib.h>


#define MAX 20
#define MAXLENGTH 20
#define MAX_LENGTH 50


/*=========zmienne globalne i struktury danych=================*/
struct przedmiot {
char nazwa[MAX];
char kod[5];
int JD,ECTS,JK;
char prowadzacy[MAX];
char opis[MAX_LENGTH];
char klasa[2];
};


struct przedmiot zbior[50];/*tablica struktur zawierajaca kolejno wpisywanie przedmioty*/
int N=0; /*zlicza wprowadzone przedmioty*/



struct element{
struct przedmiot p;
struct element *poprzedni, *nastepny;
};


struct element *poczatek = NULL;
struct element *koniec = NULL;


struct element *wsk, *aktualny, *poprzedni;
struct przedmiot temp;



char *n = "Nazwa";
char *kd = "Kod";
char *jd = "JD";
char *ec = "ECTS";
char *jk = "JK";
char *prwdzcy = "PROWADZACY";
char *ops = "OPIS";
char *kls = "KLASA";


/*================prototypy funkcji==========================*/
void powitanie();
void menu();
void wczytaj_dane();
void buduj_liste(int );
int wpisz_przedmiot(struct przedmiot *);
int odczytaj_przedmiot(struct przedmiot *, FILE *);
void wczytaj_plik();
void edytuj();
void edytuj_jeden(struct element *);
void usun();
void usun_jeden(struct element *);
void wypisz();
void menu_sort();
void zapisz();
void zakoncz();
void sort_nazwa();
void sort_kod();
void sort_JD();
void sort_ECTS();
void sort_JK();
void sort_prowadzacy();
void sort_klasa();
void sort_liczby();
void sort_znaki();
void sortuj_liczby();
void sortuj_znaki();
void zamien(struct element * , struct element * );
int porownaj_napisy(char *,char *);


int main()
{
powitanie();

exit(0);
}


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
"(4) Usun rekord.\n"
"(5) Sortuj dane.\n"
"(6) Zapisz dane do pliku.\n"
"(7) Zakoncz program.\n");

while(1) {
	i = 0;
	wybor = 0;
	while(1) {
        c = getchar();
		if(i==0){
			if(c>='1'&&c<='7') wybor = c;
			else wybor = 0;
			i++;
		}
		else {
			if(c=='\n'&&i==1&&wybor) 
				switch(wybor) {
				case '1': wczytaj_dane(); break;
				case '2': edytuj(); break;
				case '3': wypisz(); break;
				case '4': usun(); break;
				case '5': menu_sort(); break;
				case '6': zapisz(); break;
				case '7': zakoncz(); break;
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
	
	wsk->poprzedni = koniec;
	if(koniec != NULL) koniec->nastepny = wsk;
	wsk->nastepny = NULL;
	koniec = wsk;
	if(poczatek == NULL) poczatek = wsk;
	
	
}/*while(wpisz_przedmiot....*/
fclose(f);
}/*else*/

menu();
}/*====================================== koniec buduj_liste() */





/*Funkcja pobiera wskaznik na przedmiot i wypelnia go danymi z klawiatury. 
Zwraca 1 po wypelnieniu wszystkich pol danego przedmiotu, a 0, gdy nie zostal podany zadnen przedmiot.*/
int wpisz_przedmiot(struct przedmiot *a)
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
    gets(a->klasa);
    /*a->klasa=getchar();
    while(getchar()!='\n');*/

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
int odczytaj_przedmiot(struct przedmiot *a, FILE *f)
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


void edytuj()
{
     char klucz[5];
     struct element *skoczek;
     struct element *do_edycji = NULL;
     
     
     printf("Zostala wywolana funkcja edytujaca przedmiot.\n\n");

     printf("Wprowadz kod przedmiotu, ktory chcesz edytowac: ");
     gets(klucz);

     skoczek = poczatek;
     while(skoczek != NULL)
     {
          if(strcmp(klucz,skoczek->p.kod)==0) edytuj_jeden(skoczek);
          skoczek = skoczek->nastepny;
          
     }
     if(do_edycji == NULL)
     {
        printf("Nie zostal odnaleziony przedmiot o takim kodzie.\n");
        menu();
     }


menu();
}/*=================================koniec edytuj() */

void edytuj_jeden(struct element *do_edycji)
{
     char c,wybor;
     int i;
     
     printf("Co chcesz zmienic w tym przedmiocie?\n"
     "1 - wszystko\n"
     "2 - nazwe\n"
     "3 - kod\n"
     "4 - liczbe JD\n"
     "5 - liczbe ECTS\n"
     "6 - liczbe JK\n"
     "7 - prowadzacego\n"
     "8 - klase przedmiotu\n"
     "9 - opis przedmiotu\n"
     "0 - powrot do menu glownego\n");
     
     while(1) {
	 i = 0;
	 wybor = 0;
	       while(c=getchar()) {
                 if(i==0){
			              if(c>='0'&&c<='9') wybor = c;
			              else wybor = 0;
			              i++;
		         }
		         else {
			          if(c=='\n'&&i==1&&wybor) 
                        switch(wybor) {
                              case '1': printf("Podaj nowa nazwe: "); menu();
				              case '2': printf("Podaj nowa nazwe: "); menu();
				              case '3': printf("Podaj nowy kod: "); menu();
				              case '4': printf("Podaj nowa liczbe JD: "); menu();
				              case '5': printf("Podaj nowa liczbe ECTS: "); menu();
				              case '6': printf("Podaj nowa liczbe JK: "); menu();
				              case '7': printf("Podaj nowego prowadzacego: "); menu();
                              case '8': printf("Podaj nowa klase przedmiotu: "); menu();
                              case '9': printf("Podaj nowy opis przedmiotu: "); gets(do_edycji->p.opis); menu();
                              case '0': menu(); break;
				              
				        }
                      else 
				        if(c=='\n') {printf("Niepoprawna komenda! Wybierz jeszcez raz.\n");i=0;}
				        else i++;
		          }
          }
     }/*while(1) */
     
    

menu();     
}

/*Wypisanie bazy danych na ekran i ponowne wyswietlenie menu*/
void wypisz()
{
     struct element *skoczek;
     skoczek = poczatek;
     
     printf("Lista wprowadzonych przedmiotow:\n\n");
     printf("%-20s%-7s%-3s%-5s%-3s%-20s%-6s%-20s\n",n,kd,jd,ec,jk,prwdzcy,kls,ops);
     while(skoczek != NULL)
     {
          fprintf(stdout,"%-20s%-7s%-3d%-5d%-3d%-20s%-6s%-20s\n",
          skoczek->p.nazwa,skoczek->p.kod,skoczek->p.JD,skoczek->p.ECTS,skoczek->p.JK,skoczek->p.prowadzacy,skoczek->p.klasa,skoczek->p.opis);
          skoczek = skoczek-> nastepny;
     }
menu(); 
}/*=================================koniec wypisz() */



/*Menu pytajace o zadane pole sortowania. Po odpowiednim wyborze odsyla do funkcji sortujacej po wlasciwym kryterium. */
void menu_sort()
{
char c;
char wybor;
int i;


printf("\nW jaki sposob chcesz posortowac dane?\n"
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



/*Zapisywanie bazy danych do pliku. Zostaje utworzony badz nadpisany plik dane.txt*/
void zapisz()
{
     FILE *baza;
     struct element *skoczek;
     skoczek = poczatek;
     
     if((baza=fopen("dane2.txt","w"))==NULL){
          printf("Nie moge otworzyc pliku dane.txt do zapisu!\n");
          exit(1);
     }
     fprintf(baza,"%-20s%-7s%-3s%-5s%-3s%-20s%-6s%-20s\n\n",n,kd,jd,ec,jk,prwdzcy,kls,ops);
     while(skoczek != NULL){
          /*fprintf(baza,"Przedmiot numer (%d):\n",N);*/
          fprintf(baza,"%-20s%-7s%3d%5d%3d%-20s%-6s%20s\n",
          skoczek->p.nazwa,skoczek->p.kod,skoczek->p.JD,skoczek->p.ECTS,skoczek->p.JK,skoczek->p.prowadzacy,skoczek->p.klasa,skoczek->p.opis);
          skoczek = skoczek-> nastepny;
     }
     
     
     fclose(baza);
     
printf("Zostala wywolana funkcja zapisujaca liste przedmiotow do pliku.\n\n");


menu();
}/*==================================koniec zapisz() */


void usun()
{
     char klucz[5];
     struct element *skoczek;
     struct element *do_usuniecia = NULL;
     
     
     printf("Zostala wywolana funkcja usuwajaca przedmiot.\n\n");

     printf("Wprowadz kod przedmiotu, ktory chcesz usunac: ");
     gets(klucz);

     skoczek = poczatek;
     while(skoczek != NULL)
     {
          if(strcmp(klucz,skoczek->p.kod)==0) usun_jeden(skoczek);
          skoczek = skoczek->nastepny;
          
     }
     if(do_usuniecia == NULL)
     {
        printf("Nie zostal odnaleziony przedmiot o takim kodzie.\n");
        menu();
     }


menu();
}

void usun_jeden(struct element *to_kill)
{
     struct element *tmp;
     
     if(to_kill->poprzedni != NULL) 
          to_kill->poprzedni->nastepny = to_kill->nastepny;
     else 
          poczatek = to_kill->nastepny;
     
     if(to_kill->nastepny != NULL)
          to_kill->nastepny->poprzedni = to_kill->poprzedni;
     else
          to_kill->poprzedni->nastepny = NULL;
     
     free(to_kill);
     
menu();
}



void zakoncz()
{
char c;
printf("Dziekuje za skorzystanie z programu.\n"
"Aby kontynuowac, nacisnij dowolny klawisz...\n");
c = getchar();
exit(0);
}




void sort_nazwa()
{
     
     sortuj_znaki();
     
     printf("Dane zostaly posortowane wedlug nazwy.\n");
     menu();
}

void sort_kod()
{
     sortuj_znaki();
     
     printf("Dane zostaly posortowane wedlug kodu.\n");
     menu();
}


void sort_JD()
{
     sortuj_liczby();
     
     printf("Dane zostaly posortowane wedlug JD.\n");
     menu();
}


void sort_ECTS()
{
     struct element *skoczek, *skoczek2,*tmp,*aktualny;
     skoczek=poczatek;
     while(skoczek != NULL)
     {
          aktualny = skoczek;
          skoczek2 = skoczek->nastepny;
          if(skoczek2 == NULL) break;
          tmp = skoczek2;
          while(skoczek2 != NULL)
          {
               if(skoczek2->p.ECTS < tmp->p.ECTS) tmp = skoczek2;
               skoczek2 = skoczek2->nastepny;             
          }
          if(aktualny->p.ECTS > tmp->p.ECTS) zamien(aktualny,tmp);
          skoczek = skoczek->nastepny;
     }
     
     
     printf("Dane zostaly posortowane wedlug ECTS.\n");
     menu();
}


void sort_JK()
{
     struct element *skoczek, *skoczek2;
     skoczek = poczatek;
     skoczek = skoczek->nastepny;
     while(skoczek != NULL)
     {
          skoczek2 = skoczek->poprzedni;
          
          while(skoczek2 != NULL && skoczek2->p.JK > skoczek->p.JK){
               zamien(skoczek2,skoczek);
               skoczek2 = skoczek2->poprzedni;
          }
          
          skoczek = skoczek->nastepny;             
     }    
     
     printf("Dane zostaly posortowane wedlug JK.\n");
     menu();
}


void sort_prowadzacy()
{
     sortuj_znaki();
     
     printf("Dane zostaly posortowane wedlug prowadzacego.\n");
     menu();
}


void sort_klasa()
{
     
     printf("Dane zostaly posortowane wedlug klasy.\n");
     menu();
}


void sortuj_liczby()
{
     struct element *skoczek, *skoczek2, *temp;
     skoczek = poczatek->nastepny;
     while(skoczek != NULL)
     {
          skoczek2 = skoczek->poprzedni;
          
          while(skoczek2 != NULL && skoczek2->p.JK > skoczek->p.JK){
               zamien(skoczek2,skoczek);
               skoczek2 = skoczek2->poprzedni;
          }
          
          skoczek = skoczek->nastepny;             
     }    
}

void sortuj_znaki()
{
     return;
}


void zamien(struct element *a, struct element *b)
{
         struct element *tmp;
         
         if(a->poprzedni == NULL && b->nastepny == NULL && a->nastepny == b){                       
                         a->poprzedni = b;
                         a->nastepny = NULL;
                         poczatek = b;
                         poczatek->nastepny = a;
                         printf("opcja 1\n");
         }
         else if(a->poprzedni == NULL && b->nastepny == NULL){
                         tmp = b;
                         a->poprzedni = b->poprzedni;
                         a->nastepny->poprzedni=b;
                         b->poprzedni->nastepny=a;
                         a->nastepny = NULL;
                         poczatek = b;
                         poczatek->nastepny = tmp->poprzedni;
                         printf("opcja 1-1\n");
         }
         else if(a->poprzedni == NULL){
                         tmp = a;
                         a->nastepny = b->nastepny;
                         a->poprzedni = b->poprzedni;
                         b->poprzedni->nastepny = a;
                         b->nastepny->poprzedni = a;
                         poczatek = b;
                         poczatek->nastepny = a->nastepny;
                         tmp->nastepny->poprzedni = b;
                         
                         printf("opcja 2\n");
         }
         else if(b->nastepny == NULL){
                         tmp = a;
                         b->poprzedni->nastepny = a;
                         a->poprzedni = b->poprzedni;
                         a->nastepny = NULL;
                         
                         b->poprzedni = tmp->poprzedni;
                         b->nastepny = tmp->nastepny;
                         tmp->poprzedni->nastepny = b;
                         tmp->nastepny->poprzedni = b;
                         
                         printf("opcja 3\n");
                         return;
         }
         else {
              tmp = a;
              a->nastepny = b->nastepny;
              a->poprzedni = b->poprzedni;
              b->nastepny->poprzedni=a;
              b->poprzedni->nastepny=a;
              b->poprzedni = tmp->poprzedni;
              b->nastepny = tmp->nastepny;
              tmp->poprzedni->nastepny = b;
              tmp->nastepny->poprzedni = b;
              printf("opcja 4\n");
              }
}


int porownaj_napisy(char *a,char *b)
{
    return 0;                       
}

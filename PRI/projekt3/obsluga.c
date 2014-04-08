/*================OBSLUGA========================
Funkcje do edycji rekordow i pojedynczych pol
Funkcje do usuwania rekordow
Funkcje do wypisywania na ekran
Funkcje do zapisu do pliku
*/


#include <stdio.h>
#include "funkcje.h"
#include "def.h"


void edytuj()
{
     char klucz[5];
     int i;
     char wybor, c;
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
                              case '1': edytuj_wszystko(*do_edycji); 
                                        menu();
				              case '2': printf("Podaj nowa nazwe: "); 
                                        gets(do_edycji->p.nazwa); 
                                        menu();
				              case '3': printf("Podaj nowy kod: "); 
                                        gets(do_edycji->p.kod); 
                                        menu();
				              case '4': printf("Podaj nowa liczbe JD: "); 
                                        scanf("%d",&do_edycji->p.JD); 
                                        while(getchar()!='\n'); 
                                        menu();
				              case '5': printf("Podaj nowa liczbe ECTS: "); 
                                        scanf("%d",&do_edycji->p.ECTS); 
                                        while(getchar()!='\n'); 
                                        menu();
				              case '6': printf("Podaj nowa liczbe JK: "); 
                                        scanf("%d",&do_edycji->p.JK); 
                                        while(getchar()!='\n'); 
                                        menu();
				              case '7': printf("Podaj nowego prowadzacego: "); 
                                        gets(do_edycji->p.prowadzacy); 
                                        menu();
                              case '8': printf("Podaj nowa klase przedmiotu: "); 
                                        do_edycji->p.klasa=getchar(); 
                                        while(getchar()!='\n'); 
                                        menu();
                              case '9': printf("Podaj nowy opis przedmiotu: "); 
                                        gets(do_edycji->p.opis); 
                                        menu();
                              case '0': menu(); 
                                        break;
				              
				        }
                      else 
				        if(c=='\n') {printf("Niepoprawna komenda! Wybierz jeszcez raz.\n");i=0;}
				        else i++;
		          }
          }
     }/*while(1) */
     
    

menu();     
}

void edytuj_caly(struct element **do_edycji)
{
     gets(do_edycji->p.nazwa);
     
}



char *n = "Nazwa";
char *kd = "Kod";
char *jd = "JD";
char *ec = "ECTS";
char *jk = "JK";
char *prwdzcy = "PROWADZACY";
char *ops = "OPIS";
char *kls = "KLASA";



/*Wypisanie bazy danych na ekran i ponowne wyswietlenie menu*/
void wypisz()
{
     struct element *skoczek;
     skoczek = poczatek;
     
     printf("Lista wprowadzonych przedmiotow:\n\n");
     printf("%-20s%-7s%-3s%-5s%-3s%-20s%-6s%-20s\n",n,kd,jd,ec,jk,prwdzcy,kls,ops);
     while(skoczek != NULL)
     {
          fprintf(stdout,"%-20s%-7s%-3d%-5d%-3d%-20s%-6c%-20s\n",
          skoczek->p.nazwa,skoczek->p.kod,skoczek->p.JD,skoczek->p.ECTS,skoczek->p.JK,skoczek->p.prowadzacy,skoczek->p.klasa,skoczek->p.opis);
          skoczek = skoczek-> nastepny;
     }
menu(); 
}/*=================================koniec wypisz() */





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
          fprintf(baza,"%-20s%-7s%3d%5d%3d%-20s%-6c%20s\n",
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



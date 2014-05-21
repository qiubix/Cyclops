#include <stdio.h>
#include "funkcje.h"
#include "def.h"
#include "funkcje.h"


void sort_nazwa()
{
     struct element *skoczek, *skoczek2, *temp;
     skoczek = poczatek->nastepny;
     while(skoczek != NULL)
     {
          skoczek2 = skoczek->poprzedni;
          
          while(skoczek2 != NULL && strcmp(skoczek2->p.nazwa,skoczek->p.nazwa)){
               zamien(skoczek2,skoczek);
               skoczek2 = skoczek2->poprzedni;
          }
          
          skoczek = skoczek->nastepny;             
     }    
     
     printf("Dane zostaly posortowane wedlug nazwy.\n");
     menu();
}

void sort_kod()
{
     struct element *skoczek, *skoczek2, *temp;
     skoczek = poczatek->nastepny;
     while(skoczek != NULL)
     {
          skoczek2 = skoczek->poprzedni;
          
          while(skoczek2 != NULL && strcmp(skoczek2->p.kod,skoczek->p.kod)){
               zamien(skoczek2,skoczek);
               skoczek2 = skoczek2->poprzedni;
          }
          
          skoczek = skoczek->nastepny;             
     }    
     
     printf("Dane zostaly posortowane wedlug kodu.\n");
     menu();
}


void sort_JD()
{
     struct element *skoczek, *skoczek2, *temp;
     skoczek = poczatek->nastepny;
     while(skoczek != NULL)
     {
          skoczek2 = skoczek->poprzedni;
          
          while(skoczek2 != NULL && skoczek2->p.JD > skoczek->p.JD){
               zamien(skoczek2,skoczek);
               skoczek2 = skoczek2->poprzedni;
          }
          
          skoczek = skoczek->nastepny;             
     }    
     
     
     printf("Dane zostaly posortowane wedlug JD.\n");
     menu();
}


void sort_ECTS()
{
     sortuj_liczby();
     
     printf("Dane zostaly posortowane wedlug ECTS.\n");
     menu();
}


void sort_JK()
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
     
     printf("Dane zostaly posortowane wedlug JK.\n");
     menu();
}


void sort_prowadzacy()
{
     struct element *skoczek, *skoczek2, *temp;
     skoczek = poczatek->nastepny;
     while(skoczek != NULL)
     {
          skoczek2 = skoczek->poprzedni;
          
          while(skoczek2 != NULL && strcmp(skoczek2->p.prowadzacy,skoczek->p.prowadzacy)){
               zamien(skoczek2,skoczek);
               skoczek2 = skoczek2->poprzedni;
          }
          
          skoczek = skoczek->nastepny;             
     }    
     
     printf("Dane zostaly posortowane wedlug prowadzacego.\n");
     menu();
}


void sort_klasa()
{
     struct element *skoczek, *skoczek2, *temp;
     skoczek = poczatek->nastepny;
     while(skoczek != NULL)
     {
          skoczek2 = skoczek->poprzedni;
          
          while(skoczek2 != NULL && strcmp(skoczek2->p.klasa,skoczek->p.klasa)){
               zamien(skoczek2,skoczek);
               skoczek2 = skoczek2->poprzedni;
          }
          
          skoczek = skoczek->nastepny;             
     }    
     
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



/*
void zamien(struct element *a, struct element *b)
{
         struct element *tmp;
         
         if(a->poprzedni == NULL && b->nastepny == NULL){
                         b->poprzedni = NULL;
                         a->poprzedni = b;
                         b->nastepny = a;
                         a->nastepny = NULL;
         }
         if(a->poprzedni == NULL){
                         tmp = b;
                         b->poprzedni = NULL;
                         a->poprzedni = b;
                         b->nastepny = a;
                         a->nastepny = tmp->nastepny;
         }
         if(b->nastepny == NULL){
                         tmp = a;
                         a->nastepny = NULL;
                         a->poprzedni = b;
                         b->nastepny = a;
                         b->poprzedni = tmp->poprzedni;
         }
         tmp = a;
         a->nastepny = b->nastepny;
         a->poprzedni = b;
         b->nastepny = a;
         b->poprzedni = tmp->poprzedni;
}*/



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



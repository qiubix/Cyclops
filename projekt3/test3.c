#include <stdio.h>

#define MAX 10

/*
int main()
{
    FILE *f;
    char nazwa[MAX];
    if((f = fopen("baza.txt","a+")) == NULL)
    {
          fprintf(stdin,"Nie moge otworzyc pliku baza.\n");
          exit(1);
          }
    
    
    
    system("pause");
    return 0;
    }*/

typedef struct {
char nazwa[MAX];
int JD;
} przedmiot;

przedmiot temp;
int N;

struct element{
przedmiot p;
struct element *poprzedni, *nastepny;
};


struct element *poczatek = NULL;
struct element *wsk, *aktualny, *poprzedni;

char *n = "Nazwa";
char *jd = "JD";

int odczytaj(przedmiot *,FILE *);
void wypisz();

int main()
{
    FILE *f;
    f = fopen("baza.txt","r");
    
    while(odczytaj(&temp,f))
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
}
    fclose(f);
    
    wypisz();
    /*
    struct element *skoczek;
     skoczek = poczatek;
     
     printf("Lista wprowadzonych przedmiotow:\n\n");
     
     while(skoczek != NULL)
     {
          printf("Nazwa: %s\nJD: %d\n\n",
          skoczek->p.nazwa,skoczek->p.JD);
          skoczek = skoczek-> nastepny;
     }
    */

    
    system("pause");
    return 0;
    }
    
    
int odczytaj (przedmiot *a, FILE *f)
{
    if(fgets(a->nazwa,MAX,f)==NULL) return 0;
    fscanf(f,"%d",&a->JD);
    printf("Odczytalem\n");
    
    return 1;
    }

/*Wypisanie bazy danych na ekran i ponowne wyswietlenie menu*/
void wypisz()
{
     struct element *skoczek;
     skoczek = poczatek;
     
     printf("Lista wprowadzonych przedmiotow:\n\n");
     printf("%-20s%-3s\n",n,jd);
     while(skoczek != NULL)
     {
          fprintf(stdout,"%-20s%-3d\n",skoczek->p.nazwa,skoczek->p.JD);
          skoczek = skoczek-> nastepny;
     }

}/*=================================koniec wypisz() */

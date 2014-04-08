#include <stdio.h>

#define MAXLENGTH 20
#define MAX_LENGTH 50

typedef struct {
char nazwa[MAXLENGTH];
char kod[5];
int JD,ECTS,JK;
char prowadzacy[MAXLENGTH];
char opis[MAX_LENGTH];
char klasa;
} przedmiot;

struct element{
przedmiot p;
struct element *poprzedni, *nastepny;
};

struct element *poczatek = NULL;
struct element *koniec = NULL;


int wpisz_przedmiot(przedmiot *);
int porownaj(char znaki1[],char znaki2[]);



void wypisz();

przedmiot temp;


struct element *wsk, *aktualny, *poprzedni;

int main()
{
int n=0;



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
	
	n++;
}

    
    printf("\nZakonczyles wpisywanie. Wpisales %d przedmioty(ow)\n\n",n);
    
    wypisz(poczatek,koniec);

system("pause");    
return 0;    
}



int wpisz_przedmiot(przedmiot *a)
{
int i=0;
char c;  

printf("\nPodaj nazwe przedmiotu: ");
	while(c=getchar())
	{
		if(c=='\n') break;
		else {
		a->nazwa[i]=c;
		i++;
		}
	}
if(i==0) return 0;	

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
}


void wypisz()
{
     FILE *baza;
     struct element *skoczek;
     skoczek = poczatek;
     
     if((baza=fopen("dane.txt","w"))==NULL){
          printf("Nie moge otworzyc pliku dane.txt do zapisu!\n");
          exit(1);
     }
     
     while(skoczek != NULL)
     {
          fprintf(baza,"Nazwa: %s\nKod: %s\nJD: %d\nECTS: %d\nJK: %d\nProwadzacy: %s\nKlasa: %c\nOpis: %s\n\n",
          skoczek->p.nazwa,skoczek->p.kod,skoczek->p.JD,skoczek->p.ECTS,skoczek->p.JK,skoczek->p.prowadzacy,skoczek->p.klasa,skoczek->p.opis);
          skoczek = skoczek-> nastepny;
     }
     fclose(baza);
}


int porownaj(char znaki1[],char znaki2[])
{
    int i;
    for(i=0;i<20;i++)
    {
       if (znaki1[i]<znaki2[i]) return 1;
       if (znaki1[i]>znaki2[i]) break;
    }
    return 0;
}

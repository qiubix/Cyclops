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
przedmiot subject;
struct element *poprzedni, *nastepny;
};

struct element *poczatek = NULL;
struct element *koniec = NULL;


int wpisz_przedmiot(przedmiot *);
int wpisz_nazwa(przedmiot *);
void wpisz_kod();
void wpisz_JD();
void wpisz_ECTS();
void wpisz_JK();
void wpisz_prowadzacy();
void wpisz_klasa();
void wpisz_opis();

void wypisz(struct element *,struct element *);

przedmiot a;
struct element *nowy, *aktualny, *poprzedni;


int main()
{
int n=0;    
przedmiot temp;


while(wpisz_przedmiot(&temp))
{
	nowy = (struct element *) malloc (sizeof(struct element));
	if(!nowy) break;
	nowy->subject = temp;
	aktualny = poczatek;
	poprzedni
	
	n++;
}

    
    printf("\nZakonczyles wpisywanie. Wpisales %d przedmioty(ow)\n\n",n);
    
    wypisz(poczatek,koniec);

system("pause");    
return 0;    
}

int wpisz_przedmiot(przedmiot *a)
{
if(wpisz_nazwa(a)) return 0;
wpisz_kod();
wpisz_JD();
wpisz_ECTS();
wpisz_JK();
wpisz_prowadzacy();
wpisz_klasa();
wpisz_opis();

return 1;
}

int wpisz_nazwa(przedmiot *a)
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
if(i==0) return 1;
else return 0;
}

void wpisz_kod()
{
printf("Podaj kod przedmiotu: ");
gets(a.kod);
}

void wpisz_JD()
{
printf("Podaj JD przedmiotu: ");
scanf("%d",&a.JD);
}

void wpisz_ECTS()
{
printf("Podaj ECTS przedmiotu: ");
scanf("%d",&a.ECTS);
}

void wpisz_JK()
{
printf("Podaj JK przedmiotu: ");
scanf("%d",&a.JK);
while(getchar()!='\n');
}

void wpisz_prowadzacy()
{
printf("Podaj prowadzacego przedmiot: ");
gets(a.prowadzacy);
}

void wpisz_klasa()
{
printf("Podaj klase przedmiotu: ");
a.klasa=getchar();
while(getchar()!='\n');
}

void wpisz_opis()
{
printf("Podaj opis przedmiotu: ");
gets(a.opis);
}

void wypisz(struct element *poczatek, struct element *koniec)
{
     struct element *skoczek;
     skoczek = poczatek;
     
     while(skoczek != NULL)
     {
          printf("Nazwa: %s\nKod: %s\nJD: %d\nECTS: %d\nJK: %d\nProwadzacy: %s\nKlasa: %c\nOpis: %s\n\n",skoczek->subject.nazwa,skoczek->subject.kod,skoczek->subject.JD,skoczek->subject.ECTS,skoczek->subject.JK,skoczek->subject.prowadzacy,skoczek->subject.klasa,skoczek->subject.opis);
          skoczek = skoczek-> nastepny;
     }
}

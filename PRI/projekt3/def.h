#define MAX 20
#define MAXLENGTH 20
#define MAX_LENGTH 50


struct przedmiot {
char nazwa[MAX];
char kod[5];
int JD,ECTS,JK;
char prowadzacy[MAX];
char opis[MAX_LENGTH];
char klasa[2];
};


struct element{
przedmiot p;
struct element *poprzedni, *nastepny;
};


struct element *wsk, *aktualny, *poprzedni;
struct przedmiot temp;


struct element *poczatek = NULL;
struct element *koniec = NULL;


int N=0; /*zlicza wprowadzone przedmioty*/

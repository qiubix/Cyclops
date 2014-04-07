#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_SIZE 13

void rules();
void show_table(int,int);
int deal();
int draw();


int d=0;
int p=0;
int dealer[10]={0,0,0,0,0,0,0,0,0,0};
int player[10]={0,0,0,0,0,0,0,0,0,0};
int a=0;
int random[MAX_SIZE] = {2,3,4,5,6,7,8,9,10,11,12,13,14};


int main()
{
    
    rules();
    printf("Podaj a: ");
    scanf("%d", &a);
    system("cls");
    deal();
    
    
    system("pause");
    
return 0;
    }/*koniec main*/


void rules()
{
printf("==============Zasady==============\n");
printf("1.Gracz i krupier (komputer) dostaja po 2 karty.\n Jedna z kart krupiera jest odkryta.\n");
printf("2.Celem gry jest osiagniecie wiekszej liczby punktow niz przeciwnik, jednak mniejszej niz 21.\n");
printf("3.Gre rozpoczyna gracz, ktory moze dobrac po jednej karcie, az uzna, ze zakonczyl dobieranie.\n");
printf("4.Krupier wykonuje swoja ture i nastepuje porownanie. Zwycieza ten, ktorego wynik \n bedzie blizszy 21, ale nie przekroczy tej liczby.\n");
printf("5.Dwa asy zawsze wygrywaja.\n");
printf("6.W przypadku remisu wygrywa krupier. Przekroczenie 21 punktow oznacza przegrana.\n");
printf("7.Kolory nie maja znaczenia. \n");
printf("8.Punktacja: blotki zgodnie z nominalem, walet 2p, dama 3p, krol 4p, as 11p.\n");
printf("  \n");

}/*=======================================================koniec start() */


void show_table(int d,int p)
{
int a,b;

rules();

printf("Dealer: ");
for(a=0;a<d;a++)
{
	printf("%d ",dealer[a]);
	}
printf(" \n");
printf("Gracz:  ");
for(b=0;b<p;b++)
{
	printf("%d ",player[b]);
	}
printf(" \n");
}/*=======================================================koniec show_table() */


int draw() /*================funkcja losujaca jedna karte*/
{

int i;

srand( time(NULL) );
i=rand()%MAX_SIZE + 1; 
int card = random[i];

return card;
}/*=======================================================koniec draw() */



int deal()
{
d=p=0;
while (d<2)
{
	dealer[d]=draw();
	d++;
	player[p]=draw();
	p++;
	}
show_table(d,p);
	
return 0;
}/*=======================================================koniec deal() */

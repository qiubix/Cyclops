/*Projekt 2.13 - Gra w "oczko"*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_SIZE 13



/*========================================================= deklaracje funkcji*/
void rules();
void start();
int draw();
void deal();
void show_table(int,int);
void gameplay();
int showdown();
int menu();
int winner();


/*=========================================================deklaracje zmiennych*/
int d=0;
int p=0;
int dealer[10]={0,0,0,0,0,0,0,0,0,0};
int player[10]={0,0,0,0,0,0,0,0,0,0};
char cards[MAX_SIZE] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
int check[MAX_SIZE] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
int dealer_sum;
int player_sum;




/*========================================================= main() */
int main()
{
    printf("Witam w programie do gry w oczko.\n\n");
    start();
    while(menu());


return 0;
}/*========================================================koniec main*/


void rules()
{
printf("==============Zasady==============\n");
printf("1.Gracz i krupier (komputer) dostaja po 2 karty.\n Jedna z kart krupiera jest odkryta.\n");
printf("2.Celem gry jest osiagniecie wiekszej liczby punktow niz przeciwnik, \njednak mniejszej niz 21.\n");
printf("3.Gre rozpoczyna gracz, ktory moze dobrac po jednej karcie, \naz uzna, ze zakonczyl dobieranie.\n");
printf("4.Krupier wykonuje swoja ture i nastepuje porownanie. \nZwycieza gracz, wynik blizszy 21, ale nie przekroczy tej liczby.\n");
printf("5.Dwa asy zawsze wygrywaja.\n");
printf("6.W przypadku remisu wygrywa krupier.\n");
printf("7.Kolory nie maja znaczenia. \n");
printf("8.Punktacja: blotki zgodnie z nominalem, walet 2p, dama 3p, krol 4p, as 11p.\n");
printf("  \n");

}/*=======================================================koniec rules() */

void start()
{
char a;
char choice=0; 
int i=0;    
  
rules();   
printf("Aby rozpoczac losowanie, wpisz 1: ");

while(a=getchar())
     {
                     if(i==0)
                          {
                                  if(a=='1') choice = a;
                                  else choice = 0;
                                  i++;}
                          else
                          {
                                  if(choice&&i==1&&a=='\n')
                                        deal();
                                  else
                                      if (a=='\n') {printf("Niewlasciwa komenda!\n");i=0;}
                                      else i++;
                                  
                          }/*else*/
     if(choice=='1'&&a=='\n'&&i==1) break;
     }

}/*=======================================================koniec start()*/


void show_table(int d,int p)
{
int a,b;


printf("\nDealer:");
                  for(a=0;a<d;a++) printf(" X");/*printf(" %c",dealer[a]);*/
                  printf(" \n");
printf("Gracz: ");
                  for(b=0;b<p;b++) printf(" %c",player[b]);
                  printf(" \n");
}/*=======================================================koniec show_table() */



int draw() /*================funkcja losujaca jedna karte*/
{
int card = 0;
int random = rand()%MAX_SIZE;
/*if(check[random]==4) draw();
else 
     {
     check[random]++;
     card = cards[random];                
     }*/
     card = cards[random];
return card;
}/*=======================================================koniec draw() */




/*=========================DEAL===============================
funkcja odpowiedzialna za rozdanie kart, a nastepnie wyswietlenie ich na stole*/

void deal()
{
d=p=0;
player_sum=0;
dealer_sum=0;
srand((unsigned)(time(0)));
while (d<2)
{
	dealer[d]=draw();
	switch(dealer[d])
	{
                     case '2': dealer_sum+=2;break;
                     case '3': dealer_sum+=3;break;
                     case '4': dealer_sum+=4;break;
                     case '5': dealer_sum+=5;break;
                     case '6': dealer_sum+=6;break;
                     case '7': dealer_sum+=7;break;
                     case '8': dealer_sum+=8;break;
                     case '9': dealer_sum+=9;break;
                     case 'T': dealer_sum+=10;break;
                     case 'J': dealer_sum+=2;break;
                     case 'Q': dealer_sum+=3;break;
                     case 'K': dealer_sum+=4;break;
                     case 'A': dealer_sum+=11;break;
                     }
	d++;
	player[p]=draw();
	switch(player[p])
	{
                     case '2': player_sum+=2;break;
                     case '3': player_sum+=3;break;
                     case '4': player_sum+=4;break;
                     case '5': player_sum+=5;break;
                     case '6': player_sum+=6;break;
                     case '7': player_sum+=7;break;
                     case '8': player_sum+=8;break;
                     case '9': player_sum+=9;break;
                     case 'T': player_sum+=10;break;
                     case 'J': player_sum+=2;break;
                     case 'Q': player_sum+=3;break;
                     case 'K': player_sum+=4;break;
                     case 'A': player_sum+=11;break;
                     }
	p++;
	}
show_table(d,p);
gameplay();	
}/*=======================================================koniec deal() */


int take()
{
/*tu trzeba sprawdzic, czy karta nie powtarza sie juz 4 razy, i ewentualnie wylosowac jeszcze raz. */
player[p]=draw();
switch(player[p])
	{
                     case '2': player_sum+=2;break;
                     case '3': player_sum+=3;break;
                     case '4': player_sum+=4;break;
                     case '5': player_sum+=5;break;
                     case '6': player_sum+=6;break;
                     case '7': player_sum+=7;break;
                     case '8': player_sum+=8;break;
                     case '9': player_sum+=9;break;
                     case 'T': player_sum+=10;break;
                     case 'J': player_sum+=2;break;
                     case 'Q': player_sum+=3;break;
                     case 'K': player_sum+=4;break;
                     case 'A': player_sum+=11;break;
                     }
p++;
return 0;
}/*=======================================================koniec take() */

/*======================GAMEPLAY=============================
gracz rozpoczyna gre. Moze dobierac karty, lub zakonczyc i oddac ture krupierowi*/

void gameplay()
{
     int i=0;
     char c=0;
     char choice=0;
     
     printf("\nWpisz T aby dobrac karte.\n");
     printf("Wpisz Q aby zakonczyc.\n");
     
     while(c=getchar())
     {
                     if(i==0)
                          {
                                  if(c=='T'||c=='t'||c=='Q'||c=='q') choice = c;
                                  else choice = 0;
                                  i++;}
                          else
                          {
                                  if(choice&&i==1&&c=='\n')
                                        switch(choice)
                                        {
                                                case 't': {
                                                     take();
                                                     show_table(d,p); 
                                                     printf("\nWpisz T aby dobrac karte.\n");
                                                     printf("Wpisz Q aby zakonczyc.\n");
                                                     i=0;
                                                     break;}
                                                case 'T': {
                                                     take();
                                                     show_table(d,p); 
                                                     printf("\nWpisz T aby dobrac karte.\n");
                                                     printf("Wpisz Q aby zakonczyc.\n");
                                                     i=0;
                                                     break;}
                                                case 'q': break;
                                                case 'Q': break;
                                        }/*switch*/
                                  else
                                      if (c=='\n') {printf("Niewlasciwa komenda! Mozesz dobrac karte (T) lub zakonczyc ture (Q)\n");i=0;}
                                      else i++;
                                  
                          }/*else*/
                          if((choice=='Q'||choice=='q')&&c=='\n'&&i==1) {/*show_table(d,p);*/break;}
     }
winner();     
}/*========================================================koniec gameplay()*/


/*=====================SHOWDOWN============================
rozegranie tury krupiera i wyswietlenie wyniku*/
int showdown()
{
if (player_sum>22) return 0;
else{
    if(player_sum==22&&p==2) return 1;
    else
    {
        if(dealer_sum==22) return 0;
        else{
            while(dealer_sum<16)
            {
                            if(dealer_sum>=player_sum||dealer_sum>21) break;
                            dealer[d]=draw();
                            switch(dealer[d]){
                                        case '2': dealer_sum+=2;break;
                                        case '3': dealer_sum+=3;break;
                                        case '4': dealer_sum+=4;break;
                                        case '5': dealer_sum+=5;break;
                                        case '6': dealer_sum+=6;break;
                                        case '7': dealer_sum+=7;break;
                                        case '8': dealer_sum+=8;break;
                                        case '9': dealer_sum+=9;break;
                                        case 'T': dealer_sum+=10;break;
                                        case 'J': dealer_sum+=2;break;
                                        case 'Q': dealer_sum+=3;break;
                                        case 'K': dealer_sum+=4;break;
                                        case 'A': dealer_sum+=11;break;
                                        }/*switch*/
                            d++;
            }
        if(player_sum>dealer_sum) return 1;
        else {
             if(player_sum<22&&dealer_sum>21) return 1;
             else return 0;}
             }
    }
}
    
    
}/*=================================================== koniec showdown()*/

int winner()
{
int a,b;

showdown();
printf("\nDealer: ");
                  for(a=0;a<d;a++) printf("%c ",dealer[a]);
                  printf(" \n");
printf("Gracz: ");
                  for(b=0;b<p;b++) printf(" %c",player[b]);
                  printf(" \n");

if(showdown())
    {
                  printf("\nGratulacje! Wygrales! Masz %d p., a komputer %d p.\n\n",player_sum,dealer_sum);
                  return 1;
                  }
    else
    {
                  if(player_sum>22) printf ("\nNiestety, przegrales. Przekroczyles liczbe 21!\n\n");
                  else printf("\nNiestety, przegrales. Komputer ma %d p., a Ty masz %d p.\n\n",dealer_sum, player_sum);
                  return 0;
                  }



}/*=================================================== koniec winner()*/



int menu()
{     
char a;
char choice=0; 
int i=0;    

printf("(1) Zagraj jeszcze raz.\n(2) Wyjdz z programu.\n\n");

while(a=getchar())
     {
                     if(i==0)
                          {
                                  if(a=='1'||a=='2') choice = a;
                                  else choice = 0;
                                  i++;}
                          else
                          {
                                  if(choice&&i==1&&a=='\n')
                                        {
                                                           switch(choice)
                                                           {
                                                                         case '1': deal();break;
                                                                         case '2': printf("Dziekuje za wspolna gre!\n\n");return 0;break;
                                                                         }
                                                           }
                                  else
                                      if (a=='\n') {printf("Niewlasciwa komenda!\n");i=0;}
                                      else i++;
                                  
                          }/*else*/
     if(choice=='1'&&a=='\n'&&i==1) break;
     }

}

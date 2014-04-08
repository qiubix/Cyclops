void addBegin(struct element **head,struct element **tail, przedmiot subject) 
void addEnd(struct element **head,struct element **tail, przedmiot subject) 
void addMiddle(struct element **head, struct element **tail, przedmiot subject, int pos)









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
     struct element *skoczek, *skoczek2,*najmniejszy,*aktualny;
     skoczek=poczatek;
     while(skoczek != NULL)
     {
          aktualny = skoczek;
          skoczek2 = skoczek->nastepny;
          if(skoczek2 == NULL) break;
          tmp = skoczek2;
          while(skoczek2 != NULL)
          {
               if(skoczek2->p.ECTS < tmp->p.ECTS) najmniejszy = skoczek2;
               skoczek2 = skoczek2->nastepny;             
          }
          if(aktualny->p.ECTS > tmp->p.ECTS) zamien(aktualny,najmniejszy);
          skoczek = skoczek->nastepny;
     }
     
     printf("Dane zostaly posortowane wedlug ECTS.\n");
     menu();
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








/**********************************************************************************************************************************/

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
int wpisz_nazwa(przedmiot *);
void wpisz_kod(przedmiot *);
void wpisz_JD(przedmiot *);
void wpisz_ECTS();
void wpisz_JK();
void wpisz_prowadzacy();
void wpisz_klasa();
void wpisz_opis();

void wypisz();



struct element *wsk, *aktualny, *poprzedni;

int main()
{
int n=0;
przedmiot temp;


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


przedmiot a;

int wpisz_przedmiot(przedmiot *a)
{
if(wpisz_nazwa(a)) return 0;
wpisz_kod(a);
wpisz_JD(a);
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

/*	while(c=getchar())
	{
		if(c=='\n') break;
		else {
		a->nazwa[i]=c;
		i++;
		}
	}
if(i==0) return 0;	*/


void wpisz_kod(przedmiot *a)
{
printf("Podaj kod przedmiotu: ");
gets(a->kod);
}

void wpisz_JD(przedmiot *a)
{
printf("Podaj JD przedmiotu: ");
scanf("%d",&a->JD);
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

void wypisz()
{
     struct element *skoczek;
     skoczek = poczatek;
     
     while(skoczek != NULL)
     {
          printf("Nazwa: %s\nKod: %s\nJD: %d\nECTS: %d\nJK: %d\nProwadzacy: %s\nKlasa: %c\nOpis: %s\n\n",
          skoczek->p.nazwa,skoczek->p.kod,skoczek->p.JD,skoczek->p.ECTS,skoczek->p.JK,skoczek->p.prowadzacy,skoczek->p.klasa,skoczek->p.opis);
          skoczek = skoczek-> nastepny;
     }
}








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












/************************************************************************************************************************/

"Nazwa: %s\nKod: %s\nJD: %d\nECTS: %d\nJK: %d\nProwadzacy: %s\nKlasa: %c\nOpis: %s\n\n",

printf("%-20s%-7s%-4s%-5s%-4s%-20s%-6s%-5s\n",n,kd,jd,ec,jk,prwdzcy,kls,ops);



         if(a->poprzedni == NULL)
         {
            b->poprzedni = NULL;
            b->nastepny = a;
         }
         
         
         a->nastepny = b->nastepny;
         a->poprzedni->nastepny = b;
         b->poprzedni = a->poprzedni;
         b->nastepny->poprzedni = a;
         a->poprzedni = b;
         b->nastepny = a;
         
         
		 

/*Funkcja czyta przedmiot z pliku*/
int odczytaj_przedmiot(przedmiot *a, FILE *f)
{
    if(fscanf(f,"%s",a->nazwa) == 0) return 0;
    /*if(a->nazwa[0]==" ") return 0;*/
    fgets(a->kod,MAX,f);
    fscanf(f,"%d",&a->JD);
    fscanf(f,"%d",&a->ECTS);
    fscanf(f,"%d",&a->JK);
    fgets(a->prowadzacy,MAX,f);
    fgets(a->klasa,2,f);
    fgets(a->opis,MAX,f);
    
    return 1;
    
}



/*Funkcja czyta przedmiot z pliku*/
int odczytaj_przedmiot(przedmiot *a, FILE *f)
{
    if(fgets(a->nazwa,MAX + 1,f)==NULL) return 0;
    /*if(a->nazwa[0]=='\0') return 0;*/
    printf("Tu doszedlem\n");
    fgets(a->kod,MAX + 1,f);
    fscanf(f,"%d",&a->JD);
    fscanf(f,"%d",&a->ECTS);
    fscanf(f,"%d",&a->JK);
    fgets(a->prowadzacy,MAX + 1,f);
    a->klasa = getc(f);
    fgets(a->opis,MAX + 1,f);
    
    return 1;
    
}


/*Funkcja czyta przedmiot z pliku*/
int odczytaj_przedmiot(przedmiot *a, FILE *f)
{
    if(fscanf(f,"%s",a->nazwa) == 0) return 0;
    /*if(a->nazwa[0]==" ") return 0;*/
    fgets(a->kod,MAX,f);
    fscanf(f,"%d",&a->JD);
    fscanf(f,"%d",&a->ECTS);
    fscanf(f,"%d",&a->JK);
    fgets(a->prowadzacy,MAX,f);
    fgets(a->klasa,2,f);
    fgets(a->opis,MAX,f);
    
    return 1;
    
}

/*Funkcja czyta przedmiot z pliku*/
/*int odczytaj_przedmiot(przedmiot *a, FILE *f)
{
    if(fgets(a->nazwa,MAX,f)==NULL) return 0;
    /*if(a->nazwa[0]=='\0') return 0;*//*
    printf("Tu doszedlem\n");
    fscanf(f,"%s",&a->kod);
    fscanf(f,"%d",&a->JD);
    fscanf(f,"%d",&a->ECTS);
    fscanf(f,"%d",&a->JK);
    fscanf(f,"%s",&a->prowadzacy);
    fscanf(f,"%c",&a->klasa);
    fscanf(f,"%s",a->opis);
    
    return 1;
    
}*/





void zamien(struct element *a, struct element *b)
{
	struct element *tmp;
	
	if(a->poprzedni == NULL){
		if(b->nastepny==NULL){
			if(a->nastepny == b){
				a->nastepny = NULL;
				a->poprzedni = b;
				b->nastepny = a;
				b->poprzedni = NULL;
				poczatek = b;
				printf("opcja 1-1\n");
			}
			else{
				b->poprzedni->nastepny = a;
				tmp = a->nastepny;
				a->nastepny = NULL;
				a->poprzedni = b->poprzedni;
				b->nastepny = tmp;
				b->poprzedni = NULL;
				poczatek = b;
				printf("opcja 1-2\n");
			}
		}
		else{
			b->poprzedni->nastepny = a;
			b->nastepny->poprzedni = a;
			tmp = a->nastepny;
			a->nastepny = b->nastepny;
			a->poprzedni = b->poprzedni;
			b->nastepny = tmp;
			b->poprzedni = NULL;
			poczatek = b;
			printf("opcja 2\n");
		}
	}
	else{
		if(b->nastepny==NULL){
			a->poprzedni->nastepny = b;
			a->nastepny->poprzedni = b;
			tmp = b->poprzedni;
			b->poprzedni = a->poprzedni;
			b->nastepny = a->nastepny;
			a->poprzedni = tmp;
			a->nastepny = NULL;
			printf("opcja 3\n");
		}
		else{
			a->poprzedni->nastepny=b;
            a->nastepny->poprzedni=b;
            b->poprzedni->nastepny=a;
            b->nastepny->poprzedni=a;
            tmp=a->poprzedni;
            a->poprzedni=b->poprzedni;
            b->poprzedni=tmp;
            tmp=a->nastepny;
            a->nastepny=b->nastepny;
            b->nastepny=tmp;
			printf("opcja 4\n");
		}
	}
}






void zamien(struct element *a, struct element *b)
{
	struct element *tmp;
	
	if(a->nastepny == b){
		b->nastepny = a;
		a->nastepny = b->nastepny;
		a->poprzedni = b->poprzedni;
	}
	else{
		if(a->poprzedni == NULL){
			if(b->nastepny==NULL){
				b->poprzedni->nastepny = a;
				tmp = a->nastepny;
				a->nastepny = NULL;
				a->poprzedni = b->poprzedni;
				b->nastepny = tmp;
				b->poprzedni = NULL;
				poczatek = b;
				printf("opcja 1-2\n");
			
			}
			else{
				b->poprzedni->nastepny = a;
				b->nastepny->poprzedni = a;
				tmp = a->nastepny;
				a->nastepny = b->nastepny;
				a->poprzedni = b->poprzedni;
				b->nastepny = tmp;
				b->poprzedni = NULL;
				poczatek = b;
				printf("opcja 2\n");
			}
		}
		else{
			if(b->nastepny==NULL){
				a->poprzedni->nastepny = b;
				a->nastepny->poprzedni = b;
				tmp = b->poprzedni;
				b->poprzedni = a->poprzedni;
				b->nastepny = a->nastepny;
				a->poprzedni = tmp;
				a->nastepny = NULL;
				printf("opcja 3\n");
			}
			else{
				a->poprzedni->nastepny=b;
				a->nastepny->poprzedni=b;
				b->poprzedni->nastepny=a;
				b->nastepny->poprzedni=a;
				tmp=a->poprzedni;
				a->poprzedni=b->poprzedni;
				b->poprzedni=tmp;
				tmp=a->nastepny;
				a->nastepny=b->nastepny;
				b->nastepny=tmp;
				printf("opcja 4\n");
			}
		}
	}

}

void sort_JK(){
	
	struct element *aktualny, *najmniejszy, *skoczek, *skoczek2, *poczatek2;
	
	poczatek2 = NULL;
	skoczek = poczatek;
	
	while(skoczek !=NULL){
		najmniejszy=skoczek;
		skoczek=skoczek->nastepny;
	}
}







void sort_JK()
{
     struct element *skoczek, *skoczek2,*najmniejszy,*aktualny;
     skoczek=poczatek;
     
     najmniejszy = skoczek;
     while(skoczek != NULL)
     {
          if(skoczek->p.JK < najmniejszy->p.JK) najmniejszy = skoczek;
          skoczek = skoczek->nastepny;             
     }
     poczatek2 = najmniejszy;
     poczatek2->poprzedni = NULL;
     tmp = skoczek->nastepny;
     skoczek->poprzedni->nastepny = skoczek->nastepny;
     tmp->poprzedni = skoczek->poprzedni;
     
     skoczek = poczatek;
     while(skoczek != NULL)
     {
          najmniejszy = skoczek;             
     }
     
     
     
     
     skoczek = poczatek;
     while(skoczek != NULL)
     {
          aktualny = skoczek;
          skoczek2 = skoczek->nastepny;
          
          if(skoczek2 == NULL) break;
          najmniejszy = skoczek2;
          while(skoczek2 != NULL)
          {
               if(skoczek2->p.JK < najmniejszy->p.JK) najmniejszy = skoczek2;
               skoczek2 = skoczek2->nastepny;             
          }
          if(aktualny->p.JK > najmniejszy->p.JK) 
          
          skoczek = skoczek->nastepny;
     }
        
     
     printf("Dane zostaly posortowane wedlug JK.\n");
     menu();
}



void sort_JK()
{
	struct element *skoczek, *skoczek2, *aktualny;
	
	skoczek = poczatek->nastepny;
	while(skoczek!=NULL){
		aktualny = skoczek;
		skoczek2 = skoczek->poprzedni;
		while((skoczek2->p.JD > aktualny->p.JD)&&skoczek2 != NULL) skoczek2=skoczek2->poprzedni;
		aktualny->poprzedni->nastepny = aktualny->nastepny;
		aktualny->nastepny->poprzedni = aktualny->poprzedni;
		aktualny->poprzedni = skoczek2->poprzedni;
		aktualny->nastepny = skoczek2;
		skoczek2->poprzedni->nastepny = aktualny;
		skoczek2->poprzedni = aktualny;
		
		skoczek = skoczek->nastepny;
	}
}


void wstaw_przed(struct element *a, struct element *b)
{
	struct element *tmp;
	
	if(a->nastepny == b){
		if(a->poprzedni == NULL){
			if(b->nastepny == NULL){
				a->nastepny = NULL;
				a->poprzedni = b;
				b->nastepny = a;
				b->poprzedni = NULL;
				poczatek = b;
			}
			else{
				b->nastepny->poprzedni = a;
				b->poprzedni = NULL;
				a->nastepny = b->nastepny;
				b->nastepny = a;
				a->poprzedni = b;
				poczatek = b;
			}
		}
		else{
			if(b->nastepny == NULL){
				a->nastepny = NULL;
				a->poprzedni->nastepny = b;
				b->poprzedni = a->poprzedni;
				b->nastepny = a;
				a->poprzedni = b;
			}
			else{
				b->nastepny->poprzedni = a;
				a->poprzedni->nastepny = b;
				tmp = a->poprzedni;
				a->poprzedni = b;
				a->nastepny = b->nastepny;
				b->poprzedni = tmp;
				b->nastepny = a;
			}
		}
	}
	else{
		if(a->poprzedni == NULL){
			if(b->nastepny == NULL){
				b->poprzedni->nastepny = NULL;
				b->nastepny = a;
				b->poprzedni = NULL;
				a->poprzedni = b;
				poczatek = b;
			}
			else{
				b->poprzedni->nastepny = b->nastepny;
				b->nastepny->poprzedni = b->poprzedni;
				b->nastepny = a;
				b->poprzedni = NULL;
				a->poprzedni = b;
				poczatek = b;
			}
		}
		else{
			if(b->nastepny == NULL){
				b->poprzedni->nastepny = NULL;
				tmp = a->poprzedni;
				a->poprzedni->nastepny = b;
				b->nastepny = a;
				b->poprzedni = tmp;
				a->poprzedni = b;
			}
			else{
				b->poprzedni->nastepny = b->nastepny;
				b->nastepny->poprzedni = b->poprzedni;
				tmp = a->poprzedni;
				a->poprzedni->nastepny = b;
				a->poprzedni = b;
				b->nastepny = a;
				b->poprzedni = tmp;
			}
		}
	}
}




void sort_ECTS()
{
     struct element *skoczek, *skoczek2,*najmniejszy,*aktualny;
     skoczek=poczatek;
     while(skoczek != NULL)
     {
          aktualny = skoczek;
          skoczek2 = skoczek->nastepny;
          skoczek = skoczek->nastepny;
          if(skoczek2 == NULL) break;
          najmniejszy = skoczek2;
          while(skoczek2 != NULL)
          {
               if(skoczek2->p.ECTS < najmniejszy->p.ECTS) najmniejszy = skoczek2;
               skoczek2 = skoczek2->nastepny;
               printf("skoczek2 - %d",skoczek2);
               getchar();
               printf("==== obieg ====\n");
          }
          if(aktualny->p.ECTS > najmniejszy->p.ECTS) zamien(aktualny,najmniejszy);
          
          printf("Skoczek - %d\n",skoczek);
          getchar(); 
     }
     
     
     printf("Dane zostaly posortowane wedlug ECTS.\n");
     menu();
}







void usun_jeden(struct element *do_usuniecia)
{
     struct element *tmp;
     
     if(do_usuniecia->poprzedni == NULL && do_usuniecia->nastepny == NULL) do_usuniecia->nastepny == NULL;
     else if(do_usuniecia->nastepny==NULL) do_usuniecia->poprzedni->nastepny = NULL;
     else if(do_usuniecia->poprzedni == NULL) do_usuniecia->nastepny->poprzedni = NULL;
     else {
          tmp = do_usuniecia;
          do_usuniecia->nastepny->poprzedni = do_usuniecia->poprzedni;
          do_usuniecia->poprzedni->nastepny = tmp->nastepny;
          free(do_usuniecia);
     }
menu();
}
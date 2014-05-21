#include <stdio.h>

/*void gameplay();
int koniec();
*/
int main()
{
    int a,b,c;
    
    printf("a: ");
    scanf("%d",&a);
    printf("b: ");
    scanf("%d",&b);
    printf("c: ");
    scanf("%d",&c);
    
    if(a==22&&b==2) printf("Przypadek 1\n");
    else{
    if(a<b&&c==2) printf("Przypadek 2\n");
    else printf("Przypadek 3\n");
    }
    
    /*gameplay();
    printf("Brawo, dziala!\n");
    */
    system ("pause");
    
return 0;
}

/*
void gameplay()
{
char c;
char choice=0;
int i=0;

printf("Wpisz T aby dobrac karte.\n");
printf("Wpisz Q aby zakonczyc.\n");

while(1)
{
        i=0;
        choice=0;
        
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
                                                case '\n': break;
                                                case 't': {
                                                     printf("Dobralem karte.\n"); 
                                                     printf("Wpisz T aby dobrac karte.\n");
                                                     printf("Wpisz Q aby zakonczyc.\n");
                                                     break;}
                                                case 'T': {
                                                     printf("Dobralem karte.\n"); 
                                                     printf("Wpisz T aby dobrac karte.\n");
                                                     printf("Wpisz Q aby zakonczyc.\n");
                                                     break;}
                                                case 'q': koniec();break;
                                                case 'Q': koniec();break;
                                        }/*switch*/
                                  /*else
                                      if (c=='\n') printf("Niewlasciwa komenda! Mozesz dobrac karte (T) lub zakonczyc ture (Q)\n");
                                      else i++;
                                  
                          }/*else*/
        /*}/*while(c=getchar())*/
/*}/*while(1)*/

/*}/*gameplay()*/



/*===========================DOBRZE DZIALA!!!!!======================================================
int koniec()
{
    printf("Wygrales!\n");
    return 0;
    }

void gameplay()
{
     int i=0;
     char c,ch,choice=0;
     
     printf("Wpisz T aby dobrac karte.\n");
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
                                                case '\n': break;
                                                case 't': {
                                                     printf("Dobralem karte.\n");
                                                     printf("Wpisz T aby dobrac karte.\n");
                                                     printf("Wpisz Q aby zakonczyc.\n");
                                                     i=0;
                                                     break;}
                                                case 'T': {
                                                     printf("Dobralem karte.\n");
                                                     printf("Wpisz T aby dobrac karte.\n");
                                                     printf("Wpisz Q aby zakonczyc.\n");
                                                     i=0;
                                                     break;}
                                                case 'q': break;
                                                case 'Q': break;
                                        }/*switch*/
                                 /* else
                                      if (c=='\n') {printf("Niewlasciwa komenda! Mozesz dobrac karte (T) lub zakonczyc ture (Q)\n");i=0;}
                                      else i++;
                                  
                          }/*else*/
                         /* if(c=='\n'&&i==1&&choice) {koniec();break;}
     }
     
}/*gameplay()*/



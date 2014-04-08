#include <stdio.h>


int porownaj(char znaki1[],char znaki2[]);


char tablica1[5];
char tablica2[5];

int main()
{
     printf("Podaj pierwszy wyraz: ");
     gets(tablica1);
     printf("Podaj drugi wyraz: ");
     gets(tablica2);
     
     if(porownaj(tablica1,tablica2)) printf("Drugi wyraz jest dalej w kolejnosci alfabetycznej\n");
     else
     printf("Pierwszy wyraz jest dalej w kolejnosci alfabetycznej\n");
     
     
system("pause");    
return 0; 
}


int porownaj(char znaki1[],char znaki2[])
{
    
    int i;
    char a,b;
    
    for(i=0;i<5;i++)
    {
       a = znaki1[i];
       b = znaki2[i];
       if (a<b) return 1;
       if (a>b) break;
    }
    return 0;
        
}

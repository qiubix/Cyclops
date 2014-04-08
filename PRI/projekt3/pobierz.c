#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "def.h"
#include "funkcje.h"

int pobierz_znaki(struct element *a, FILE *f){

char znaki[MAX+1];
int i=0;
char c;
int blad;
int flaga = 0;


while(c!='\n'){
	c=getc(f);
	blad = 0;
	if(i==0){
		if(isalpha(c)){
			if(isupper(c)) znaki[i] = c;
			else if(islower(c)) znaki[i] = toupper(c);
			else if(isdigit
		}
		else{
			if(c=='\n') blad = 1;
			else blad = -1;
		}
	}
	else{
	
	}
	
	if(blad==1) return 0;
	if(blad==-1)break;
	
}


	while(c!='\n'){
		c=getc(f);
		if(c=='\n'){
			if(i==0) continue;
			else flaga = 1;
		}
		else if(isalpha(c)){
			if(i==0)
				znaki[i]=toupper(c);				
			else
				znaki[i]=c;
		}
		else if(c==' '){
			if(i==0) continue;
			else znaki[i]=c;
		}
		else{
			blad = 1;
		}
		if(flaga) break;
		if(blad) break;
		else i++;
	}
	if(flaga){
	strcpy(wyraz,znaki);
	return 1;
	}
	if(blad) return 0;
	return 0;

}



int pobierz_liczba(struct element *a){

int liczba;



}

void wyczysc(char a[],int dlugosc){
int i;
for(i=0;i<dlugosc;i++) 
	a[i] = 0;
return;
}
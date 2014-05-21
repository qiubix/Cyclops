/*Plik naglowkowy zawierajacy ciala funkcji odpowiedzialnych za wczytywanie danych.*/

/*funkcje zbierajace dane z klawiatury*/
void wpisz_przedmiot();
void wpisz_nazwa();
void wpisz_kod();
void wpisz_JD();
void wpisz_ECTS();
void wpisz_JK();
void wpisz_prowadzacy();
void wpisz_klasa();
void wpisz_opis();

/*funkcje wczytujace z pliku*/
void wczytaj_przedmiot();
void wczytaj_nazwa();
void wczytaj_kod();
void wczytaj_JD();
void wczytaj_ECTS();
void wczytaj_JK();
void wczytaj_prowadzacy();
void wczytaj_klasa();
void wczytaj_opis();


/*zmienne zewnetrzne*/


void wpisz_przedmiot()
{
printf("Podaj nazwe przedmiotu: ");
wpisz_nazwa();

printf("Podaj kod przedmiotu: ");
wpisz_kod();

printf("Podaj JD przedmiotu: ");
wpisz_JD();

printf("Podaj ECTS przedmiotu: ");
wpisz_ECTS();

printf("Podaj JK przedmiotu: ");
wpisz_JK();

printf("Podaj prowadzacego przedmiotu: ");
wpisz_prowadzacy();

printf("Podaj klase przedmiotu: ");
wpisz_klasa();

printf("Podaj opis przedmiotu: ");
wpisz_opis();
}

void wpisz_nazwa()
{

}
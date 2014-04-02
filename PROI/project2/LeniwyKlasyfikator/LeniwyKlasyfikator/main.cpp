//Karol Katerzawa
//PROI - Projekt 2 
//"Leniwy klasyfikator"

//main.cpp
//Uruchamia test modulowy klasyfikatora

#include <iostream>
#include "Sample.h"
#include "Klasyfikator.h"
#include "UnitTest.h"



int main(){
	Test t1;
	t1.inicjalizuj();
	t1.test_dodawania_elem();
	t1.test_usuwania_elem();
	t1.test_dodawania_klasyfikatorow();
	t1.test_znajdowania_najblizszego();
	t1.test_glosowania();
	t1.test_odejmowania_klasyfikatorow();
	t1.test_operatora_strumienia();
	t1.wypisz_wynik(std::cout);
	system("PAUSE");
}

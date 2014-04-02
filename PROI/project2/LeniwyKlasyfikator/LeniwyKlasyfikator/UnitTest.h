//UnitTest.h
//Definicja klasy Test, odpowiadajacej za sprawdzenie
//wszystkich modulow klasy Klasyfikator


#ifndef UNITTEST_H
#define UNITTEST_H


class Test{
	std::string wynik;
	Klasyfikator<Sample> k1;
	Klasyfikator<Sample> k2;
	Klasyfikator<Sample> k3;
public:
	void inicjalizuj();
	void test_dodawania_elem();
	void test_usuwania_elem();
	void test_odejmowania_elem();
	void test_znajdowania_najblizszego();
	void test_glosowania();
	void test_dodawania_klasyfikatorow();
	void test_odejmowania_klasyfikatorow();
	void test_operatora_strumienia();
	void wypisz_wynik(std::ostream & _o);
};

#endif //UNITTEST_H

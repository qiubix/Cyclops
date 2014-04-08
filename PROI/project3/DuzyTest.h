//DuzyTest.h

#ifndef DUZYTEST_H
#define DUZYTEST_H

#include "UnitTest.h"

class DuzyTest: public UnitTest{
	Klasyfikator<Sample> k1;
	Klasyfikator<Sample> k2;
	std::vector<Sample> v1;
	std::vector<Sample> v2;
	std::list<Sample> l1;
	std::list<Sample> l2;
public:
	DuzyTest();
	~DuzyTest();
	void inicjalizuj();
	void odczyt();
	void zapis();
	void testuj();
	void wynik(std::ostream &);
};

#endif //DUZYTEST_H


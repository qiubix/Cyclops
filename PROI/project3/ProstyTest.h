//ProstyTest.h


#ifndef PROSTYTEST_H
#define PROSTYTEST_H

#include "UnitTest.h"

class ProstyTest: public UnitTest{
	Klasyfikator<Sample> k1;
	Klasyfikator<Sample> k2;
	std::vector<Sample> v1;
	std::vector<Sample> v2;
	std::list<Sample> l1;
	std::list<Sample> l2;
public:
	ProstyTest();
	~ProstyTest();
	void inicjalizuj();
	void odczyt();
	void zapis();
	void testuj();
	void wynik(std::ostream &);
};

#endif //PROSTYTEST_H


//UnitTest.h
//Deklaracja abstrakcyjnej klasy zawierajacej testy klas CSVReaderWriter i XMLReaderWriter
//Klasy DuzyTest i MalyTest dziedzicza po niej. 



#ifndef UNITTEST_H
#define UNITTEST_H


#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Sample.h"
#include "Klasyfikator.h"
#include "text_cast.h"
#include "CSVReaderWriter.h"
//#include "XMLReaderWriter.h"

class UnitTest{
public:
	std::string wyniki;
	virtual void inicjalizuj() =0;
	virtual void odczyt() =0;
	virtual void zapis() =0;
	virtual void testuj() =0;
	virtual void wynik(std::ostream& ) =0;
};


#endif //UNITTEST_H

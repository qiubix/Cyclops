//ProstyTest.cpp


#include "ProstyTest.h"



//Kostruktor
ProstyTest::ProstyTest(){
	//...
}


//Destruktor
ProstyTest::~ProstyTest(){
	//...
}


void ProstyTest::inicjalizuj(){
	for(int i=0;i<10;i++){
		double *tmp = new double[MAX];
		for(int j=0;j<MAX;j++)
			tmp[j] = i + j + 0.5;
		k1.push_back(Sample(tmp));
		k2.push_back(Sample(tmp));
		v1.push_back(Sample(tmp));
		v2.push_back(Sample(tmp));
		//l1.push_back(Sample(tmp));
		//l2.push_back(Sample(tmp));
		delete []tmp;
	}
}


void ProstyTest::odczyt(){
	CSVReaderWriter<Sample, MAX, Klasyfikator<Sample> > csv_k;
	CSVReaderWriter<Sample, MAX, std::vector<Sample> > csv_v;
	//CSVReaderWriter<Sample, MAX, std::list<Sample> > csv_l;
	
	//Wyczyszczenie kontenerow, do ktorych nastapi wczytywanie
	k1.clear();
	v1.clear();
	l1.clear();
	
	bool czy_jest = true;

	//CSV do k1	
	try{
		csv_k.read(',',k1);
		for(int i=0; i<k2.size(); i++)
			if(!k1.find(k2[i]))
				czy_jest = false;
		//std::cout << "Odczyt do k1: " << czy_jest << "\n";
	}
	catch(string e){
		std::cerr << e;
		czy_jest = false;
	}

	//CSV do v1
	try{
		csv_v.read(',',v1); 
		if(!porownaj(v1,v2))
			czy_jest = false;
		//std::cout << "Odczyt do v1: " << czy_jest << "\n";
	}
	catch(string e){
		std::cerr << e;
		czy_jest = false;
	}
/*
	//CSV do l1
	try{
		csv_l.read(',',l1);
		if(!porownaj(l1,l2))
			czy_jest = false;
	}
	catch(string e){
		std::cerr << e;
		czy_jest = false;
	}
*/
	wyniki += "Test odczytu zakonczony ";
	if(czy_jest)
		wyniki += "pomyslnie.\n";
	else
		wyniki += "niepomyslnie!\n";
}


void ProstyTest::zapis(){
	CSVReaderWriter<Sample, MAX, Klasyfikator<Sample> > csv_k;
	CSVReaderWriter<Sample, MAX, std::vector<Sample> > csv_v;
	//CSVReaderWriter<Sample, MAX, std::list<Sample> > csv_l;
	
	bool czy_jest = true;
	//std::cout << k1;
	
	
	//zapis k1 do pliku
	try{
		csv_k.write(',',k1);
	}
	catch(string e){
		std::cerr << e;
		czy_jest = false;
	}

	//zapis v1 do pliku
	try{
		csv_v.write(',',v1);
	}
	catch(string e){
		std::cerr << e;
		czy_jest = false;
	}
	
	/*
	//zapis l1 do pliku  	
	try{
		csv_l.write(',',l1);
	}
	catch(string e){
		std::cerr << e;
		czy_jest = false;
	}*/
	wyniki += "Test zapisu zakonczony ";
	if(czy_jest)
		wyniki += "pomyslnie.\n";
	else
		wyniki += "niepomyslnie!\n";
}

void ProstyTest::testuj(){
	inicjalizuj();
	odczyt();
	zapis();
}

void ProstyTest::wynik(std::ostream & _o){
	_o << "Prosty test:\n";
	_o << wyniki;
}



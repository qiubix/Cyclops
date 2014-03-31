//PROI
//Autor: Karol Katerzawa
//Projekt 1 - "Leniwy klasyfikator"


//Samples.h
//Zawiera deklaracje klasy samples (probki)

#ifndef SAMPLES_H
#define SAMPLES_H

#define MAX 10

class Klasyfikator;

class Sample{
	double wektor[MAX];	//przechowuje liczby rzeczywiste
	bool klasa;			//symbol opisujacy klase probki
	void UstawKlase();
	double OdlegloscWektorow(double* );
public:
	Sample();		//Konstruktor
	~Sample();		//Destruktor

	//Metody
	void DodajNowa(double*);
	bool PorownajProbki(Sample& a, Sample& b);
	std::ostream& WypiszProbke(std::ostream& _o);		
	bool PokazKlase();

	//Przeciazenie operatorow
	friend bool operator ==(Sample&,Sample&);
	//friend std::ostream& operator <<(std::ostream&,Klasyfikator&);
	//friend std::ostream& operator <<(std::ostream&,Sample&);
};

void operator << (std::ostream& _o, Sample& _s);


#endif //SAMPLES_H

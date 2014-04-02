//Sample.h
//Zawiera definicje klasy Sample


#ifndef SAMPLE_H
#define SAMPLE_H

//Rozmiar wektora probki
const int MAX = 10;


class Sample{
	double wektor[MAX];
	bool klasa;
	double OdlegloscWektorow(const Sample& );
	std::ostream & WypiszProbke(std::ostream & _o);
public:
	//Konstruktory i destruktor
	Sample();
	Sample(bool);
	Sample(double*, bool);
	~Sample(){};

	//metody klasy Sample i przeciazenia operatorow
	void DodajNowa(double*, bool);
	bool PokazKlase();
	void friend operator <<(std::ostream& _o, Sample& _s);
	bool friend operator ==(const Sample &, const Sample &);
	double friend operator -(const Sample &, Sample &);
};


#endif //SAMPLE_H

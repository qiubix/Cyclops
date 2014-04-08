//Karol Katerzawa
//PROI - Projekt 3.

//CSVReaderWriter.h
//Definicje metod klasy szablonowej CSVReaderWriter

#ifndef CSVREADERWRITER_INL_H
#define CSVREADERWRITER_INL_H

#include <fstream>
#include <vector>


template <typename Element, unsigned int columns, typename Container>
void CSVReaderWriter<Element,columns,Container>::read(const char _separator, Container & _output){

	std::ifstream in("dane.csv");		//Otwarcie pliku
	
	std::string line_tmp;			//przechowuje pojedyncza linie
	while(getline(in, line_tmp)){
		std::vector<std::string> entry;				//vector entry zawierajacy poszczegolne pola skladajace sie na linie
		std::stringstream line;
		std::string field;					//string przechowujacy pojedyncze pole
		line << line_tmp;
		int field_count = 0;					//zlicza pola w linii
		while(getline(line, field, _separator)){		//przebiega linie co separator
			entry.push_back(field);				//dodaje do entry pole
			++field_count;
		}
		if(field_count == columns)				//sprawdza, czy liczba pol w wierszu jest poprawna
			_output.push_back(Element(entry));		//tworzy Element z danym wierszem, a nastepnie dodaje go do Container
	}
}

template <typename Element, unsigned int columns, typename Container>
void CSVReaderWriter<Element,columns,Container>::write(const char _separator, Container & _input){

	std::ofstream out("backup.csv");		//Otwarcie pliku

	std::stringstream file;		//sstream file przechowuje caly Containter
	std::string line_tmp;
	for(int i=0; i<static_cast<int>(_input.size()); i++)
		file << _input[i];				//przeslanie Containera do file

	while(getline(file,line_tmp)){					//pobieranie ze sstream file po jednej linii i zapisywanie jej do line
		std::string field, entry;				//stringi do przechowywania pojedynczego pola i gotowej linii
		std::stringstream line;
		line << line_tmp;
		int field_count = 0;					//zlicza pola w linii
		while(getline(line,field, '\t')){			//pobieranie z linii pol oddzielonych spacjami
			entry += field;					//dodanie pola do stringa entry			
			++field_count;					//zwiekszenie licznika pol
			if(field_count < MAX)
				entry += _separator;				//dodanie separatora po polu
		}
		if(field_count == columns){				//sprawdza poprawnosc pol w wierszu
			out << entry << '\n';				//dodaje gotowa linie do pliku i znak nowej linii na koncu
		}
	}
}

#endif //CSVREADERWRITER_INL_H


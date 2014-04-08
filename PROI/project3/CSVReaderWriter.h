//Karol Katerzawa
//PROI - Projekt 3.

//ReadWriteCSV.h
//Deklaracje klasy szablonowej do odczytu i zapisu z pliku CSV

#ifndef CSVREADERWRITER_H
#define CSVREADERWRITER_H

template <typename Element, unsigned int columns, typename Container>
class CSVReaderWriter{
	public:
		CSVReaderWriter(){};
		~CSVReaderWriter(){};
		void read (const char _separator, Container & _output);
		void write (const char _separator, Container & _input);
};

#include "CSVReaderWriter_inl.h"

#endif //CSVREADERWRITER_H


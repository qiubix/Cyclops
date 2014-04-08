//Karol Katerzawa
//PROI - Projekt 3.

//XMLReaderWriter.h
//Deklaracja klasy XMLReaderWriter i jej metod

#ifndef XMLREADERWRITER_H
#define XMLREADERWRITER_H

template <typename Element, unsigned int columns, template<class> class Klasyfikator>
class XMLReaderWriter{
	public: 
		void read (Klasyfikator<Element> & _output);
		void write (Klasyfikator<Element> & _input);
};

#include "XMLReaderWriter_inl.h"

#endif //XMLREADERWRITER_H


//Karol Katerzawa
//PROI - Projekt 3.

//XMLReaderWriter_inl.h
//Definicje metod klasy XMLReaderWriter

#ifndef XMLREADERWRITER_INL_H
#define XMLREADERWRITER_INL_H

template <typename Element, unsigned int columns, template<class> class Klasyfikator>
void XMLReaderWriter<Element,columns,Klasyfikator>::read(Klasyfikator<Element> & _output){
	std::ifstream in("dane.xml");
	
	std::string line;
	while(getline(in,line)){
		std::vector<std::string> entry;
		std::stringstream line_tmp;
		line_tmp << line;
		


#endif //XMLREADERWRITER_INL_H


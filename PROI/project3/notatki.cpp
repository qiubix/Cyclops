
void CSVReaderWriter<Element,columns,Klasyfikator>::
read (const char _separator, Klasyfikator<Element> & _output){

	ifstream in("dane.csv");		//Otwarcie pliku
	
	std::stringstream line;
	while(getline(in, line)){
		std::vector<std::string> entry;
		std::string field;
		int field_count = 0;
		while(getline(line, field, _separator)){
			entry.push_back(field);
			++field_count;
		}
		_output.push_back(Element(entry));
	}
}


	std::string field;			//string przechowujacy pojedyncze pole miedzy separatorami
	std::vector<std::string> entry;		//vector przechowujacy pojedyncza linie
	int field_count = 0;			//Liczba pol w linii
	bool czy_dodac = true;			//Flaga - dodawanie linii

	while(getline(in, field, _separator)){
		entry.push_back(field);		//dodanie pola do vectora przechowujacego cala linie
		++field_count;
		if(field_count == columns){				//osiagnieto koniec linii
			_output.push_back(Element(entry));		//Element o danych jak we wczytanej linii zostaje dodany do Container
			entry.erase(entry.begin(), entry.end());	//wyczyszczenie vectora przechowujacego wczytana linie
		}
		czy_dodac = true;
	}
}



template <typename Element, unsigned int columns, template<class> class Klasyfikator>
void class CSVReaderWriter<Element,columns,Klasyfikator>::read(const char _separator, Klasyfikator<Element> & _output){
	//...
}

void CSVReaderWriter<Element,columns,Klasyfikator>::
read (const char _separator, Klasyfikator<Element> & _output){



template<class T>
void Klasyfikator<T>::push_back(const T & element){
	bool czy_dodac = true;
	for(int i=0; i<wielkosc; i++){
		if(tablica[i] == element){
			czy_dodac = false;
			break;
		}
	}
	if(czy_dodac){
		int nowa_wielkosc = wielkosc + 1;
		T* temp = new T[nowa_wielkosc];
		
		for(int i=0; i<wielkosc; i++)
			temp[i] = tablica[i];
		temp[wielkosc] = element;
		delete []tablica;
		






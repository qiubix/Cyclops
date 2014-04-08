//Karol Katerzawa
//PROI - Projekt 3.

//text_cast.h
//Szablon klasy rzutujacej ze stringa na dany typ

#ifndef TEXT_CAST_H
#define TEXT_CAST_H

#include <sstream>
#include <string>
#include <stdexcept>

using std::stringstream;
using std::string;
using std::runtime_error;

template<typename To, typename From>
To text_cast(const From & _from) {
	stringstream str;
	To _to;
	str << _from;
	str >> _to;
	
	return _to;
}


template<class T>
bool porownaj(const T& a, const T&b){
	if(a.size()!=b.size())
		return false;
	else{
		for(int i=0; i<static_cast<int>(a.size()); i++){
			bool znaleziono = false;
			for(int j=0; j<static_cast<int>(b.size());j++)
				if(a[i] == b[j]){
					znaleziono = true;
					break;
				}
			if(!znaleziono)
				return false;
		}
	}
	return true;
}


#endif //TEXT_CAST_H


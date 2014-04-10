/** 
@file asd.cc

Plik do modyfikacji w ramach cwiczenia z AISDI.
Zawiera niekompletne implementacje metod klasy ListMap,
oraz mape podobna koncepcyjnie do tej z cwicznia 1 (SmallMap)
zaimplementowana w jescze bardziej szczatkowy sposob.
Jest tez prosta funkcja testujaca (void test()), ktora
jest wolana w funkcji main. Mozna w niej zaimplementowac
wlasne testy.
NALEZY ZMODYFIKOWAC I UZUPELNIC CIALA METOD KLASY LISTMAP.
    
@author
Pawel Cichocki, Michal Nowacki

@date  
last revision
- 2006.01.06 Michal Nowacki: wersja polska
- 2005.11.17 Michal Nowacki: constructor
- 2005.11.04 Pawel Cichocki: copied comments from the header
- 2005.11.03 Pawel Cichocki: const_iterator done properly now
- 2005.10.27 Pawel Cichocki: cosmetic changes
- 2005.10.26 Michal Nowacki: removed some method bodies
- 2005.10.25 Pawel Cichocki: wrote it

COPYRIGHT:
Copyright (c) 2005 Instytut Informatyki, Politechnika Warszawska
ALL RIGHTS RESERVED
*******************************************************************************/

#include <assert.h>
#include <algorithm>

#include <iostream>

#ifdef _SUNOS
#include "/home/common/dyd/aisdi/liniowe/ListMap.h" 
#else
#include "ListMap.h"
#endif

//////////////////////////////////////////////////////////////////////////////
// ListMap and ListMap::iterator methods
//////////////////////////////////////////////////////////////////////////////

ListMap::ListMap()
{
	first=new Node(std::make_pair( -1, "STRAZNIK"));
    first->next=first;
    first->prev=first;
    first->internalDataPointer=first;
};

ListMap::ListMap( const ListMap& m )
{
	first=new Node(std::make_pair( -1, "STRAZNIK"));
    first->next=first;
    first->prev=first;
    first->internalDataPointer=first;
	if (!m.empty())
	{
		for (const_iterator i=m.begin(); i!=m.end(); i++)
			unsafe_insert(std::make_pair(i->first, i->second));
	}
};

ListMap::~ListMap()
{
	clear();
	delete first;
	first=NULL;
};

// Wstawienie elementu do mapy.
// @returns Para, kt�rej komponent bool jest r�wny true gdy wstawienie zosta�o
//          dokonane, r�wny false gdy element identyfikowany przez klucz
//          ju� istnia� w mapie. Iterator ustawiony jest na ten wstawiony 
//          lub istniej�cy ju� w mapie element.
std::pair<ListMap::iterator, bool> ListMap::insert(const std::pair<Key, Val>& entry)
{
	iterator i;
    i=find(entry.first);
	if (i== end())
		return std::make_pair(unsafe_insert(entry),true);
	else
	{
	i->second=entry.second;
	return std::make_pair(i, false);
	}
}

// Wstawienie elementu do mapy.
// Matoda zak�ada, �e w mapie nie wyst�puje element identyfikowany przez key
ListMap::iterator ListMap::unsafe_insert(const std::pair<Key, Val>& entry)
{
	Node *temp;
	temp=new Node(std::make_pair(entry.first,entry.second));
	temp->internalDataPointer=NULL;
	iterator koniec=end();
	if(empty())
	{
		first->prev=temp;
		first->next=temp;
		first=temp;
		first->prev=koniec.node;
		first->next=koniec.node;
		return iterator(first);
	}
	iterator poczatek=begin();
	if (poczatek->first>entry.first)
	{
		temp->next=first;
    		temp->prev=first->prev;
		first->prev->next=temp;
		first->prev=temp;
		first=temp;
		return iterator(first);
	}
	while (poczatek!=koniec) 
	{
        if(poczatek->first>entry.first) 
			break;
		poczatek++;
    }
	temp->next=poczatek.node;
	temp->prev=poczatek.node->prev;
	poczatek.node->prev->next=temp;
	poczatek.node->prev=temp;
	poczatek.node=temp;
    return poczatek;
}

// Zwraca iterator addresuj�cy element w mapie dla kt�rego klucz jest r�wny 
// szukanemu kluczowi lub element za ostatnim gdy szukanego klucza brak w mapie.
ListMap::iterator ListMap::find(const Key& k)
{
	iterator i=first;
	iterator koniec=end();
	while(i!=koniec)
		if(i->first==k)
			return i;
		else
			i++;
	return koniec;}

ListMap::const_iterator ListMap::find(const Key& k) const
{
	const_iterator i=first;
	const_iterator koniec=end();
	while(i!=koniec)
		if(i->first==k)
			return i;
		else
			i++;
	return koniec;
}

// Udost�pnia warto�� powi�zan� z kluczem key. Wstawia element do mapy je�li 
// nie istnia�.
// @returns Referencje do warto�ci powi�zanej z kluczem.
ListMap::Val& ListMap::operator[](const Key& k)
{
	iterator i=find(k);
	if(i==end())
		return insert(std::make_pair(k, "")).first->second;
	else
		return i->second;
}

// Sprawdzenie czy mapa jest pusta.
bool ListMap::empty() const
{
	return (first->prev==first);
}

// Zwraca ilo�� element�w w mapie.
ListMap::size_type ListMap::size( ) const
{
	int size=0;
	iterator i=first;
	while (i!=end())
	{
		size++;
		i++;
	}
	return size;
}

// Zwraza ilo�� element�w skojarzonych z kluczem key.
ListMap::size_type ListMap::count(const Key& _Key) const
{
    if (find(_Key)==end()) 
		return 0;
    return 1;
}

// Usuwa element z mapy.
// @returns iterator adresuj�cy pierwszy element za usuwanym.
ListMap::iterator ListMap::erase(ListMap::iterator i)
{
	if (i==end()) return i;
	if (i.node==first)
	{
		first=first->next;
		first->prev=i.node->prev;
		i.node->prev->next=first;
		delete i.node;
	}
	else
	{
		i.node->prev->next=i.node->next;
        i.node->next->prev=i.node->prev;
        delete i.node;
	}
	i++;
	return i;
}

// Usuwa zakres element�w z mapy.
// Zakres jest zdefiniowany poprzez iteratory first i last
// first jest okre�la pierwszy element do usuni�cia, a last okre�la element 
// po ostatnim usuni�tym elemencie.
// @returns iterator adresuj�cy pierwszy element za usuwanym.
ListMap::iterator ListMap::erase(ListMap::iterator f, ListMap::iterator l)
{
	if (f==l) return erase(l);
	while(f!=l)
		f=erase(f);
	if(f==end())
		return f;
	else
		return erase(f);
}

// Usuwa element z mapy.
// @returns Ilo�� usuni�tych element�w.
//          (nie jest to multimapa, wi�� mo�e by� to warto�� 1 lub 0 )
ListMap::size_type ListMap::erase(const Key& key)
{
	iterator i=find(key);
	if(i==end())
		return 0;
	else
	{
		erase(i);
		return 1;
	}
}

// Usuni�cie wszystkich element�w z mapy.
void ListMap::clear( )
{
	iterator koniec=end();
	erase(begin(),end());
	first=koniec.node;
	first->prev=first;
	first->next=first;
	return;
}

// Por�wnanie strukturalne map.
// Czy reprezentacja danych jest identyczna.
// Zwraca true je�li wewn�trzne struktury map s� identyczne.
bool ListMap::struct_eq(const ListMap& another) const
{
	return info_eq(another);
}

// Por�wnanie informacyjne map.
// Czy informacje trzymane w mapach s� identyczne.
// Zwraca true je�li mapy zwieraj� takie same pary klucz-warto��.
bool ListMap::info_eq(const ListMap& another) const
{
	if(size() != another.size()) return false;
	iterator i(first),j(another.first);
	
	for(;i!=end();i++,j++)
		if(i->first!=j->first||i->second!=j->second)
            return false;
	return true;
}

// preincrementacja
ListMap::const_iterator& ListMap::const_iterator::operator++()
{
	if(node->internalDataPointer==NULL)
	    node=node->next;
	return *this;
}

// postincrementacja
ListMap::const_iterator ListMap::const_iterator::operator++(int)
{
	const_iterator temp(*this);
	if(node->internalDataPointer==NULL)
		node=node->next;
	return temp;
}

ListMap::const_iterator& ListMap::const_iterator::operator--()
{
	if(node->prev->internalDataPointer==NULL)
		node=node->prev;
	return *this;
}

// postincrementacja
ListMap::const_iterator ListMap::const_iterator::operator--(int)
{
	const_iterator temp(*this);
	if(node->prev->internalDataPointer==NULL)
		node=node->prev;
	return temp;
}

/// Zwraca iterator addresuj�cy pierwszy element w mapie.
ListMap::iterator ListMap::begin()
{ 
	return iterator(first);
}

/// Zwraca iterator addresuj�cy pierwszy element w mapie.
ListMap::const_iterator ListMap::begin() const
{ 
	return iterator(first);
}

/// Zwraca iterator addresuj�cy element za ostatnim w mapie.   
ListMap::iterator ListMap::end()
{ 
	return iterator(first->prev);
}

/// Zwraca iterator addresuj�cy element za ostatnim w mapie.   
ListMap::const_iterator ListMap::end() const
{ 
	return const_iterator(first->prev);
}

//////////////////////////////////////////////////////////////////////////////
// SmallMap
//////////////////////////////////////////////////////////////////////////////

/// Przyk�ad map'y z implementacj� podobn� do std::map.
/// To jest jedynie przyk�ad!!!
/// Normalnie implementacja powinna opiera� si� o drzewo lub tablic� haszuj�c�.
template <class Key, class Val>
class SmallMap
{
   std::pair<Key, Val> tab[2];
   int isOcupied[2];
public:

   SmallMap()
   {
      for(unsigned i=0; i<2; ++i)
      {
         isOcupied[i]=0;
      }
   }

   typedef std::pair<Key, Val>* iterator;   ///< Ka�dy wska�nik jest te� iteratorem.

   iterator begin() { return tab; }
   iterator end() { return tab+2; }

   Val& operator[](const Key& k)
   {
      static Val val;
      for(unsigned i=0; i<2; ++i)
      {
         if(isOcupied[i]&&tab[i].first==k)
            return tab[i].second;
      }
      // create
      for(unsigned i=0; i<2; ++i)
      {
         if(!isOcupied[i])
         {
            tab[i].first=k;
            isOcupied[i]=1;
            return tab[i].second;
         }
      }
      //std::cout<<"Out of space! You should not put more than two Key-Value pairs into the SmallMap.\n";
      std::cerr<<"Out of space! You should not put more than two Key-Value pairs into the SmallMap.\n";
      //assert(0);
      return val;   // Ma�o sensowne, ale to jest tylko przyk��d
   }
};
      

//////////////////////////////////////////////////////////////////////////////
// Testy
//////////////////////////////////////////////////////////////////////////////

/// Funckcja pomocnicza do wypisania element�w.
void print(const std::pair<int, std::string>& p)
{
   std::cout<<p.first<<", "<<p.second<<std::endl;
}

#include <map>

/// Testy u�ytkownika
void test()
{
   // A typedef used by the test.
   typedef std::map<int, std::string> TEST_MAP;
   //typedef SmallMap<int, std::string> TEST_MAP;
   //typedef ListMap TEST_MAP;

   std::cout << "Testy uzytkownika" << std::endl;

        TEST_MAP m;  
   
   m[2] = "Merry";
   m[4] = "Jane";
   m[8] = "Korwin";
   m[4] = "Magdalena";

   for_each(m.begin(), m.end(), print );
   //system("PAUSE");
}


//double t[MAX] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
	/*Sample S;
	S.DodajNowa(t);
	S.WypiszProbke(0);
	double x[MAX] = {0};
	cout << S.OdlegloscWektorow(x) << endl;*/

	//Klasyfikator k;
	//k.DodajProbki(5,0.7);
	//k.WypiszZawartosc();

	/*
	double t[MAX] = {0};
	double a = 1.5;
	for(int i = 0; i < MAX; i++)
		t[i] = a + i;
	*/


	//k.WyszukajNajblizsza(x);
	//k.ZamienProbki(0,4);
	//k.WypiszZawartosc();

	//Klasyfikator k2;
	//k2.DodajProbki(2,0.5);
	//k2 = k;
	//cout << k;


	inicjalizuj();
	k.DodajProbki(5,0.7);
	cout << k;
	cout << "Zostaly dodane probki do klasyfikatora k.\n\n";

	//k.ZamienProbki(4,1);
	//cout << k;

	
	//Sample x;
	double t[MAX] = {1.5,4.1,2.2,0.6,5.1,10.5,3.2,9.8,9.0,12.3};
	//x.DodajNowa(t);
	//cout << "Dodana probka to: \n" << x << "\n\n";
	//cout << "Najblizsza probka:\n" << k.WyszukajNajblizsza(k.DodajKolejna(t)) << "\n\n\n";
	//cout << k;
	cout << "\nKlasa bedaca w wiekszosci po przeprowadzeniu glosowania, to: " << k.Glosowanie(k.DodajKolejna(t)) << "\n\n";
	cout << k;


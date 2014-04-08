projekt: main.o menu.o obsluga.o sort.o wczytaj.o
	gcc main.o menu.o obsluga.o sort.o wczytaj.o -o projekt -Wall
main.o: main.c
	gcc -c -Wall main.c
menu.o: menu.c
	gcc -c -Wall menu.c
obsluga.o: obsluga.c
	gcc -c -Wall obsluga.c
sort.o: sort.c
	gcc -c -Wall sort.c
wczytaj.o: wczytaj.c
	gcc -c -Wall wczytaj.c

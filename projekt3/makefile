CGFLAGS=-c -Wall -pedantic
OBJ=main.o menu.o obsluga.o sort.o wczytaj.o


program: $(OBJ)
    gcc $(CGFLAGS) $(OBJ) -o program

main.o: main.c
    gcc $(CGFLAGS) main.c

menu.o: menu.c
    gcc $(CGFLAGS) menu.c

obsluga.o: obsluga.c
    gcc $(CGFLAGS) obsluga.c

sort.o: sort.c
    gcc $(CGFLAGS) sort.c

wczytaj.o: wczytaj.c
    gcc $(CGFLAGS) wczytaj.c


clean:
rm -f main.o menu.o obsluga.o sort.o wczytaj.o

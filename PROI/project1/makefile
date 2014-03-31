CGFLAGS=-Wall
OBJ=main.o Samples.o Klasyfikator.o

program: $(OBJ)
	g++ $(CGFLAGS) $(OBJ) -o program

Samples.o: Samples.cpp Samples.h
	g++ -c $(CGFLAGS) Samples.cpp

Klasyfikator.o: Klasyfikator.cpp Klasyfikator.h
	g++ -c $(CGFLAGS) Klasyfikator.cpp

main.o: main.cpp Samples.h Klasyfikator.h
	g++ -c $(CGFLAGS) main.cpp

clean:
	rm -f main.o Samples.o Klasyfikator.o

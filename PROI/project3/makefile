CGFLAGS=-Wall
OBJ=main.o Sample.o ProstyTest.o

program: $(OBJ)
	g++ $(CGFLAGS) $(OBJ) -o program

Sample.o: Sample.cpp
	g++ -c $(CGFLAGS) Sample.cpp

ProstyTest.o: ProstyTest.cpp
	g++ -c $(CGFLAGS) ProstyTest.cpp

main.o: main.cpp
	g++ -c $(CGFLAGS) main.cpp

clean:
	rm -f main.o Sample.o ProstyTest.o

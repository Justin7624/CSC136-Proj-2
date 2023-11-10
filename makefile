debugFlag=-g

all: testchild savings

savings: Child.o savings.o
        g++ -o savings savings.o Child.o $(debugFlag)

savings.o: savings.cpp Child.h
        g++ -c savings.cpp -o savings.o $(debugFlag)

Child.o: Child.cpp Child.h
        g++ -c Child.cpp $(debugFlag)

testchild: Child.o testchild.o
        g++ -o testchild testchild.o Child.o $(debugFlag)

testchild.o: testchild.cpp Child.h
        g++ -c testchild.cpp -o testchild.o $(debugFlag)

clean:
        rm -f *.o testchild savings

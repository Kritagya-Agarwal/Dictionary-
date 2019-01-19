all: dictionary

dictionary: main.o AVLTree.o
	g++ main.o AVLTree.o -o dictionary

main.o: main.cpp
	g++ -c main.cpp

AVLTree.o : AVLTree.cpp
	g++ -c AVLTree.cpp

clean:
	rm *.o dictionary
	

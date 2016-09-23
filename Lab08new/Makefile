Lab08: main.o Test.o
	g++ -g -std=c++11 -Wall main.o Test.o -o Lab08

main.o: main.cpp BSTI.h BinarySearchTree.h BinarySearchTree.hpp Node.h Node.hpp Test.h
	g++ -g -std=c++11 -Wall -c main.cpp

Test.o: Test.cpp Test.h BinarySearchTree.h
	g++ -g -std=c++11 -c Test.cpp

clean:
		rm *.o Lab08
		echo clean do-diddly done

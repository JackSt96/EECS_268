Lab03: main.o Test.o
	g++ -g -std=c++11 -Wall main.o Test.o -o Lab03

main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp Test.h
	g++ -g -std=c++11 -Wall -c main.cpp

Test.o: Test.cpp Test.h
	g++ -g -std=c++11 -c Test.cpp

clean:
		rm *.o Lab03
		echo clean do-diddly done

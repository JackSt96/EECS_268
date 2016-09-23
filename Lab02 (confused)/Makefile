
Lab02: main.o Node.o LinkedList.o
	g++ -g -std=c++11 main.o Node.o LinkedList.o -o Lab02

main.o: main.cpp Node.h LinkedList.h
	g++ -g -std=c++11 -c main.cpp

Node.o: Node.cpp Node.h
	g++ -g -std=c++11 -c Node.cpp
	
LinkedList.o: LinkedList.cpp LinkedList.h Node.h
	g++ -g -std=c++11 -c LinkedList.cpp

clean:
		rm *.o Lab02
		echo clean do-diddly done

Lab04: main.o Test.o PreconditionViolationException.o
	g++ -g -std=c++11 -Wall main.o Test.o PreconditionViolationException.o -o Lab04

main.o: main.cpp Stack.h Stack.hpp StackInterface.h Node.h Node.hpp Test.h
	g++ -g -std=c++11 -Wall -c main.cpp

Test.o: Test.cpp Test.h
	g++ -g -std=c++11 -c Test.cpp

PreconditionViolationException.o: PreconditionViolationException.cpp PreconditionViolationException.h
	g++ -g -std=c++11 -c PreconditionViolationException.cpp

clean:
		rm *.o Lab04
		echo clean do-diddly done

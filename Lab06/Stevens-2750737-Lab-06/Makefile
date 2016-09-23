Lab06: main.o Test.o
	g++ -g -std=c++11 -Wall main.o Test.o -o Lab06

main.o: main.cpp Sorts.h Sorts.hpp Test.h
	g++ -g -std=c++11 -Wall -c main.cpp

Test.o: Test.cpp Test.h Sorts.h
	g++ -g -std=c++11 -c Test.cpp

clean:
		rm *.o Lab06
		echo clean do-diddly done

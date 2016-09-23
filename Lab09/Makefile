Lab09: main.o MazeCreationException.o MazeWalker.o Position.o MazeReader.o Test.o
	g++ -g -std=c++11 -Wall main.o MazeCreationException.o MazeWalker.o Position.o MazeReader.o Test.o -o Lab09

main.o: main.cpp MazeCreationException.h MazeReader.h MazeWalker.h Test.h
	g++ -g -std=c++11 -Wall -c main.cpp

MazeCreationException.o: MazeCreationException.cpp MazeCreationException.h
	g++ -g -std=c++11 -c MazeCreationException.cpp

MazeWalker.o: MazeWalker.cpp MazeWalker.h Position.h
	g++ -g -std=c++11 -c MazeWalker.cpp

Position.o: Position.cpp Position.h
	g++ -g -std=c++11 -c Position.cpp

MazeReader.o: MazeReader.cpp MazeReader.h MazeCreationException.h
	g++ -g -std=c++11 -c MazeReader.cpp

Test.o: Test.cpp Test.h ArrayHelper.h MazeWalker.h MazeReader.h
	g++ -g -std=c++11 -c Test.cpp

ArrayHelper.o: ArrayHelper.cpp ArrayHelper.h
	g++ -g -std=c++11 -c ArrayHelper.cpp

clean:
		rm *.o Lab09
		echo clean do-diddly done

Lab05: main.o AnimalPen.o PreconditionViolationException.o FarmAnimal.o Cow.o CyberChicken.o Chicken.o
	g++ -g -std=c++11 -Wall main.o AnimalPen.o PreconditionViolationException.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o -o Lab05

main.o: main.cpp StackInterface.h Cow.h Chicken.h CyberChicken.h AnimalPen.h FarmAnimal.h
	g++ -g -std=c++11 -Wall -c main.cpp

AnimalPen.o: AnimalPen.cpp AnimalPen.h Node.h Node.hpp StackInterface.h Stack.h Stack.hpp FarmAnimal.h PreconditionViolationException.h
	g++ -g -std=c++11 -Wall -c AnimalPen.cpp

FarmAnimal.o: FarmAnimal.cpp FarmAnimal.h
	g++ -g -std=c++11 -c FarmAnimal.cpp

Cow.o: Cow.cpp Cow.h FarmAnimal.h
	g++ -g -std=c++11 -c Cow.cpp

Chicken.o: Chicken.cpp Chicken.h FarmAnimal.h
	g++ -g -std=c++11 -c Chicken.cpp

CyberChicken.o: CyberChicken.cpp CyberChicken.h Chicken.h
	g++ -g -std=c++11 -c CyberChicken.cpp

PreconditionViolationException.o: PreconditionViolationException.cpp PreconditionViolationException.h
	g++ -g -std=c++11 -c PreconditionViolationException.cpp

clean:
		rm *.o Lab05
		echo clean do-diddly done

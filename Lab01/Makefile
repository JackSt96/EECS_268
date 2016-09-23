Lab01: main.o Pokemon.o Colosseum.o Dice.o 
		g++ -g -o Lab01 main.o Pokemon.o Colosseum.o Dice.o 

main.o: main.cpp Pokemon.cpp Colosseum.cpp
		g++ -c -g main.cpp
	
Dice.o: Dice.cpp Dice.h
		g++ -c -g Dice.cpp
	
Pokemon.o: Pokemon.cpp Pokemon.h
		g++ -c -g Pokemon.cpp
	
Colosseum.o: Colosseum.cpp Colosseum.h Dice.h Pokemon.h
		g++ -c -g Colosseum.cpp

clean: 
	rm *.o Lab01
	echo clean do-diddly done
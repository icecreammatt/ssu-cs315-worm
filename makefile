worm: main.o game.o ScreenImage.o WormBody.o Cell.o getChar.o
	g++ -ggdb -o worm main.o game.o ScreenImage.o WormBody.o Cell.o getChar.o -lncurses

main.o: main.cpp game.hpp ScreenImage.hpp Cell.hpp WormBody.hpp
	gcc -ggdb -c main.cpp -lncurses

ScreenImageImage.o: ScreenImage.hpp ScreenImage.cpp Cell.hpp WormBody.hpp
	gcc -ggdb -c ScreenImage.cpp -lncurses

WormBody.o: WormBody.hpp WormBody.cpp Cell.hpp
	gcc -ggdb -c WormBody.cpp

game.o: game.hpp game.cpp WormBody.hpp ScreenImage.hpp Cell.hpp
	gcc -ggdb -c game.cpp

Cell.o: Cell.hpp Cell.cpp
	gcc -ggdb -c Cell.cpp -lncurses

getChar.o: getChar.cpp
	gcc -ggdb -c getChar.cpp -lncurses

clean:
	rm *.o worm

backup:
	cp * ~/backupWorm/

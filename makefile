worm.x: main.o game.o ScreenImage.o WormBody.o Cell.o getChar.o
	g++ -g -o worm.x main.o game.o ScreenImage.o WormBody.o Cell.o -lncurses getChar.o

main.o: main.cpp game.hpp ScreenImage.hpp Cell.hpp WormBody.hpp
	g++ -g -c  main.cpp

ScreenImageImage.o: ScreenImage.hpp ScreenImage.cpp Cell.hpp WormBody.hpp
	g++ -g -c ScreenImage.cpp

WormBody.o: WormBody.hpp WormBody.cpp Cell.hpp
	g++ -g -c WormBody.cpp

game.o: game.hpp game.cpp WormBody.hpp ScreenImage.hpp Cell.hpp
	g++ -g -c game.cpp

Cell.o: Cell.hpp Cell.cpp
	g++ -g -c Cell.cpp

getChar.o: getChar.cpp
	gcc -ggdb -c getChar.cpp

clean:
	rm *.o worm.x

backup:
	cp * ~/backupWorm/
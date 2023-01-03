worm.x: main.o game.o ScreenImage.o WormBody.o Cell.o getChar.o
	g++ -ggdb -o worm.x main.o game.o ScreenImage.o WormBody.o Cell.o getChar.o -lncurses

main.o: main.cpp game.hpp ScreenImage.hpp Cell.hpp WormBody.hpp
	gcc -ggdb -c -O0 main.cpp -lncurses

ScreenImageImage.o: ScreenImage.hpp ScreenImage.cpp Cell.hpp WormBody.hpp
	gcc -ggdb -c -O0 ScreenImage.cpp -lncurses

WormBody.o: WormBody.hpp WormBody.cpp Cell.hpp
	gcc -ggdb -c -O0 WormBody.cpp -lncurses

game.o: game.hpp game.cpp WormBody.hpp ScreenImage.hpp Cell.hpp
	gcc -ggdb -c -O0 game.cpp -lncurses

Cell.o: Cell.hpp Cell.cpp
	gcc -ggdb -c -O0 Cell.cpp -lncurses

getChar.o: getChar.cpp
	gcc -ggdb -c -O0 getChar.cpp -lncurses

clean:
	rm *.o worm.x

backup:
	cp * ~/backupWorm/
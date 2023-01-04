worm: main.o game.o ScreenImage.o WormBody.o Cell.o getChar.o
	clang++ -ggdb -o worm main.o game.o ScreenImage.o WormBody.o Cell.o getChar.o -lncurses

main.o: main.cpp game.hpp ScreenImage.hpp Cell.hpp WormBody.hpp
	clang++ -ggdb -c main.cpp

ScreenImageImage.o: ScreenImage.hpp ScreenImage.cpp Cell.hpp WormBody.hpp
	clang++ -ggdb -c ScreenImage.cpp -lncurses

WormBody.o: WormBody.hpp WormBody.cpp Cell.hpp
	clang++ -ggdb -c WormBody.cpp

game.o: game.hpp game.cpp WormBody.hpp ScreenImage.hpp Cell.hpp
	clang++ -ggdb -c game.cpp

Cell.o: Cell.hpp Cell.cpp
	clang++ -ggdb -c Cell.cpp

getChar.o: getChar.cpp
	clang++ -ggdb -c getChar.cpp

clean:
	rm *.o worm
	# rm ./bin/worm
	# rmdir bin

# install:
	# mkdir ./bin
	# cp worm ./bin/worm

backup:
	cp * ~/backupWorm/

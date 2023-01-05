compiler := $(COMPILER)

worm: main.o game.o ScreenImage.o WormBody.o Cell.o getChar.o
	$(compiler) -ggdb -o worm main.o game.o ScreenImage.o WormBody.o Cell.o getChar.o -lncurses

main.o: main.cpp game.hpp ScreenImage.hpp Cell.hpp WormBody.hpp
	$(compiler) -ggdb -c main.cpp

ScreenImageImage.o: ScreenImage.hpp ScreenImage.cpp Cell.hpp WormBody.hpp
	$(compiler) -ggdb -c ScreenImage.cpp -lncurses

WormBody.o: WormBody.hpp WormBody.cpp Cell.hpp
	$(compiler) -ggdb -c WormBody.cpp

game.o: game.hpp game.cpp WormBody.hpp ScreenImage.hpp Cell.hpp
	$(compiler) -ggdb -c game.cpp

Cell.o: Cell.hpp Cell.cpp
	$(compiler) -ggdb -c Cell.cpp

getChar.o: getChar.cpp
	$(compiler) -ggdb -c getChar.cpp

clean:
	rm *.o worm
	# rm ./bin/worm
	# rmdir bin

# install:
	# mkdir ./bin
	# cp worm ./bin/worm

backup:
	cp * ~/backupWorm/

// Matt Carrier
// CS 315
// Worm
// game.hpp

#include "ScreenImage.hpp"
#include "WormBody.hpp"

class Game {

public:

  Game(); // play new instance of the game
  // also sets itms to the default
  ~Game(); // clean up the memory

  //isAlive() // returns false if the worm is dead
  //newGame(); // create a new game using score from last

private:

  ScreenImage * screen;
  WormBody * worm;
  
  int score;
  bool quit;
  // drawing class?
  // input class?

};

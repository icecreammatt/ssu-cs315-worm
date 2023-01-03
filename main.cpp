// Matt Carrier
// CS 315
// Worm
// main.cpp

#include "Cell.hpp"
#include "ScreenImage.hpp"
#include "WormBody.hpp"
#include "prototypes.hpp"
#include <curses.h>
#include <iostream>

using namespace std;

void startup();
void endCurses();

bool logic(ScreenImage *screen, WormBody *worm, char moveDir, int &score,
           bool &munchieFound);

int main() {
  startup();

  // Game game
  WormBody *worm;
  ScreenImage *screen;

  worm = new WormBody(14, 2, 1);
  screen = new ScreenImage(24, 80, worm);

  mvaddstr(0, 1, "Worm");
  refresh();

  int score = 0;
  bool quit = false;
  char moveDir = 'l';
  bool munchieFound = true;

  while (quit == false) {
    // get input
    moveDir = get_char();
    if (moveDir == ' ') {
      moveDir = 'l';
    }

    // run logic (returns quit)
    quit = logic(screen, worm, moveDir, score, munchieFound);
  }

  endCurses();

  cout << "Your final score was:" << score << endl;
  // screen->printB();
  return 0;
}

void startup() {
  initscr();
  clear();
  noecho();
  cbreak();
  curs_set(0);
}

void endCurses() {
  mvcur(0, COLS - 1, LINES - 1, 0);
  clear();
  refresh();
  endwin();
}

bool logic(ScreenImage *screen, WormBody *worm, char moveDir, int &score,
           bool &munchieFound) {

  bool gameOver = false;
  // Cell head ( &(worm->getHead()) );
  // Cell head ( worm->getHead() );

  Cell head;
  head = worm->getHead();

  int row = head.getRow();
  int col = head.getColumn();

  //  cout << row << " " << col << endl;

  // README
  if (moveDir == 'w' || moveDir == 'i') {
    head.setLocation(row - 1, col);
  } else if (moveDir == 's' || moveDir == 'k') {
    head.setLocation(row + 1, col);
  } else if (moveDir == 'a' || moveDir == 'j') {
    head.setLocation(row, col - 1);
  } else if (moveDir == 'd' || moveDir == 'l') {
    head.setLocation(row, col + 1);
  }
  //  cout << head.getRow() << " " << head.getColumn() << endl;

  worm->addNewHead(head);

  if (screen->isAMunchieCell(head)) {
    munchieFound = true;
    // std::cout << "INCREASE\n";

    //      Cell munchie;
    //      munchie = screen->getMunchie();
    //      int row = munchie.getRow();
    //      int col = munchie.getColumn();

    worm->increaseLength(screen->getMunchieSize());
    score += screen->getMunchieSize();
    mvaddstr(0, 70, "Score: ");
    mvprintw(0, 76, "%i", score);
    refresh();

    // worm->increaseLength ( screen[ munchie.getRow(), munchie.getColumn() ] );
  }

  if (!(screen->makeWormCell(head))) {
    gameOver = true;
  }

  // this reduces the length of the number of cells to add.
  if (worm->getLength() > 0) {
    // std::cout << "reducing length\n";
    worm->reduceLength();
  }

  if (worm->getLength() == 0) {
    // if isAMunchie returns a number
    // increase worm by this length
    worm->removeTail();

    Cell tail;
    tail = worm->getTail();
    row = tail.getRow();
    col = tail.getColumn();
    screen->makeVacantCell(row, col);
  }

  if (munchieFound) {
    // this bit is causing segfault
    screen->makeMunchieCell();
    munchieFound = false;
  }
  // get tail and then pass it to makeVacant
  // update screen make vacant

  // Cell tail ( worm->getTail() );
  // screen->makeVacantCell( tail.getRow(), tail.getColumn() );

  /*
    Take the input and move the worm in the correct direction
    - handle moving the worm in the screen
    - handle updating free pool
    - handle updating worm's array
    - check for collision
    - insert munchie
    - update score
    - check for quit or death
  */

  // return true for quit or death
  // else return false

  if (moveDir == 'q' || gameOver == true)
    return true;

  return false;
}

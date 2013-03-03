#ifndef _WORMBODY
#define _WORMBODY

#include "Cell.hpp"
#include <list>
#include <iostream>

const int MAX_WORM_LEN = 1920;

class WormBody  {

public:
    WormBody( int initRow, int initCol, int initLength );
    
    /**
       Make "oneCell" to become the new head cell of the worm
     */
    void addNewHead( Cell oneCell );
    
    /**
       Return the cell that represents the head cell of the worm.
     */
    Cell getHead();

    /**
       Return the cell that represents the tail cell of the worm.
     */
    Cell getTail();

  void  increaseLength( int newlength );
    /**
       Remove the cell that represents the tail of the worm.
     */
    void removeTail();
    void print();

  int getLength() { return length; }
  void reduceLength();
  //Cell getWormArray() { return worm; }

private:

  Cell worm[MAX_WORM_LEN];
  //std::list <Cell> wormB;
  int head, tail;
  int length;
};

#endif

#ifndef _SCREENIMAGE
#define _SCREENIMAGE

#include "Cell.hpp"
#include "WormBody.hpp"
#include <curses.h>
#include <cstdlib>
#include <ctime>

#include <iostream>

const int MAX_ROWS = 24;
const int MAX_COLUMNS = 80;
const int MAX_FREEPOOL_SIZE = MAX_ROWS * MAX_COLUMNS;


class ScreenImage {

public: 
    ScreenImage( int rows, int cols,  WormBody *worm );

    /**
       The cell represented by (row, col) will become a vacant cell.
       Of course the cell can not already be a vacant cell.
     */
    void makeVacantCell( int row, int col );

    /**
       Returns true if the cell represented by (row, col) represents a
       wall cell.
    */
    bool isAWallCell( int row, int col );

    /**
       Returns true if the cell represented by (row, col) represents a
       cacant cell.
    */
    bool isAVacantCell( int row, int col );

    /**
       Returns true if the cell represented by (row, col) represents a
       worm cell.
    */
    bool isAWormCell( int row, int col );
    /**
       Make the VACANT cell represented by (row, col) to represent a
       worm cell.
    */
  bool makeWormCell( int row, int col );

    /**
       Make the VACANT cell represented by the argument cell to
       represent a worm cell.
    */
    bool makeWormCell( Cell &cell );

    /**
       Returns true if the cell represented by (row, col) represents a
       munchie cell.
    */
  bool isAMunchieCell( Cell &head );
  bool isAMunchieCell( int row, int col );

    /**
       Choose a vacant cell, turn it into a munchie cell and return a
       munchie cell with matching (row, column) pair.
    */
  Cell makeMunchieCell(); // should print munchie in this function
    
    /**
       Initially, we set all cells in on the screen to UNUSED.  Then
       we turn them into wall, worm, vacant, or munchie cells.
     */
    bool isUnused( int row, int col );

    /**
       Make the cell that is represented by (row, col) into a wall
       cell.  If the cell is already vacant, remove it from the
       vacantPool. 
     */
    void makeWallCell( int row, int col );

  //    void print();
  void printB();

  Cell getMunchie() { return munchie; }
  int getMunchieSize();

private: 
  int screen[MAX_ROWS][MAX_COLUMNS];
  Cell freePool[MAX_FREEPOOL_SIZE];
  int freePoolIdx;
  Cell munchie;

  int rows;
  int cols;
};

#endif

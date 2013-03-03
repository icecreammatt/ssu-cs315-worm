#ifndef _CELL
#define _CELL

#include <iostream>
#include <curses.h>
#include <iostream>

class Cell {
public: 
  Cell () : row(0), column(0) {}
  Cell( Cell & cell );
  Cell( int row, int column );
  //  Cell( const Cell &cell );
  //Cell( Cell cell );


  //Cell ( const Cell& Cell );
  void setLocation( int row, int column );
  int getRow();
  int getColumn();
  void print(char c);
    //        std::cout << "Row = " <<  getRow() <<  "  Column = " <<  getColumn() <<  
    //" ( x = " <<  getX() <<  ", y = " <<  getY();
  //  }

private: 
  int row, column;
};

#endif

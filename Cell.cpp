#include "Cell.hpp"

Cell::Cell(int row, int column) {
  this->row = row;
  this->column = column;
}

Cell::Cell(Cell &cell) {
  row = cell.getRow();
  column = cell.getColumn();
}

/*
Cell::Cell( Cell cell )
{
  row = cell.getRow();
  column = cell.getColumn();
}
*/

void Cell::setLocation(int row, int column) {
  //  std::cout << "setLocation R:" << row << std::endl;
  //  std::cout << "setLocation C:" << column << std::endl;
  this->row = row;
  this->column = column;
}

int Cell::getRow() { return row; }

int Cell::getColumn() { return column; }

void Cell::print(char c) {
  // std::cout << row << " " << column << std::endl;
  //   mvaddch( row, column, c);
}

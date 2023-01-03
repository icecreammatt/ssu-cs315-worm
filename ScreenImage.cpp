#include "ScreenImage.hpp"

ScreenImage::ScreenImage( int rows, int cols,  WormBody *worm )
{
  this->rows = rows;
  this->cols = cols;

  int count = 0;

  // preload the grid with free spots
  freePoolIdx = 0;
  for( int y = 1; y < rows; y++ ) {
      for( int x = 0; x < cols; x++ ) {
    	  if(y == 1 || y == rows-1) {
  	      screen[y][x] = -1;
  	      mvaddch( y, x, '#' );
  	    } else if(x == 0 || x == cols-1) {
  	      screen[y][x] = -1;
  	      mvaddch( y, x, '#' );
  	    } else {
  	      screen[y][x] = freePoolIdx; // set 1,1 = last idx
  	      //count++;
  	      Cell temp( y, x );
  	      freePool[freePoolIdx] = temp; //set free pool idx = screen x,y

  	      freePoolIdx++; // increment freePoolIdx
  	    }
    	}
  }
  refresh();

  // LOOK AT ME
  // adjust free pool for worm
  

  // LOOK AT worm array and and find all of the existing cells
  // then take these and create worm cells using the screen make worm cell class
  // that way the screen is up to date.

}

void ScreenImage::makeVacantCell( int row, int col )
{
  screen[row][col] = freePoolIdx;
  freePoolIdx++;

}

bool ScreenImage::isAWallCell( int row, int col )
{
  if(screen[row][col] == -1)
    return true;
  else
    return false;
}

bool ScreenImage::isAVacantCell( int row, int col )
{
  if(screen[row][col] != -1)
    return true;
  else
    return false;
}

bool ScreenImage::isAWormCell( int row, int col )
{
  if(screen[row][col] == -1)
    return true;
  else
    return false;
}

bool ScreenImage::makeWormCell( int row, int col )
{
  
  // check for collisions here
  if( screen[row][col] == -1 )
    {
      //std::cout << "gameOver";
      return false;
    }
  //if( isAMunchieCell( row, col ) ) // this needs to be fixed
  //std::cout << "increase length";
  
  screen[row][col] = -1; // update screen with worm location
  freePool[ (screen[row][col]) ] = freePool[(freePoolIdx -1)];
  freePoolIdx--;
  return true;
}

bool ScreenImage::makeWormCell( Cell &cell )
{
  int row = cell.getRow();
  int col = cell.getColumn();
  //std::cout << "makeWormCell r:" << row << "makeWormCell c:" << col << std::endl;
  return makeWormCell( row, col );
}

bool ScreenImage::isAMunchieCell( Cell &head )
//bool ScreenImage::isAMunchieCell( int row, int col )
{
  if( head.getRow() == munchie.getRow() && head.getColumn() == munchie.getColumn() )
    return true;
  else
    return false;

}

bool ScreenImage::isAMunchieCell( int row, int col )
{
  if( munchie.getRow() == row && munchie.getColumn() == col )
    return true;
  else
    return false;
}

// this returns a type cell what do i use it for?
void ScreenImage::makeMunchieCell()
{

  //srand( getpid() );
  srand( time(NULL) );
  int random = rand() % freePoolIdx;  

  Cell randCell = freePool[random];

  munchie = randCell;

  int row = randCell.getRow();
  int col = randCell.getColumn();


  int randMunchie = (rand() % 9) + 1;

  screen[row][col] = randMunchie; // random value between 0-9
  //  mvaddch( row, col, '4' );
  mvprintw( row, col, "%i", randMunchie );

  // find random number between 0 and freePoolIdx
  // place munchie in this cell.
  // match this random with the location of the free pool and use
  // that spot to move to the screen location.

  // Cell munchie;
  // munchie.setLocation( row, col );
}

int ScreenImage::getMunchieSize()
{
  int row = munchie.getRow();
  int col = munchie.getColumn();

  return screen[row][col];
}


bool ScreenImage::isUnused( int row, int col ) { return false; }
void ScreenImage::makeWallCell( int row, int col ) {}
/*
void ScreenImage::print()
{
  move( 0, 0);
  /*    for(int y = 0; y < rows; y++)
      for( int x = 0; x < cols; x++){
	mvaddch( y, x, '*');
      }
  
  refresh();
}
*/

void ScreenImage::printB()
{
  std::cout << "freePoolIdx " << freePoolIdx << std::endl;
  std::cout << "cols: " << cols << " rows: " << rows << std::endl;
  
  for(int y = 0; y < rows; y++){
      for( int x = 0; x < cols; x++){
	std::cout << screen[y][x] << " ";
      }
      std::cout << '\n';
  }
  //  for( int i = 0; i < freePoolIdx; i++ )
    //freePool[i].print();
}



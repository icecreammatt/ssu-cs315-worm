#include "WormBody.hpp"

WormBody::WormBody(int initRow, int initCol, int initLength) {
  length = head = tail = 0;

  // ADD TO FREE POOL

  // make a init variable - 1 if i keep it this way READ ME

  //  Cell wormHead( initRow, initCol + initLength-1 ); // this will be the head
  // wormB.push_back(wormHead);
  //  Cell wormHead( initRow, initCol );
  // addNewHead( wormHead );

  for (int i = 0; i < initLength; i++) {
    Cell body(initRow, initCol + i); // this will be the body
    addNewHead(body);
  }

  // print here too
}

void WormBody::addNewHead(Cell oneCell) {

  Cell oldHead(worm[head - 1]);

  mvaddch(oldHead.getRow(), oldHead.getColumn(), 'o');

  worm[head] = oneCell;

  head++;
  if (head >= MAX_WORM_LEN)
    head = 0;

  mvaddch(oneCell.getRow(), oneCell.getColumn(), '@');
  refresh();
  // make old head old
  // make new head an @
}

Cell WormBody::getHead() {
  // std::cout << worm[head].getRow() << " " << worm[head].getColumn() ;
  return worm[head - 1];
}

Cell WormBody::getTail() { return worm[tail]; }

void WormBody::removeTail() {
  mvaddch(worm[tail].getRow(), worm[tail].getColumn(), ' ');
  refresh();

  // dont remove the tail if the length has increased
  // check if the length of the worm is == to the length of the tail -1
  tail++;
  if (tail >= MAX_WORM_LEN)
    tail = 0;
}

void WormBody::increaseLength(int newlength) { length = newlength; }

void WormBody::reduceLength() { length--; }

/*
void WormBody::print()
{
  //  for ( int i = tail; i < head; i++ )


 /*
  //print head and then tail
  for(int i = 0; i < wormB.size(); i++)
    {
      //std::cout << " " << std::endl;
      //if(wormB[i] == head)
        //wormB[i].print('@');
      //else
        //wormB[i].print('o');
    }
  refresh();
  */
//}
//*/

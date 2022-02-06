#include "Coordinate.h"

#ifndef BLOCK_H_
#define BLOCK_H_

class Block {
public:
  Block(Coordinate);
  Coordinate get_center();
  void paint();
private:
  Coordinate *coordinates;
};

#endif
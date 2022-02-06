#include <iostream>
#include "Block.h"
#include "gfx.h"

Block::Block(Coordinate c) {
  coordinates = (Coordinate *) malloc(4 * sizeof(Coordinate));
  coordinates[0] = Coordinate(c.get_x()-1, c.get_y());
  coordinates[1] = Coordinate(c.get_x(), c.get_y());
  coordinates[2] = Coordinate(c.get_x()-1, c.get_y()+1);
  coordinates[3] = Coordinate(c.get_x(), c.get_y()+1);
}

Coordinate Block::get_center() {
  return coordinates[1];
}

void Block::paint() {
  for (int i = 0; i < 4; i++)
    gfx_point(coordinates[i].get_x(), coordinates[i].get_y());
}
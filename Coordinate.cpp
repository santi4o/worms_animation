#include "Coordinate.h"

Coordinate::Coordinate(int xp, int yp) : x(xp), y(yp) {}

int Coordinate::get_x() {
  return x;
}

int Coordinate::get_y() {
  return y;
}
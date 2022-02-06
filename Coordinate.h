#ifndef COORDINATE_H_
#define COORDINATE_H_

class Coordinate {
public:
  Coordinate(int, int);
  int get_x();
  int get_y();
private:
  int x;
  int y;
};

#endif
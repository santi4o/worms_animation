#include "Block.h"
#include <queue>

#define WIDTH 500
#define HEIGHT WIDTH
#define WORM_LENGTH 10

using namespace std;

#ifndef WORM_H_
#define WORM_H_

class Worm {
public:
  Worm(Coordinate);
  void turn(double);
  bool go_forward();
  void paint();
private:
  queue <Block> body;
  double direction;
};

#endif
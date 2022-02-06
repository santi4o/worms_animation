#include <math.h>
#include "Worm.h"
#include <iostream>


Worm::Worm(Coordinate c) {
  body.push(Block(c));
  for(int i = 1; i < WORM_LENGTH; i++)
    body.push(Block(Coordinate(c.get_x()+i, c.get_y())));
}

void Worm::turn(double theta) {
  direction += theta;
  while (direction >= 6.2832)
    direction -= 6.2832;
}

bool Worm::go_forward() {
  bool border = false;
  double angle = -direction;
  Block head = body.back();
  int x = round(head.get_center().get_x() + 2*cos(angle));
  int y = round(head.get_center().get_y() + 2*sin(angle));
  if (x >= WIDTH) {
    x = WIDTH - 1;
    border = true;
  } else if (x <= 0) {
    x = 1;
    border = true;
  }
  if (y >= HEIGHT) {
    y = HEIGHT - 1;
    border = true;
  } else if (y <= 0) {
    y = 1;
    border = true;
  }
  body.push(Block(Coordinate(x,y)));
  body.pop();
  return border;
}

void Worm::paint() {
  queue <Block> blocks = body;
  while (!blocks.empty()) {
    blocks.front().paint();
    blocks.pop();
  }
}
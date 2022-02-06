#include "Worm.h"
#include <stdlib.h>

#ifndef WORMANIMATOR_H_
#define WORMANIMATOR_H_

class WormAnimator {
public:
  WormAnimator(Worm);
  void move_straight();
  void move_circular();
  void move_meandering();
  int get_type();
  int get_s_count();
  int get_c_count();
  double get_m_count();
  void change_type();
  void set_s_count(int);
  void set_c_count(int);
  void set_m_count(double);
  void change_radio();
  void change_dir();
  void change_dir_m();
  bool touched_border();
private:
  Worm worm;
  int type;
  int s_count;
  int c_count;
  double m_count;
  double circular_angle;
  bool border;
};

#endif
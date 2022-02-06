#include "WormAnimator.h"
#include <math.h>

WormAnimator::WormAnimator(Worm w) : worm(w) {
  s_count = 0;
  c_count = 0;
  m_count = 0;
  border = false;
  type = rand() % 3;
  double r = rand() / (double) (RAND_MAX);
  worm.turn(r * 3.1416 - 1.5708);
  circular_angle = (r * (1.0) - 0.5);
}

void WormAnimator::move_straight() {
  border = worm.go_forward();
  worm.paint();
  s_count++;
}

void WormAnimator::move_circular() {
  worm.turn(circular_angle);
  border = worm.go_forward();
  worm.paint();
  c_count++;
}

void WormAnimator::move_meandering() {
  if (sin(m_count) > 0.6)
    worm.turn(-0.3);
  else if (sin(m_count) < -0.6)
    worm.turn(0.3);
  border = worm.go_forward();
  worm.paint();
  m_count += 0.65;
}

int WormAnimator::get_type() {
  return type;
}

int WormAnimator::get_s_count() {
  return s_count;
}

int WormAnimator::get_c_count() {
  return c_count;
}

double WormAnimator::get_m_count() {
  return m_count;
}

void WormAnimator::change_type() {
  type = rand() % 3;
}

void WormAnimator::set_s_count(int s) {
  s_count = s;
}

void WormAnimator::set_c_count(int c) {
  c_count = c;
}

void WormAnimator::set_m_count(double m) {
  m_count = m;
}

void WormAnimator::change_radio() {
  double r = (double) rand() / (double) (RAND_MAX);
  circular_angle = (r - 0.5);
}

void WormAnimator::change_dir() {
  double r = rand() / (double) (RAND_MAX);
  worm.turn(r * 3.1416 - 1.5708);
}

void WormAnimator::change_dir_m() {
  double r = rand() / (double) (RAND_MAX);
  worm.turn(r * 3.1416 - 1);
}

bool WormAnimator::touched_border() {
  return border;
}
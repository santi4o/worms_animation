#include "AnimationManager.h"
#include <iostream>
#include <math.h>

using namespace std;

AnimationManager::AnimationManager(int nworms) {
  n = nworms;
  animators = (WormAnimator *) malloc(n * sizeof(WormAnimator));
  for (int i = 0; i < n; i++) {
    Worm worm(Coordinate(rand() % (WIDTH-WORM_LENGTH-1) + 1,
                         rand() % (HEIGHT-1) + 1));
    animators[i] = WormAnimator(worm);
  }
}

void AnimationManager::paint_frame() {
  for (int i = 0; i < n; i++) {
    switch (animators[i].get_type()) {
      case 0:
        animators[i].move_straight();
        if (animators[i].get_s_count() == 30) {
          animators[i].set_s_count(0);
          animators[i].change_type();
        }
        break;
      case 1:
        animators[i].move_circular();
        if (animators[i].get_c_count() == 50) {
          animators[i].set_c_count(0);
          animators[i].change_type();
          animators[i].change_radio();
        }
        break;
      case 2:
        animators[i].move_meandering();
        if (animators[i].get_m_count() >= 45) {
          animators[i].set_m_count(0);
          animators[i].change_type();
          animators[i].change_dir_m();
        }
        break;
      default:
        break;
    }
    if (animators[i].touched_border())
      animators[i].change_dir();
  }
}
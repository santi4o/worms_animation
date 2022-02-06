#include "WormAnimator.h"

#ifndef ANIMATIONMANAGER_H_
#define ANIMATIONMANAGER_H_

class AnimationManager {
public:
  AnimationManager(int);
  void paint_frame();
private:
  int n;
  WormAnimator *animators;
};

#endif
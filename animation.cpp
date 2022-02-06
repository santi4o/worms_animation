#include "AnimationManager.h"
#include "gfx.h"
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  if (argc != 2) {
    cout << "Forma de uso: " << argv[0] <<" NUMERO_DE_GUSANOS\n";
    exit(0);
  }
  gfx_open(WIDTH, HEIGHT, "Animaci_n de Gusanos");
  gfx_color(0,0,0);
  gfx_clear_color(255, 255, 255);
  gfx_clear();

  AnimationManager manager(atoi(argv[1]));

  while (true) {
    gfx_clear();
    manager.paint_frame();
    gfx_flush();
    usleep(25000);
    if (gfx_event_waiting()) {
      if (gfx_wait() == 'q') {
        break;
      }
    }
  }

  return 0;
}
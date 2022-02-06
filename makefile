#makefile
animation: animation.o gfx.o Coordinate.o Block.o Worm.o WormAnimator.o AnimationManager.o
	g++ gfx.o animation.o Coordinate.o Block.o Worm.o WormAnimator.o AnimationManager.o -o animation -lX11
animation.o: animation.cpp gfx.h AnimationManager.h Worm.h
	g++ animation.cpp -c
AnimationManager.o: AnimationManager.cpp AnimationManager.h WormAnimator.h Worm.h
	g++ AnimationManager.cpp -c
WormAnimator.o: WormAnimator.cpp WormAnimator.h Worm.h
	g++ WormAnimator.cpp -c
Worm.o: Worm.cpp Worm.h Block.h
	g++ Worm.cpp -c
Block.o: Block.cpp Block.h gfx.h Coordinate.h
	g++ Block.cpp -c
Coordinate.o: Coordinate.cpp Coordinate.h
	g++ Coordinate.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c
run:
	cd src; make
box2d:
	cd lzy; mkdir build; cd build; cmake ..; make
	cp lzy/build/Box2D/libBox2D.a src/include/




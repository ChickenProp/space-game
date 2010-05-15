#ifndef _WORLD_H
#define _WORLD_H

#include <vector>
#include "body.h"

typedef std::vector<Body*>::iterator bodyit_t;

class World {
public:
	World();

	void addBody(Body *newBody);
	std::vector<Body*> bodies;

	void update();
	void draw();
};

#endif

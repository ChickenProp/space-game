#include "world.h"

World::World() {
}

void World::addBody(Body *newBody) {
	bodies.push_back(newBody);
}

void World::update() {
	for (bodyit_t it = bodies.begin(); it != bodies.end(); it++) {
		if (*it == NULL)
			continue;
		(*it)->update();
	}
}

void World::draw() {
	for (bodyit_t it = bodies.begin(); it != bodies.end(); it++) {
		if (*it == NULL)
			continue;
		(*it)->draw();
	}
}

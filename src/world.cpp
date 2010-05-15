#include "world.h"
#include "globals.h"

sf::Image World::bgImage;

World::World() {
	bgImage.LoadFromFile("media/background.tga");
	bgSprite1 = sf::Sprite();
	bgSprite2 = sf::Sprite();
	bgSprite1.SetImage(bgImage);
	bgSprite2.SetImage(bgImage);
	bgSprite2.SetPosition(800, 0);
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

	bgSprite1.Move(-1, 0);
	bgSprite2.Move(-1, 0);
	if (bgSprite2.GetPosition().x <= 0) {
		bgSprite1.Move(800,0);
		bgSprite2.Move(800,0);
	}
}

void World::draw() {
	G::window.Draw(bgSprite1);
	G::window.Draw(bgSprite2);

	for (bodyit_t it = bodies.begin(); it != bodies.end(); it++) {
		if (*it == NULL)
			continue;
		(*it)->draw();
	}
}

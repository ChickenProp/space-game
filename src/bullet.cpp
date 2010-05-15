#include "bullet.h"
#include "globals.h"


bool Bullet::static_init = 0;
sf::Image Bullet::image;

Bullet::Bullet(b2Vec2 pos, float angle, b2Vec2 refVel) {
	if (!static_init) {
		static_init = 1;
		image.LoadFromFile("media/bullet.tga");
	}

	s.SetImage(image);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = pos;
	bodyDef.angle = angle;
	b = G::physics->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(0.115f, 0.025f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.0f;

	b->CreateFixture(&fixtureDef);
	b->SetLinearVelocity(bPolar(8, -angle) + refVel);
}

void Bullet::update() {}

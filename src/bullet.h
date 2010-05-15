#ifndef _BULLET_H
#define _BULLET_H

#include "body.h"

class Bullet : public Body {
public:
	Bullet(b2Vec2 position, float angle, b2Vec2 initialVelocity);

	static bool static_init;
	static sf::Image image;

	void update();
};

#endif

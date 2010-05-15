#ifndef _BULLET_H
#define _BULLET_H

#include "body.h"

class Bullet : public Body {
public:
	Bullet(sf::Vector2f position, sf::Vector2f velocity);

	void update();

	static bool static_init;
	static sf::Image image;
};

#endif

#ifndef _BODY_H
#define _BODY_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Body {
public:
	sf::Sprite s;
	b2Body *b;
	virtual void update();
};

#endif

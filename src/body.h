#ifndef _BODY_H
#define _BODY_H

#include <SFML/Graphics.hpp>

class Body {
public:
	sf::Sprite s;
	sf::Vector2f vel, acc;
	virtual void update();
};

#endif

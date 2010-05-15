#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
	Player();
	sf::Image image;
	sf::Sprite s;

	sf::Vector2f zeroVel;

	sf::Vector2f vel;
	sf::Vector2f acc;

	float screenLeft;

	void update();

	void accelerate(sf::Vector2f v);
};

#endif

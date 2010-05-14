#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
	Player();
	sf::Image image;
	sf::Sprite s;
	sf::Vector2f vel;

	void update();
};

#endif

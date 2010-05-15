#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include "body.h"

class Player : public Body {
public:
	Player();
	sf::Image image;

	sf::Vector2f zeroVel;

	float screenLeft;

	virtual void update();
	void draw();

	float fireDelay;
	sf::Clock shotClock;
	void setRateOfFire(float r);
	void tryToShoot();
	void shoot();
};

#endif

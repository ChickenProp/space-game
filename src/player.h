#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "body.h"

class Player : public Body {
public:
	Player();
	sf::Image image;

	virtual void update();

	float fireDelay;
	sf::Clock shotClock;
	void setRateOfFire(float r);
	void tryToShoot();
	void shoot();

	sf::SoundBuffer laserSoundBuffer;
	sf::Sound laserSound;
};

#endif

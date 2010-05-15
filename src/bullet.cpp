#include "bullet.h"


bool Bullet::static_init = 0;
sf::Image Bullet::image;
/*
Bullet::Bullet(sf::Vector2f pos, sf::Vector2f velocity) {
	if (!static_init) {
		static_init = 1;
		image.LoadFromFile("media/bullet.tga");
	}

	s.SetImage(image);
	s.SetPosition(pos);

	vel = velocity;
}

void Bullet::update() {
	s.Move(vel);
}
*/

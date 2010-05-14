#include "player.h"

Player::Player() {
	vel = sf::Vector2f(1, 0);
	image.LoadFromFile("media/player-ship.tga");
	s.SetImage(image);
	s.SetPosition(50, 208);
}

void Player::update() {
	s.Move(vel);
}


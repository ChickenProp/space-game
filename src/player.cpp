#include "player.h"
#include "globals.h"
#include "math.h"
#include "conf.h"

Player::Player() {
	zeroVel = sf::Vector2f(1, 0);
	vel = sf::Vector2f(0, 0);
	acc = sf::Vector2f(0, 0);
	image.LoadFromFile("media/player-ship.tga");

	s.SetImage(image);
	s.SetCenter((float)image.GetWidth()/2, (float)image.GetHeight()/2);
	s.SetPosition(50, 240);
	screenLeft = 0;
}

void Player::update() {
	screenLeft += 1;

	const sf::Input &in = G::window.GetInput();

	acc = sf::Vector2f(0,0);

	if (in.IsKeyDown(KEY_UP))
		acc += sf::Vector2f(0, -1);
	if (in.IsKeyDown(KEY_DOWN))
		acc += sf::Vector2f(0, 1);
	if (in.IsKeyDown(KEY_LEFT))
		acc += sf::Vector2f(-1, 0);
	if (in.IsKeyDown(KEY_RIGHT))
		acc += sf::Vector2f(1, 0);

	acc -= vel/10.0f;

	vel += acc;

	s.Move(vel + zeroVel);

	sf::Vector2f Gmouse(in.GetMouseX()+screenLeft, in.GetMouseY());
	sf::Vector2f mouse = Gmouse - s.GetPosition();

	s.SetRotation(-atan2(mouse.y, mouse.x) * 180.0f / M_PI);
}


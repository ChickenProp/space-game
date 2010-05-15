#include "player.h"
#include "globals.h"
#include "math.h"
#include "conf.h"

#if DVORAK
#  define KEY_UP sf::Key::Comma
#  define KEY_DOWN sf::Key::O
#  define KEY_LEFT sf::Key::A
#  define KEY_RIGHT sf::Key::E
#else
#  define KEY_UP sf::Key::W
#  define KEY_DOWN sf::Key::S
#  define KEY_LEFT sf::Key::A
#  define KEY_RIGHT sf::Key::D
#endif

Player::Player() {
	vel = sf::Vector2f(1, 0);
	image.LoadFromFile("media/player-ship.tga");
	s.SetImage(image);
	s.SetPosition(50, 208);
	s.SetCenter(32, 32);
	screenLeft = 0;
}

void Player::update() {
	screenLeft += 1;

	const sf::Input &in = G::window.GetInput();

	vel = sf::Vector2f(1, 0);

	if (in.IsKeyDown(KEY_UP))
		vel += sf::Vector2f(0, -1);
	if (in.IsKeyDown(KEY_DOWN))
		vel += sf::Vector2f(0, 1);
	if (in.IsKeyDown(KEY_LEFT))
		vel += sf::Vector2f(-1, 0);
	if (in.IsKeyDown(KEY_RIGHT))
		vel += sf::Vector2f(1, 0);

	s.Move(vel);

	sf::Vector2f Gmouse(in.GetMouseX()+screenLeft, in.GetMouseY());
	sf::Vector2f mouse = Gmouse - s.GetPosition();

	s.SetRotation(-atan2(mouse.y, mouse.x) * 180.0f / M_PI);
}


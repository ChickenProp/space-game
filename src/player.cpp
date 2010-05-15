#include "player.h"
#include "globals.h"
#include "math.h"
#include "conf.h"

Player::Player() {
	zeroVel = sf::Vector2f(1, 0);
	image.LoadFromFile("media/player-ship.tga");

	s.SetImage(image);
	s.SetCenter((float)image.GetWidth()/2, (float)image.GetHeight()/2);
	s.SetPosition(50, 240);
	screenLeft = 0;

	setRateOfFire(10);
	shotClock.Reset();

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.50f, 2.40f);
	b = G::physics->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.0f;

	b->CreateFixture(&fixtureDef);
	b->SetLinearDamping(4.0f);
}

void Player::update() {
	screenLeft += 1;

	const sf::Input &in = G::window.GetInput();

	b2Vec2 center = b->GetWorldCenter();

	float acc = 2.0f;

	if (in.IsKeyDown(KEY_UP))
		b->ApplyLinearImpulse(acc*b2Vec2(0, -1), center);
	if (in.IsKeyDown(KEY_DOWN))
		b->ApplyLinearImpulse(acc*b2Vec2(0, 1), center);
	if (in.IsKeyDown(KEY_LEFT))
		b->ApplyLinearImpulse(acc*b2Vec2(-1, 0), center);
	if (in.IsKeyDown(KEY_RIGHT))
		b->ApplyLinearImpulse(acc*b2Vec2(1, 0), center);

	sf::Vector2f Gmouse(in.GetMouseX()+screenLeft, in.GetMouseY());
	sf::Vector2f mouse = Gmouse - s.GetPosition();

	b->SetTransform(b->GetPosition(), -atan2(mouse.y, mouse.x));

	if (in.IsMouseButtonDown(sf::Mouse::Left))
		tryToShoot();
}

void Player::draw() {
	s.SetPosition(b2s( 100.0f * b->GetPosition() + b2Vec2(screenLeft, 0) ));
	s.SetRotation(r2d(b->GetAngle()));
	G::window.Draw(s);
}

void Player::setRateOfFire(float r) {
	fireDelay = 1.0f / r;
}

void Player::tryToShoot() {
	if (shotClock.GetElapsedTime() > fireDelay)
		shoot();
}

void Player::shoot() {
	shotClock.Reset();
	printf("shoot!\n");
}

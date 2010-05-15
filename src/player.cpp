#include "player.h"
#include "globals.h"
#include "math.h"
#include "conf.h"
#include "bullet.h"

Player::Player() {
	image.LoadFromFile("media/player-ship.tga");

	s.SetImage(image);
	s.SetCenter((float)image.GetWidth()/2, (float)image.GetHeight()/2);
	s.SetPosition(50, 240);

	setRateOfFire(5);
	shotClock.Reset();

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.50f, 2.40f);
	b = G::physics->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(0.27f, 0.09f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f / (0.27f * 0.09f);
	fixtureDef.friction = 0.0f;

	b->CreateFixture(&fixtureDef);
	b->SetLinearDamping(4.0f);

	laserSoundBuffer.LoadFromFile("media/player-shoot.wav");
	laserSound.SetBuffer(laserSoundBuffer);
	laserSound.SetVolume(25);
}

void Player::update() {
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

	sf::Vector2f Gmouse(in.GetMouseX(), in.GetMouseY());
	sf::Vector2f mouse = Gmouse - s.GetPosition();

	b->SetTransform(b->GetPosition(), -atan2(mouse.y, mouse.x));

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
	Bullet *bul = new Bullet(b->GetPosition() + bPolar(0.25, -b->GetAngle()),
	                         b->GetAngle(), b->GetLinearVelocity());
	G::world->addBody(bul);
	laserSound.Play();
}

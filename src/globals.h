#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "player.h"
#include "world.h"
#include "math.h"

class G {
public:
	static sf::RenderWindow window;
	static Player *player;
	static b2World *physics;
	static World *world;
};

inline float r2d (float r) {
	return r * 180.0f / M_PI;
}

inline sf::Vector2f b2s (b2Vec2 v) {
	return sf::Vector2f(v.x, v.y);
}

inline b2Vec2 bPolar(float r, float theta) {
	return r * b2Vec2(cos(theta), sin(theta));
}

inline b2Vec2 bRotate(b2Vec2 v, float theta) {
	float c = cos(theta);
	float s = sin(theta);
	return b2Vec2(c*v.x - s*v.y, s*v.x + c*v.y);
}

#endif

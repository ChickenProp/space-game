#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "player.h"
#include "math.h"

class G {
public:
	static sf::RenderWindow window;
	static Player *player;
	static b2World *physics;
};

inline float r2d (float r) {
	return r * 180.0f / M_PI;
}

inline sf::Vector2f b2s (b2Vec2 v) {
	return sf::Vector2f(v.x, v.y);
}

#endif

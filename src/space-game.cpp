#include <SFML/Graphics.hpp>
#include "globals.h"
#include "player.h"
#include "world.h"

void processEvent(sf::Event e) {
	switch (e.Type) {
	case sf::Event::Closed:
		G::window.Close();
		break;
	case sf::Event::KeyPressed:
		if (e.Key.Code == sf::Key::Escape)
			G::window.Close();
		break;
	}
}

int main (int argv, char **argc) {
	G::window.Create(sf::VideoMode(800, 480, 32), "Space shooter");
	G::window.SetFramerateLimit(60);
	G::window.SetCursorPosition(400, 240);

	G::physics = new b2World(b2Vec2(0,0), 1);
	G::player = new Player();
	G::world = new World();
	G::world->addBody(G::player);

	sf::View view(sf::FloatRect(0, 0, 800, 480));
	G::window.SetView(view);

	while (G::window.IsOpened()) {
		sf::Event ev;
		while (G::window.GetEvent(ev))
			processEvent(ev);

		if (!G::window.IsOpened())
			break;

		G::world->update();

		G::physics->Step(1.0f/60, 10, 10);

		G::window.Clear();

		G::world->draw();
		G::window.Display();
	}
}

#include <SFML/Graphics.hpp>
#include "globals.h"
#include "player.h"

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

	sf::View view(sf::FloatRect(0, 0, 800, 480));
	G::window.SetView(view);

	sf::Image bgImage;
	bgImage.LoadFromFile("media/background.tga");
	sf::Sprite bgSprite1;
	bgSprite1.SetImage(bgImage);
	sf::Sprite bgSprite2;
	bgSprite2.SetImage(bgImage);
	bgSprite2.SetPosition(800, 0);

	while (G::window.IsOpened()) {
		sf::Event ev;
		while (G::window.GetEvent(ev))
			processEvent(ev);

		if (!G::window.IsOpened())
			break;

		G::player.update();

		view.SetCenter(G::player.screenLeft + 400, 240);
		if (view.GetRect().Left >= bgSprite2.GetPosition().x) {
			bgSprite1.Move(800, 0);
			bgSprite2.Move(800, 0);
		}

		G::window.Clear();

		G::window.Draw(bgSprite1);
		G::window.Draw(bgSprite2);
		G::window.Draw(G::player.s);
		G::window.Display();
	}
}

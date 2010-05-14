#include <SFML/Graphics.hpp>
#include "player.h"

sf::RenderWindow window;
Player player;

void processEvent(sf::Event e) {
	switch (e.Type) {
	case sf::Event::Closed:
		window.Close();
		break;
	case sf::Event::KeyPressed:
		if (e.Key.Code == sf::Key::Escape)
			window.Close();
		break;
	}
}

int main (int argv, char **argc) {
	window.Create(sf::VideoMode(640, 480, 32), "Space shooter");

	sf::Image bgImage;
	bgImage.LoadFromFile("media/background.tga");
	sf::Sprite bgSprite;
	bgSprite.SetImage(bgImage);

	while (window.IsOpened()) {
		sf::Event ev;
		while (window.GetEvent(ev))
			processEvent(ev);

		if (!window.IsOpened())
			break;

		player.update();

		window.Draw(bgSprite);
		window.Draw(player.s);
		window.Display();
	}
}

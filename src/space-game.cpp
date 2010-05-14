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
	window.Create(sf::VideoMode(800, 480, 32), "Space shooter");
	window.SetFramerateLimit(60);

	sf::View view(sf::FloatRect(0, 0, 800, 480));
	window.SetView(view);

	sf::Image bgImage;
	bgImage.LoadFromFile("media/background.tga");
	sf::Sprite bgSprite1;
	bgSprite1.SetImage(bgImage);
	sf::Sprite bgSprite2;
	bgSprite2.SetImage(bgImage);
	bgSprite2.SetPosition(800, 0);

	while (window.IsOpened()) {
		sf::Event ev;
		while (window.GetEvent(ev))
			processEvent(ev);

		if (!window.IsOpened())
			break;

		player.update();

		view.SetCenter(player.s.GetPosition().x + 350, 240);
		if (view.GetRect().Left >= bgSprite2.GetPosition().x) {
			bgSprite1.Move(800, 0);
			bgSprite2.Move(800, 0);
		}

		window.Clear();

		window.Draw(bgSprite1);
		window.Draw(bgSprite2);
		window.Draw(player.s);
		window.Display();
	}
}

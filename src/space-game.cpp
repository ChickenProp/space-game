#include <SFML/Graphics.hpp>

sf::RenderWindow window;

void processEvent(sf::Event e) {
	switch (e.Type) {
	case sf::Event::Closed:
		window.Close();
		break;
	}
}

int main (int argv, char **argc) {
	window.Create(sf::VideoMode(640, 480, 32), "Space shooter");

	while (window.IsOpened()) {
		sf::Event ev;
		while (window.GetEvent(ev))
			processEvent(ev);

		if (!window.IsOpened())
			break;

		window.Display();
	}
}

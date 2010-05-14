#include <SFML/Graphics.hpp>

int main (int argv, char **argc) {
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Space shooter");
	while (1)
		window.Display();
}

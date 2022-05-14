#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "Game", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape scrimblo(sf::Vector2f(100.0f, 100.0f));
	sf::RectangleShape goat(sf::Vector2f(600.0f, 600.0f));
	sf::RectangleShape inventory(sf::Vector2f(600.0f, 600.0f));
	sf::RectangleShape item(sf::Vector2f(16.0f, 16.0f));

	//scrimblo.setFillColor(sf::Color::Cyan);
	scrimblo.setOrigin(50.0f, 50.0f);
	sf::Texture scrimbloTexture;
	sf::Texture screenTexture;
	sf::Texture inventoryTexture;
	sf::Texture itemTexture;
	scrimbloTexture.loadFromFile("trueWillowCustom.png");
	screenTexture.loadFromFile("gimp.png");
	inventoryTexture.loadFromFile("inventory.png");
	itemTexture.loadFromFile("theSkindex.png");
	goat.setTexture(&screenTexture);
	scrimblo.setTexture(&scrimbloTexture);
	inventory.setTexture(&inventoryTexture);
	item.setTexture(&itemTexture);
	sf::Vector2u textureSize = itemTexture.getSize();
	textureSize.x /= 3;
	Animation animation(&scrimbloTexture, sf::Vector2u(4, 1), 0.3f);

	float deltaTime;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//std::cout << "New window width: " << evnt.size.width << "New window height: " << evnt.size.height << std::endl;
				printf("New window width: %i New window height: %i\n", evnt.size.width, evnt.size.width);
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					printf("%c", evnt.text.unicode);
				}
				break;
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			scrimblo.move(-0.1f,0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			scrimblo.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			scrimblo.move(0.f, 0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			scrimblo.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)) {
			while (true) {
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
					break;
				}
				window.draw(inventory);
				int position = 2;
				for (int i = 0; i < 1; i++) {
					item.setTextureRect(sf::IntRect(textureSize.x * position, textureSize.y, textureSize.x, textureSize.y));
					item.setPosition(100.0f, 100.0f);
					window.draw(item);
					position++;
				}
				window.display();
			}
		}
		animation.Update(0, deltaTime);
		scrimblo.setTextureRect(animation.uvRect);
		window.clear();
		window.draw(goat);
		window.draw(scrimblo);
		window.display();
	}
	return 0;
}
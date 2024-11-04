#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include "DATA.hpp"

class TutorialMenu {
public:
	void init(sf::RenderWindow* window);
	void setup();
	bool used;

	void processInput();
	void render();
private:

	bool confirmButton;

	int screen;

	void initSource();

	sf::RenderWindow*			window;

	sf::Texture					backgroundTexture;
	sf::Sprite					backgroundSprite;

	sf::Texture					rightArrowButtonTexture;
	sf::Sprite					rightArrowButtonSprite;

	sf::Texture					leftArrowButtonTexture;
	sf::Sprite					leftArrowButtonSprite;

	sf::Texture					confirmButtonTexture;
	sf::Sprite					confirmButtonSprite;

	std::array<sf::Texture, 3>	exampleImageTexture;
	sf::Sprite					exampleImageSprite;


};
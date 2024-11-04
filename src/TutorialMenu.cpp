#include "TutorialMenu.hpp"

void TutorialMenu::init(sf::RenderWindow* window) {
	this->window = window;
	used = 0;
	confirmButton = false;
	screen = 0;
	setup();
	initSource();
}

void TutorialMenu::initSource() {

	backgroundTexture.loadFromFile("./assets/images/BackgroundTutorial.png");
	backgroundSprite.setTexture(backgroundTexture);

	rightArrowButtonTexture.loadFromFile("./assets/images/buttons/RightArrowButton.png");
	rightArrowButtonSprite.setTexture(rightArrowButtonTexture);

	leftArrowButtonTexture.loadFromFile("./assets/images/buttons/LeftArrowButton.png");
	leftArrowButtonSprite.setTexture(leftArrowButtonTexture);

	confirmButtonTexture.loadFromFile("./assets/images/buttons/ConfirmButton.png");
	confirmButtonSprite.setTexture(confirmButtonTexture);

	for (int i = 0; i < 3; i++)
		exampleImageTexture[i].loadFromFile("./assets/images/ExampleImage"+std::to_string(i) + ".png");
	exampleImageSprite.setTexture(exampleImageTexture[0]);
}


void TutorialMenu::setup() {

	backgroundSprite.setPosition(0, 300);
	backgroundSprite.setScale(0.4, 0.4);

	rightArrowButtonSprite.setPosition(1000, 500);
	rightArrowButtonSprite.setScale(0.2, 0.2);

	leftArrowButtonSprite.setPosition(350, 500);
	leftArrowButtonSprite.setScale(0.2, 0.2 );

	confirmButtonSprite.setPosition(WIDTH / 2, HEIGHT * 2 / 3);
	confirmButtonSprite.setScale(0.2 , 0.2);

	exampleImageSprite.setPosition(500, 500);
	exampleImageSprite.setScale(1, 1);
}

void TutorialMenu::processInput() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
				if (rightArrowButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					if (screen < 2)
						screen++;
					if (screen == 2) {
						confirmButton = true;
					}
					exampleImageSprite.setTexture(exampleImageTexture[screen]);
				}
				if (leftArrowButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					if (screen > 0)
						screen--;
					exampleImageSprite.setTexture(exampleImageTexture[screen]);
				}
				if (confirmButton && confirmButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					used = true;
				}
			}
		}
	}
}

void TutorialMenu::render() {
	window->draw(backgroundSprite);
	window->draw(leftArrowButtonSprite);
	window->draw(rightArrowButtonSprite);
	window->draw(exampleImageSprite);

	if (confirmButton) window->draw(confirmButtonSprite);

	window->display();
}
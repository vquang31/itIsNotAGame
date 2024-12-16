#include "TutorialMenu.hpp"

void TutorialMenu::init(sf::RenderWindow* window, SoundManager* s) {
	this->window = window;
	used = 0;
	confirmButton = false;
	screen = 0;
	soundManager = s;
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
		exampleImageTexture[i].loadFromFile("./assets/images/tutorial-"+std::to_string(i) + ".png");
	exampleImageSprite.setTexture(exampleImageTexture[0]);
}


void TutorialMenu::setup() {

	backgroundSprite.setPosition(0, 0);
	backgroundSprite.setScale(SCALE, SCALE);

	rightArrowButtonSprite.setPosition( window->getSize().x * 8 /10 , window->getSize().y * 1 / 2.7);
	rightArrowButtonSprite.setScale(SCALE, SCALE);

	leftArrowButtonSprite.setPosition(window->getSize().x * 1.4 / 9, window->getSize().y * 1 / 2.7);
	leftArrowButtonSprite.setScale(SCALE, SCALE);

	confirmButtonSprite.setPosition(window->getSize().x * 1.4 / 3 , window->getSize().y * 2.2 / 3);
	confirmButtonSprite.setScale(SCALE, SCALE);

	exampleImageSprite.setPosition(window->getSize().x * 1.15 / 5, window->getSize().y / 5);
	exampleImageSprite.setScale(SCALE * 0.35,  SCALE * 0.35);
}

void TutorialMenu::processInput() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				int sound = 1;
				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
				if (rightArrowButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					if (screen < 2)
						screen++;
					if (screen == 2) {
						confirmButton = true;
					}
					exampleImageSprite.setTexture(exampleImageTexture[screen]);
					sound = 2;
				}
				if (leftArrowButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					if (screen > 0)
						screen--;
					exampleImageSprite.setTexture(exampleImageTexture[screen]);
					sound = 2;
				}
				if (confirmButton && confirmButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					used = true;
					sound = 2;
				}
				soundManager->playSound(sound);
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
#include "EndGameMenu.hpp"

void EndGameMenu::init(sf::RenderWindow* window,sf::Font* font, SoundManager* s) {
	this->window = window;
	this->font = font;
	width = this->window->getSize().x;
	height = this->window->getSize().y;
	soundManager = s;
	initSource();
	setup_EndGameMenu();
}

int EndGameMenu::run(int curr,int setup, int start, sf::Time x) {
	playedTime = x;
	setupScreen = setup;
	startScreen = start;
	currentScreen = curr;

	int min = (int)playedTime.asSeconds() / 60;
	int second = (int)playedTime.asSeconds() % 60;
	std::string s = ((min < 10) ? "0" : "") + (std::to_string(min)) + ":" + ((second < 10) ? "0" : "") + (std::to_string(second));
	playedTimeText.setString(s);

	render_EndGameMenu();
	return processInput_EndGameMenu();
}

void EndGameMenu::initSource() {

	replayButtonTexture.loadFromFile("./assets/images/buttons/PlayButton.png");
	replayButtonSprite.setTexture(replayButtonTexture);

	exitButtonTexture.loadFromFile("./assets/images/buttons/ExitButton.png");
	exitButtonSprite.setTexture(exitButtonTexture);

}

void EndGameMenu::setup_EndGameMenu() {

	replayButtonSprite.setPosition(width / 2, height / 3);
	replayButtonSprite.setScale(SCALE, SCALE);

	exitButtonSprite.setPosition(width / 2, height / 2);
	exitButtonSprite.setScale(SCALE, SCALE);

	playedTimeText.setPosition(width / 3, 40);
	playedTimeText.setColor(sf::Color::White);
	playedTimeText.setOutlineColor(sf::Color::Black);
	playedTimeText.setOutlineThickness(2);
	playedTimeText.setFont(*font);

}


int	EndGameMenu::processInput_EndGameMenu() {

	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
				if (replayButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					return setupScreen;
				}
				if (exitButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					return startScreen;
				}
			}
		}
	}
	return currentScreen;
}

void EndGameMenu::render_EndGameMenu() {

	//window->draw(playedTimeText);
	window->draw(replayButtonSprite);
	window->draw(exitButtonSprite);

	window->display();
}
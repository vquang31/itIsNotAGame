#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class EndGameMenu {
public:
	sf::Font*				font;
	int						currentScreen;
	int						setupScreen;
	int						startScreen;
	void init(sf::RenderWindow* window, sf::Font* font);
	int run(int curr, int setupScreen, int startScreen
		, sf::Time x);
	void setup_EndGameMenu();

private:
	int						width;
	int						height;

	sf::RenderWindow*		window;

	sf::Time				playedTime;
	sf::Text				playedTimeText;

	sf::Texture				tableTexture;
	sf::Sprite				tableSprite;

	sf::Texture				replayButtonTexture;
	sf::Sprite				replayButtonSprite;
		
	sf::Texture				exitButtonTexture;
	sf::Sprite				exitButtonSprite;


	void initSource();

	

	int  processInput_EndGameMenu();
	void render_EndGameMenu();

};
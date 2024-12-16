#pragma once

#include "DataSetting.hpp"
#include "DATA.hpp"
#include "SoundManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>


class SettingMenu {
public:
	int							preScreen; // choseWindow
	int							currentScreen;
	void init(sf::RenderWindow& window, DataSetting* dataSetting, SoundManager* s);
	int	 run(int pre, int current);
	void setup_SettingMenu();
	void getData();
private:

	SoundManager*				soundManager;
	int							width;
	int							height;

	sf::RenderWindow*			window;
	DataSetting*				dataSetting;

	sf::Texture					xButtonTexture;
	sf::Sprite					xButtonSprite;

	sf::Texture					checkBoxFsTexture;
	sf::Sprite					checkBoxFsSprite;

	sf::Texture					tickVTexture;
	sf::Sprite					tickVSprite;

	sf::Texture					tableSettingTexture;
	sf::Sprite					tableSettingSprite;

	// dấu cộng 
	sf::Texture					plusButtonTexture;
	std::array<sf::Sprite, 3>	plusButtonSprite;
	// dấu trừ
	sf::Texture					minusButtonTexture;
	std::array<sf::Sprite, 3>	minusButtonSprite;
	// thanh volume
	sf::Texture					ratingVolumeTexture;
	std::array<sf::Sprite, 10>	ratingVolumeSprite[3];
	// hiển thị mức độ 
	sf::Texture					ratingXVolumeTexture;
	std::array<sf::Sprite, 10>	ratingXVolumeSprite[3];

	void setupData();
	void initSource();

	int processEvents_SettingMenu();
	void render_SettingMenu();

};
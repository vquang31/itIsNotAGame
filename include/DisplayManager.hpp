#pragma once

#include <SFML/Graphics.hpp>
#include"Game.hpp"
#include "DataSetting.hpp"
#include "SettingMenu.hpp"
#include "SoundManager.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <array>


class DisplayManager {
public:
    DisplayManager( const std::string& title);
    void run();
    void runMenu();
    void runGame();
    int                             choseWindow = 1;

    DataSetting*                    dataSetting = new DataSetting();
    SoundManager*                    soundManager = new SoundManager();

    //sf::SoundBuffer                 backgroundTrackBuffer;
    //sf::Sound                       backgroundTrackSound;

    Game game;

private:
    sf::RenderWindow* window;
    int width, height;


    void init();
    void initData();
    void initSource();

    // menu


    sf::Texture                     titleTexture;
    sf::Sprite                      titleSprite;

    sf::Texture                     openingTexture;
    sf::Sprite                      openingSprite;

    sf::Texture                     startButtonTexture;
    sf::Sprite                      startButtonSprite;
    sf::Texture                     settingButtonTexture;
    sf::Sprite                      settingButtonSprite;
    sf::Texture                     exitButtonTexture;
    sf::Sprite                      exitButtonSprite;


    void setup_Menu();
    void render_Menu();
    void processEvents_Menu();


    // SettingMenu
    SettingMenu*                    settingMenu = new SettingMenu();
    void updateFullscreen();
    void updateVolume();


    // PreGame

    // ảnh 


    // setupGame

    // inGame

};




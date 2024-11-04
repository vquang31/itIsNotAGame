#include "DisplayManager.hpp"
#include <iostream>


DisplayManager::DisplayManager(const std::string& title)
    : window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), title)), // Khởi tạo con trỏ window
    width(WIDTH),
    height(HEIGHT) {
    init();
    game.init(*window, dataSetting, settingMenu, soundManager);
}

void DisplayManager::init() {
    initData();
    settingMenu->init(*window, dataSetting);
    initSource();
}

void DisplayManager::initData() {

}

void DisplayManager::initSource() {

    // sound

    
    // menu
    playButtonTexture.loadFromFile("./assets/images/buttons/PlayButton.png");
    playButtonSprite.setTexture(playButtonTexture);

    exitButtonTexture.loadFromFile("./assets/images/buttons/ExitButton.png");
    exitButtonSprite.setTexture(exitButtonTexture);

    settingButtonTexture.loadFromFile("./assets/images/buttons/SettingButton.png");
    settingButtonSprite.setTexture(settingButtonTexture);

}

void DisplayManager::run() {
    setup_Menu();
    while (window->isOpen()) {
        if (choseWindow == 1) {
            runMenu();
        }
        if (choseWindow == 2) {
            runGame();
        }
    }
    soundManager->~SoundManager();
}

void DisplayManager::runMenu() {
    processEvents_Menu();

    // update
    while (window->isOpen() && choseWindow == 10) { //chuẩn 
        DataSetting tmp = *dataSetting;
        render_Menu();
        choseWindow = settingMenu->run(1 , 10); // 1 là previous Screen
        if (tmp.isFullscreen != dataSetting->isFullscreen) {
            updateFullscreen();
        }
        if (!(tmp == *dataSetting)) {
            updateVolume();
        }
    }

    render_Menu();
}

void DisplayManager::runGame() {
    game.run();
    choseWindow = 1; // khi exit
}

// setup

void DisplayManager::setup_Menu() {
    playButtonSprite.setPosition(width * 3 / 8, 0);
    playButtonSprite.setScale(0.4, 0.4);

    settingButtonSprite.setPosition(width * 3 / 8, height * 7 / 12);
    settingButtonSprite.setScale(0.4, 0.4);

    exitButtonSprite.setPosition(width * 3 / 8, height * 3 / 4);
    exitButtonSprite.setScale(0.4, 0.4);

}

void DisplayManager::render_Menu() {
    window->clear();
    window->draw(playButtonSprite);
    window->draw(settingButtonSprite);
    window->draw(exitButtonSprite);
    if (choseWindow != 10) // không bật setting
        window->display();
}

void DisplayManager::processEvents_Menu() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                if (playButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    choseWindow = 2;
                }
                if (settingButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    choseWindow = 10;
                }
                if (exitButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    window->close();
                }
            }
        }
    }
}


void DisplayManager::updateFullscreen() {
    if (dataSetting->isFullscreen)
    {
        window->create(sf::VideoMode(WIDTH, HEIGHT), "iTisNotAGame", sf::Style::Fullscreen);

    }
    else
    {
        window->create(sf::VideoMode(WIDTH, HEIGHT), "itIsNotAGame", sf::Style::Default);
        width = window->getSize().x;
        height = window->getSize().y;
    }
    setup_Menu();
    settingMenu->setup_SettingMenu();
}

void DisplayManager::updateVolume() {
    soundManager->updateVolume(*dataSetting);
}
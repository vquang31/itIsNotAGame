#include <SFML/Graphics.hpp>
#include "SettingMenu.hpp"
#include <iostream>

void SettingMenu::init(sf::RenderWindow& window, DataSetting* dataSetting) {
    this->window = &window;
    this->dataSetting = dataSetting;
    width = this->window->getSize().x;
    height = this->window->getSize().y;

    initSource();
    setup_SettingMenu();
    setupData(); // chua dung
}


int SettingMenu::run(int pre, int current) {
    preScreen = pre;
    currentScreen = current;
    render_SettingMenu();
    return processEvents_SettingMenu();
}

void SettingMenu::setupData() {

}

void SettingMenu::initSource() {
    xButtonTexture.loadFromFile("./assets/images/buttons/XButton.png");
    xButtonSprite.setTexture(xButtonTexture);

    checkBoxFsTexture.loadFromFile("./assets/images/buttons/checkBoxButton.png");
    checkBoxFsSprite.setTexture(checkBoxFsTexture);

    tickVTexture.loadFromFile("./assets/images/tickV.png");
    tickVSprite.setTexture(tickVTexture);

    tableSettingTexture.loadFromFile("./assets/images/TableSetting.png");
    tableSettingSprite.setTexture(tableSettingTexture);

    plusButtonTexture.loadFromFile("./assets/images/buttons/PlusButton.png");
    minusButtonTexture.loadFromFile("./assets/images/buttons/MinusButton.png");

    for (int i = 0; i < 3; i++) {
        plusButtonSprite[i].setTexture(plusButtonTexture);
        minusButtonSprite[i].setTexture(minusButtonTexture);
    }

    ratingVolumeTexture.loadFromFile("./assets/images/RatingVolume.png");
    ratingXVolumeTexture.loadFromFile("./assets/images/RatingXVolume.png");

    for (int i = 0; i < 3; i++) {
        for (int u = 0; u < 10; u++) {
            ratingVolumeSprite[i][u].setTexture(ratingVolumeTexture);
            ratingXVolumeSprite[i][u].setTexture(ratingXVolumeTexture);
        }
    }

}

void SettingMenu::setup_SettingMenu() {

    tableSettingSprite.setPosition(width / 12, height / 5);
    tableSettingSprite.setScale(1.3, 1);

    checkBoxFsSprite.setPosition(width / 6, height * 4 / 5);
    checkBoxFsSprite.setScale(0.3, 0.3);

    tickVSprite.setPosition(width / 6, height * 4 / 5);
    tickVSprite.setScale(0.3, 0.3);

    xButtonSprite.setPosition(width * 7 / 8, height * 3 / 10);
    xButtonSprite.setScale(0.3, 0.3);

    // thanh volume + dau cong + dau tru

    for (int i = 0; i < 3; i++) {
        plusButtonSprite[i].setPosition(width * 2 / 3, i * 100 + (height / 3));
        plusButtonSprite[i].setScale(0.1, 0.1);
        minusButtonSprite[i].setPosition(width * 1 / 3, i * 100 + (height / 3));
        minusButtonSprite[i].setScale(0.1, 0.1);
        for (int u = 0; u < 10; u++) {
            ratingVolumeSprite[i][u].setPosition(width * 1 / 3 + (u + 1) * 40, i * 100 + (height / 3));
            ratingVolumeSprite[i][u].setScale(0.1, 0.1);

            ratingXVolumeSprite[i][u].setPosition(width * 1 / 3 + (u + 1) * 40, i * 100 + (height / 3));
            ratingXVolumeSprite[i][u].setScale(0.1, 0.1);
        }
    }
}

void SettingMenu::render_SettingMenu() {

    window->draw(tableSettingSprite);
    window->draw(xButtonSprite);

    for (int i = 0; i < 3; i++) {
        window->draw(plusButtonSprite[i]);                  // +
        window->draw(minusButtonSprite[i]);                 // -
        for (int u = 0; u < 10; u++) {
            window->draw(ratingVolumeSprite[i][u]);
            int tmp;
            if (i == 0)         tmp = dataSetting->masterVolume / 10;
            else if (i == 1)    tmp = dataSetting->musicVolume / 10;
            else                tmp = dataSetting->SFXVolume / 10;
            if (u < tmp)
                window->draw(ratingXVolumeSprite[i][u]);
        }

    }

    window->draw(checkBoxFsSprite);
    if (dataSetting->isFullscreen)
        window->draw(tickVSprite);
    window->display();
}

int SettingMenu::processEvents_SettingMenu() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                if (xButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    return preScreen;    //choseWindow = pre;  // back
                }
                if (checkBoxFsSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    dataSetting->isFullscreen = dataSetting->isFullscreen ? 0 : 1;
                }
                /// xử lý âm thanh 
                for (int i = 0; i < 3; i++) {
                    if (plusButtonSprite[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        if (i == 0 && (dataSetting->masterVolume + 10) <= 100) 
                            dataSetting->increaseMasterVolume(1);
                        else if (i == 1 && (dataSetting->musicVolume + 10) <= 100)
                            dataSetting->increaseMusicVolume(1);
                        else if (i == 2 && (dataSetting->SFXVolume + 10) <= 100)
                            dataSetting->increaseSFXVolume(1);
                    }
                    if (minusButtonSprite[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        if (i == 0 && (dataSetting->masterVolume - 10) >= 0) 
                            dataSetting->increaseMasterVolume(-1);
                        else if (i == 1 && (dataSetting->musicVolume - 10) >= 0)
                            dataSetting->increaseMusicVolume(-1);
                        else if (i == 2 && (dataSetting->SFXVolume - 10) >= 0)
                            dataSetting->increaseSFXVolume(-1);
                    }
                }
            }
        }
    }
    return currentScreen;
}
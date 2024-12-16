#include "DisplayManager.hpp"
#include <iostream>


DisplayManager::DisplayManager(const std::string& title)
     // Khởi tạo con trỏ window 
 {
    sf::VideoMode  fullscreenMode = sf::VideoMode::getDesktopMode();
    width = fullscreenMode.width;
    height = fullscreenMode.height;
    window = new sf::RenderWindow(fullscreenMode, title, sf::Style::Fullscreen);
    init();
    game.init(*window, dataSetting, settingMenu, soundManager);
}

void DisplayManager::init() {
    initData();
    settingMenu->init(*window, dataSetting, soundManager);
    initSource();
}

void DisplayManager::initData() {

}

void DisplayManager::initSource() {

    // sound

    
    // menu


    titleTexture.loadFromFile("./assets/images/Title.png");
    titleSprite.setTexture(titleTexture);

    openingTexture.loadFromFile("./assets/images/Opening.png");
    openingSprite.setTexture(openingTexture); 

    startButtonTexture.loadFromFile("./assets/images/buttons/StartButton.png");
    startButtonSprite.setTexture(startButtonTexture);

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
        choseWindow = settingMenu->run( 1, 10); // 1 là previous Screen
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


    titleSprite.setPosition(width / 6 ,  height / 10);
    titleSprite.setScale(SCALE,SCALE);

    openingSprite.setPosition(0, 0);
    openingSprite.setScale((double)WIDTH / openingTexture.getSize().x * SCALE,
        (double)HEIGHT / openingTexture.getSize().y * SCALE);   // do ảnh có độ phân giải 1920 * 1080


    startButtonSprite.setPosition(width * 2.8 / 4, height * 4 / 12 );
    startButtonSprite.setScale(SCALE, SCALE);

    settingButtonSprite.setPosition(width * 2.8 / 4, height * 6 / 12);
    settingButtonSprite.setScale(SCALE, SCALE);

    exitButtonSprite.setPosition(width * 2.8 / 4, height * 8 / 12);
    exitButtonSprite.setScale( SCALE , SCALE );

    //startButtonSprite.setPosition(width * 3 / 8, 0);
    //startButtonSprite.setScale(0.4 * SCALE, 0.4 * SCALE);

    //settingButtonSprite.setPosition(width * 3 / 8, height * 7 / 12);
    //settingButtonSprite.setScale(0.4 * SCALE, 0.4 * SCALE);

    //exitButtonSprite.setPosition(width * 3 / 8, height * 3 / 4);
    //exitButtonSprite.setScale(0.4 * SCALE, 0.4 * SCALE);
}

void DisplayManager::render_Menu() {
    window->clear();

    window->draw(openingSprite);
    window->draw(titleSprite);
    window->draw(startButtonSprite);
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
                int click = 1;
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                if (startButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    click = 2;
                    choseWindow = 2;
                }
                if (settingButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    click = 2;
                    choseWindow = 10;
                }
                if (exitButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    window->close();
                }
                soundManager->playSound(click);
            }
        }
    }
}


void DisplayManager::updateFullscreen() {
    if (dataSetting->isFullscreen)
    {
        window->create(sf::VideoMode(width, height), "iTisNotAGame", sf::Style::Fullscreen);

    }
    else
    {
        window->create(sf::VideoMode(width, height), "itIsNotAGame", sf::Style::Default);
        width = window->getSize().x;
        height = window->getSize().y;
    }
    setup_Menu();
    settingMenu->setup_SettingMenu();
}

void DisplayManager::updateVolume() {
    soundManager->updateVolume(*dataSetting);
}
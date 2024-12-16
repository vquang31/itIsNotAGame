#include "Game.hpp"
#include <iostream>

void Game::init( sf::RenderWindow& window, DataSetting* dataSetting, SettingMenu* a, SoundManager* s) {
	this->window = &window; 
	this->dataSetting = dataSetting;
	this->settingMenu = a;
	this->soundManager = s;
	width = this->window->getSize().x;
	height = this->window->getSize().y;
	font->loadFromFile("./assets/fonts/Verona-SerialRegular.ttf");
	initData();
	initSource();
	setup_Game();
	player.setup(font);
	tutorialMenu->init(this->window,soundManager);
	endGameMenu->init(this->window, font, soundManager);
}

void Game::initData() {
	choseWindow = 0;
	minDeltaTime = sf::seconds(1.0f / MAX_FPS);
	player.pointerCast = 0;

	for (int i = 0; i < 4; i++) {
		quantityItemsText[i].setString("Quantity: " + std::to_string( player.inventory.getItemByIndex(i).getQuantity()));
	}

	for (int i = 0; i < FRAME_END_GAME_ANIMATION; i++) {
		endGameAnimationTime[i] = sf::milliseconds(i * (TIME_END_GAME_ANIMATION / FRAME_END_GAME_ANIMATION));
	}

	for (int i = 0; i < FRAME_SKY; i++) {
		skyTime[i] = sf::milliseconds(i * (TIME_SKY / FRAME_SKY));
	}

	beginPointsText.setString("Current point: " + std::to_string(player.beginPoints));
	playedTimeText.setString("00:00");
}

void Game::initSource() {
	// sound

	//normalCastSoundBuffer.loadFromFile("./assets/audio/bruh2.ogg");
	//normalCastSound.setBuffer(normalCastSoundBuffer);
	//normalCastSound.setVolume(dataSetting->SFXVolume * dataSetting->masterVolume / 100);

	// setupGame

	runInGameButtonTexture.loadFromFile("./assets/images/buttons/PlayButton.png");
	runInGameButtonSprite.setTexture(runInGameButtonTexture);

	tableSetupTexture.loadFromFile("./assets/images/TableSetup.png");
	tableSetupSprite.setTexture(tableSetupTexture);

	getItemButtonTexture.loadFromFile("./assets/images/buttons/GetItemButton.png");
	getItemButtonSprite.setTexture(getItemButtonTexture);

	resetItemButtonTexture.loadFromFile("./assets/images/buttons/ResetButton.png");
	resetItemButtonSprite.setTexture(resetItemButtonTexture); 


	// UI 	
	

	// Enemy Texture

	// background

	//for (int i = 0; i < FRAME_SKY; i++) {
	//	sf::Texture tmp;		
	//	tmp.loadFromFile("./assets/images/animation/skyAnimation/"+ (std::to_string(5*i+1))+".png");
	//	skyTexture.push_back(tmp);
	//}
	//skySprite.setTexture(skyTexture[0]);

	HPTexture.loadFromFile("./assets/images/Heart.png");
	emptyHPTexture.loadFromFile("./assets/images/EmptyHeart.png");

	for (int i = 0; i < 3; i++) {
		HPSprite[i].setTexture(HPTexture);
	}


	backgroundTexture.loadFromFile("./assets/images/background_inGame/Background.png");
	backgroundSprite.setTexture(backgroundTexture);

	treeBackgroundTexture.loadFromFile("./assets/images/background_inGame/TreeBackground.png");
	treeBackgroundSprite.setTexture(treeBackgroundTexture);


	// table

	mainTableTexture.loadFromFile("./assets/images/MainTable.png");
	mainTableSprite.setTexture(mainTableTexture);


	// layer cast

	layerCastTexture.loadFromFile("./assets/images/LayerCast.png");
	
	castButtonTexture.loadFromFile("./assets/images/buttons/CastButton.png");
	castButtonSprite.setTexture(castButtonTexture);

	elementCastTexture[0].loadFromFile("./assets/images/FireElement.png"); // sau phải sửa lại ảnh này 
	elementCastTexture[1].loadFromFile("./assets/images/WaterElement.png");
	elementCastTexture[2].loadFromFile("./assets/images/EarthElement.png");

	elementTexture[0].loadFromFile("./assets/images/FireElement.png");
	elementTexture[1].loadFromFile("./assets/images/WaterElement.png");
	elementTexture[2].loadFromFile("./assets/images/EarthElement.png");

	for (int i = 0; i < 3; i++) {
		layerCastSprite[i].setTexture(layerCastTexture);
		elementSprite[i].setTexture(elementTexture[i]);
	}
	// slider Stress

	borderStressTexture.loadFromFile("./assets/images/BorderStress.png");
	borderStressSprite.setTexture(borderStressTexture);

	sliderStressTexture.loadFromFile("./assets/images/SliderStress.png");
	sliderStressSprite.setTexture(sliderStressTexture);

	// PauseButton

	pauseButtonTexture.loadFromFile("./assets/images/buttons/PauseButton.png");
	pauseButtonSprite.setTexture(pauseButtonTexture);

	// Inventorty
	inventoryButtonTexture.loadFromFile("./assets/images/buttons/InventoryButton.png");
	inventoryButtonSprite.setTexture(inventoryButtonTexture);

	for (int i = 0; i < 4; i++) {
		itemTexture[i].loadFromFile("./assets/images/items/Item" + (std::to_string(i+1)) +".png");
		itemSprite[i].setTexture(itemTexture[i]);
	}

	tmpItemSprite.setTexture(itemTexture[0]);

	tableItemTexture.loadFromFile("./assets/images/TableItem.png"); /// inventory
	tableItemSprite.setTexture(tableItemTexture);

	xButtonTexture.loadFromFile("./assets/images/buttons/XButton.png");
	xButtonSprite.setTexture(xButtonTexture);

	useItemButtonTexture.loadFromFile("./assets/images/buttons/UseItemButton.png");
	useItemButtonSprite.setTexture(useItemButtonTexture);
	
	// pauseGame

	continueButtonTexture.loadFromFile("./assets/images/buttons/ContinueButton.png");
	continueButtonSprite.setTexture(continueButtonTexture);

	settingMenuButtonTexture.loadFromFile("./assets/images/buttons/SettingButton.png");
	settingMenuButtonSprite.setTexture(settingMenuButtonTexture);

	exitButtonTexture.loadFromFile("./assets/images/buttons/ExitButton.png");
	exitButtonSprite.setTexture(exitButtonTexture);

	// revive

	reviveButtonTexture.loadFromFile("./assets/images/buttons/ReviveButton.png");
	reviveButtonSprite.setTexture(reviveButtonTexture);

	//reviveTableTexture.loadFromFile("./assets/images/ReviveTable.png");
	//reviveTableSprite.setTexture(reviveTableTexture);

	// animation endGame
	 
	for (int i = 0; i < FRAME_END_GAME_ANIMATION; i++) {
		endGameAnimationTexture[i].loadFromFile("./assets/images/animation/endGameAnimation/EndGameAnimation"+(std::to_string(i)) + ".png");
	}
	endGameAnimationSprite.setTexture(endGameAnimationTexture[0]);


}

void Game::setup_Game() {

	// layout
	//////		SetupGame

	runInGameButtonSprite.setPosition(width / 4, height * 2 / 3);
	runInGameButtonSprite.setScale(SCALE, SCALE);

	tableSetupSprite.setPosition(0 ,0);
	tableSetupSprite.setScale(SCALE,SCALE);

	resetItemButtonSprite.setPosition(width * 3.7 /  5, height * 3.5 / 5);
	resetItemButtonSprite.setScale(SCALE, SCALE);

	getItemButtonSprite.setPosition(width * 4.2 / 5, height * 3.5 / 5);
	getItemButtonSprite.setScale(SCALE,SCALE);

	tmpItemSprite.setPosition(width * 9.5 / 12, height / 20 );
	tmpItemSprite.setScale(SCALE,SCALE);	

	for (int i = 0; i < 4; i++) {
		itemSprite[i].setPosition(width * 1.2 /  2, height / 6 + i * height / 6);
		itemSprite[i].setScale(0.45, 0.45);
	}

	// text
	for (int i = 0; i < 4; i++) {
		quantityItemsText[i].setPosition(width * 2.2 / 3, height * 2.8 / 5);
		quantityItemsText[i].setColor(sf::Color::White);
		quantityItemsText[i].setOutlineColor(sf::Color::Black);
		quantityItemsText[i].setOutlineThickness(2);
		quantityItemsText[i].setFont(*font);
		quantityItemsText[i].setCharacterSize(40);
	}

	scriptItemString[0] = "Slowwwwww \nMakeeee everyoneeee \nslowlyyy(-70%)\nCost: 3\nDuration: 4000";
	scriptItemString[1] = "Freezing\nMake everyone can't\nmove\nCost: 3\nDuration: 2000";
	scriptItemString[2] = "Explosion\nKILL EVERYTHING \n\nCost: 6";
	scriptItemString[3] = "Cure\nDon't STRESS\n\nCost: 2 ";

	for (int i = 0; i < 4; i++) {
		scriptItemText[i].setString(scriptItemString[i]);
		scriptItemText[i].setPosition(width * 2.2 / 3, height * 3 / 10);
		scriptItemText[i].setColor(sf::Color::White);
		scriptItemText[i].setOutlineColor(sf::Color::Black);      
		scriptItemText[i].setOutlineThickness(2);
		scriptItemText[i].setFont(*font);
		scriptItemText[i].setCharacterSize(45);
	}

	beginPointsText.setPosition(width * 2.3 / 3, height * 3.1 / 5);
	beginPointsText.setColor(sf::Color(255, 100, 50));
	beginPointsText.setFont(*font);
	beginPointsText.setCharacterSize(40);
	beginPointsText.setOutlineColor(sf::Color::Black);        // Đặt màu viền
	beginPointsText.setOutlineThickness(2);


	playedTimeText.setPosition(width / 2 - width / 50,  height / 40);
	playedTimeText.setColor(sf::Color::White);
	playedTimeText.setOutlineColor(sf::Color::Black);        // Đặt màu viền
	playedTimeText.setOutlineThickness(2);
	playedTimeText.setFont(*font);
	playedTimeText.setCharacterSize(35);

	//////		InGame
	
	//UI
	// background

	skySprite.setPosition(0,0); 
	skySprite.setScale(1,1);

	for (int i = 0; i < 3; i++) {
		HPSprite[i].setPosition( (i+1)* 50 ,50);
		HPSprite[i].setScale(0.05,0.05);
	}


	backgroundSprite.setPosition(0, 0);
	backgroundSprite.setScale(SCALE, SCALE);

	treeBackgroundSprite.setPosition(0, 0);
	treeBackgroundSprite.setScale(SCALE ,SCALE);

	// table
	mainTableSprite.setPosition(0, 0);
	mainTableSprite.setScale(SCALE, SCALE);
	 
	//layer Cast

	castButtonSprite.setPosition(width * 2.18/ 4, height * 3.2/ 4 );
	castButtonSprite.setScale(SCALE, SCALE);

	for (int i = 0; i < 3; i++) {
		layerCastSprite[i].setPosition(width / 3.05 + i * width / 14.2, height * 3.22 / 4 );
		layerCastSprite[i].setScale(SCALE, SCALE);

		elementSprite[i].setPosition(width / 3.05 + i * width / 20.5, height * 10.1 / 11);
		elementSprite[i].setScale(SCALE * 0.6 , SCALE * 0.6) ;

	}

	// slider Stress

	borderStressSprite.setPosition(width * 1.5 / 5, height *  2.1 / 3);
	borderStressSprite.setScale(SCALE, SCALE);

	sliderStressSprite.setPosition(width * 1.5 / 5, height * 2.1 / 3);
	sliderStressSprite.setScale(SCALE, SCALE);
	sliderStressSprite.setTextureRect(sf::IntRect(0, 0, 0
		, sliderStressTexture.getSize().y));

	// pauseButton

	pauseButtonSprite.setPosition(width * 7 / 8 , height / 24 );
	pauseButtonSprite.setScale(SCALE, SCALE);

	// inventory

	inventoryButtonSprite.setPosition(width * 7 /9 , height * 8 / 9);
	inventoryButtonSprite.setScale(SCALE, SCALE);

	tableItemSprite.setPosition(0,0);
	tableItemSprite.setScale(SCALE, SCALE);

	xButtonSprite.setPosition(width * 3 / 4, height / 5);
	xButtonSprite.setScale(SCALE,SCALE);

	useItemButtonSprite.setPosition(width * 2.2 /4 , height * 3.2 / 5);
	useItemButtonSprite.setScale(SCALE, SCALE);

	// pauseGame

	continueButtonSprite.setPosition(width / 1.5 , height / 14 + height * 2 /12);
	continueButtonSprite.setScale(SCALE, SCALE);

	settingMenuButtonSprite.setPosition(width / 1.5, height / 14 + height * 4 / 12);
	settingMenuButtonSprite.setScale(SCALE, SCALE);

	exitButtonSprite.setPosition(width / 1.5, height / 14 + height * 6 / 12);
	exitButtonSprite.setScale(SCALE, SCALE);

	// revive

	reviveButtonSprite.setPosition(width / 2.2 , height / 2.2);
	reviveButtonSprite.setScale(SCALE, SCALE);

	reviveTableSprite.setPosition(width / 2.5, height / 2.5);
	reviveTableSprite.setScale(0, 0);

}

void Game::run() {
	resetDataGame();
	choseWindow = 0;
	lastFrameTime = clockRunGame.getElapsedTime();

	while (window->isOpen() && choseWindow != -1) {
		if (choseWindow == 0)
			runSetupGame();
		if (choseWindow == 4) {
			runTutorial();
		}
		if (choseWindow == 1) {
			runInGame();
		}
	}
	resetDataGame();
}

void Game::runSetupGame() {
	while (clockRunGame.getElapsedTime() - lastFrameTime < minDeltaTime);
	lastFrameTime = clockRunGame.getElapsedTime();	
	processInput_SetupGame();

	updateDataPerFrame_SetupGame();

	render_SetupGame();

}

void Game::runTutorial() {

	while (clockRunGame.getElapsedTime() - lastFrameTime < minDeltaTime);
	lastFrameTime = clockRunGame.getElapsedTime();	
	if (!tutorialMenu->used) {
		tutorialMenu->processInput();
		render_InGame();
		tutorialMenu->render();
	}
	if (tutorialMenu->used) {
		choseWindow = 1;
		playedClockPerFrame.restart();
		clockRunGame.restart();
		lastFrameTime = clockRunGame.getElapsedTime();

	}
}

void Game::runInGame() {
	while (clockRunGame.getElapsedTime() - lastFrameTime < minDeltaTime);
	lastFrameTime = clockRunGame.getElapsedTime();
	processInput_InGame(); //1

	// update played time
	playedTime = playedTime + playedClockPerFrame.getElapsedTime();

	// 10
	runPauseGame();
	// 11
	runInventory();
	// 2  or 3 
	eventPlayerDie();

	playedClockPerFrame.restart();


	updateDataPerFrame_InGame();

	render_InGame();
	//lastFrameTime = clockRunGame.getElapsedTime();	//3
}

void Game::runPauseGame() {
	while (window->isOpen() && choseWindow == 10) {
		while (clockRunGame.getElapsedTime() - lastFrameTime < minDeltaTime);
		lastFrameTime = clockRunGame.getElapsedTime();

		processInput_PauseGame();
		//  chosewindow == 100
		runSettingMenu();
		//
		render_PauseGame();
		//lastFrameTime = clockRunGame.getElapsedTime();
	}
}

// 100
void Game::runSettingMenu() {
	while (window->isOpen() && choseWindow == 100) {
		while (clockRunGame.getElapsedTime() - lastFrameTime < minDeltaTime);
		lastFrameTime = clockRunGame.getElapsedTime();	

		render_PauseGame();
		DataSetting tmp = *dataSetting;
		choseWindow = settingMenu->run(10 , 100);
		if (tmp.isFullscreen != dataSetting->isFullscreen) {
			updateFullscreen();
		}
		if (!(tmp == *dataSetting)) {
			updateVolume();
		}		
	}
}

// 11 inventory
void Game::runInventory() {
	setup_inventory();
	while (window->isOpen() && choseWindow == 11) {
		while (clockRunGame.getElapsedTime() - lastFrameTime < minDeltaTime);
		lastFrameTime = clockRunGame.getElapsedTime();		

		processInput_Inventory();
		//  update
		

		//
		render_Inventory();
	}
}

// 3
void Game::runEndGameMenu() {
	while (window->isOpen() && choseWindow == 3) {
		while (clockRunGame.getElapsedTime() - lastFrameTime < minDeltaTime);
		lastFrameTime = clockRunGame.getElapsedTime();		

		render_InGame();
		choseWindow = endGameMenu->run(3, 0, -1, playedTime);
		if (choseWindow != 3) resetDataGame();

	}
}

// 2

void Game::runReviveMenu() {
	xButtonSprite.setPosition(width  / 2 , height / 1.7);
	while (window->isOpen() && choseWindow == 2) {
		while (clockRunGame.getElapsedTime() - lastFrameTime < minDeltaTime);
			lastFrameTime = clockRunGame.getElapsedTime();
			processInput_ReviveMenu();
			render_InGame();
			render_ReviveMenu();
	}
}

// setupGamE

void Game::processInput_SetupGame() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			int clickSound = 1;
				//soundManager->clickSound.play();
			if (event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
				for (int i = 0; i < 4; i++) {
					if (itemSprite[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						pointerItem = i;
						clickSound = 1;
					}
				}
				if (getItemButtonSprite.getGlobalBounds().contains(mousePos.x,mousePos.y)) {
					increaseItem_SetupGame();
					clickSound = 2;
				}
				if (resetItemButtonSprite.getGlobalBounds().contains(mousePos.x,mousePos.y)) {
					resetItem_SetupGame();
					clickSound = 2;
				}
				if (runInGameButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					choseWindow = 4;
					clickSound = 2;
				}
			}
			soundManager->playSound(clickSound);
		}
	}
}

void Game::increaseItem_SetupGame() {
	if (player.beginPoints >= player.inventory.getItemByIndex(pointerItem).getCost()) {
		player.beginPoints -= player.inventory.getItemByIndex(pointerItem).getCost();
		player.inventory.increaseItemByIndex(pointerItem, 1);
	}

	quantityItemsText[pointerItem].setString((std::to_string(player.inventory.getItemByIndex(pointerItem).getQuantity())));
	beginPointsText.setString("Current point: " + std::to_string(player.beginPoints));
}

void Game::resetItem_SetupGame() {
	for (int i = 0; i < 4; i++) {
		player.inventory.resetQuantityItemByIndex(i);
	}
	player.beginPoints = BEGIN_POINTS;
}

void Game::updateDataPerFrame_SetupGame() {
	tmpItemSprite.setTexture(itemTexture[pointerItem]);
	beginPointsText.setString("Current point: " + std::to_string(player.beginPoints));
	for(int i  = 0 ; i < 4 ; i++)
		quantityItemsText[i].setString("Quantity: "+(std::to_string(player.inventory.getItemByIndex(i).getQuantity())));
	// display mô tả của item 
	// ..
}

void Game::render_SetupGame() 
{
	window->clear();

	window->draw(skySprite);
	window->draw(backgroundSprite);
	window->draw(treeBackgroundSprite);

	window->draw(player.characterSprite);

	window->draw(tableSetupSprite);

	for (int i = 0; i < 4; i++) 
		window->draw(itemSprite[i]);

	window->draw(quantityItemsText[pointerItem]);
	
	window->draw(beginPointsText);

	window->draw(scriptItemText[pointerItem]);
	window->draw(getItemButtonSprite);
	window->draw(resetItemButtonSprite);

	window->draw(runInGameButtonSprite);
	
	window->draw(tmpItemSprite);
	window->display();
}

// InGame

void Game::processInput_InGame() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

		if (event.type == sf::Event::KeyPressed)
		{	
			int click = 0;
			if (event.key.code == sf::Keyboard::P || event.key.code == sf::Keyboard::Escape) {
				// pause   
				choseWindow = 10;
				click = 1;
			}
			if (event.key.code == sf::Keyboard::I) {
				choseWindow = 11;
				click = 1;
			}
			if (player.sum() < 3) {
				if (event.key.code == sf::Keyboard::A) {
					if (player.sum() == 0)
						player.castingMagic(playedTime);
					updateLayerCast(0);
					click = 1;
				}
				else if (event.key.code == sf::Keyboard::S) {
					if (player.sum() == 0)
						player.castingMagic(playedTime);
					updateLayerCast(1);
					click = 1;
				}
				else if (event.key.code == sf::Keyboard::D) {
					if (player.sum() == 0)
						player.castingMagic(playedTime);
					updateLayerCast(2);
					click = 1;
				}
			}
			if (event.key.code == sf::Keyboard::Enter && player.sum() > 0) {
				castMagic();
				click = 1;
			}
			soundManager->playSound(click);
		}

		if (event.type == sf::Event::MouseButtonPressed) { // input keyboard
			int click = 0;
			if (event.mouseButton.button == sf::Mouse::Left) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);	
				if (pauseButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
				{
					click = 1;
					choseWindow = 10;
				}
				if (inventoryButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
				{
					// pauseGame và hiển thị inventory
					choseWindow = 11;
					click = 2; 
				}
				if (castButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)
					&& player.sum() > 0) 
				{
					castMagic();
					click = 1;
				}
				if (player.sum() < 3) 
				{
					for (int i = 0; i < 3; i++) 
					{
						if (elementSprite[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
							if(player.sum() == 0 )
								player.castingMagic(playedTime);
							updateLayerCast(i);
							click = 1;
						}
					}
				}
			}
			soundManager->playSound(click);
		}
    }
}

void Game::updateLayerCast(int i) {
	if (!player.stress)
	{
		int a = i;
		if (a == 0)			player.cast.fire++;
		else if (a == 1)	player.cast.water++;
		else				player.cast.earth++;
		layerCastSprite[player.pointerCast].setTexture(elementCastTexture[a]);

	}
	else 
	{
		int a = i;
		int b = (i == 0 || i == 2 ) ? 1 : 2;
		int c = (b == 1 && i == 0) ? 2 : 0;

		// a = 0 b = 1 c = 2
		// a = 1 b = 2 c = 0
		// a = 2 b = 1 c = 0
		
		// 20% ko mong muon
		// 10% chia deu cho 2 nguyen to con lai
		
		int tmp;

		int ran = randomInRange(0, 1000);
		if (ran > 300) {
			tmp = a;
		}
		else if (ran > 150) {
			tmp = b;
		}
		else {
			tmp = c;
		}
		if (tmp == 0)			player.cast.fire++;
		else if (tmp == 1)		player.cast.water++;
		else					player.cast.earth++;
		layerCastSprite[player.pointerCast].setTexture(elementCastTexture[tmp]);
	}
	player.pointerCast++;
}

void Game::castMagic() {
	// không thể kill khi chưa spawn
	bool hit = false;
	for (int i = 0; i < enemies.size(); i++) {
		for (int u = 0; u < enemies[i]->element.size(); u++) {
			if (player.cast == enemies[i]->element[u] && enemies[i]->isAlive()) 
			{
				if(!hit) soundManager->normalCastSound.play();
				hit = true;		
				enemies[i]->decreaseHpByNormalCast(u);
				enemies[i]->eventNormalCast(enemyTexture, playedTime);
				u--;
				if (enemies[i]->HP == 0) {
					enemies[i]->die(playedTime);
				}
			}
		}
	}
	for (int i = 0; i < player.pointerCast; i++) {
		layerCastSprite[i].setTexture(layerCastTexture);
	}


	player.castMagic(playedTime, hit);
}

void Game::updateDataPerFrame_InGame() {

	useMagicItem();				// sử dụng Item Magic
	updateStressPoints();

	updateAnimation_InGame();
	spawnEnemies_InGame();

	updateData_InGame();
	// reset data perFrame ->

	moveEnemies_InGame();

}

void Game::updateStressPoints() {
	 
	int decreasePoint = DECREASE_STRESS_POINT_PER_SECOND / MAX_FPS;
	if (player.pointerCast == 0  ) {
		decreasePoint = CONST_NORMAL * DECREASE_STRESS_POINT_PER_SECOND / MAX_FPS;
	}
	if (player.stress) decreasePoint = CONST_STRESS * DECREASE_STRESS_POINT_PER_SECOND / MAX_FPS;
	
	//std::cout << player.intervalTime.asMilliseconds() << " " << playedTime.asMilliseconds() << std::endl;

	if (player.intervalTime.asMilliseconds() < playedTime.asMilliseconds()) {
		if (player.currentStressPoints - decreasePoint <= 0) {
			player.currentStressPoints = 0;
			player.stress = false;
		}
		else
			player.currentStressPoints -= decreasePoint;
	}

	sliderStressSprite.setTextureRect(sf::IntRect(0, 0
		, sliderStressTexture.getSize().x * player.currentStressPoints / MAX_STRESS_POINTS
		, sliderStressTexture.getSize().y));
}

void Game::updateAnimation_InGame() {

	//ground

	// sky
	//for (int i = 0; i < FRAME_SKY; i++) {
	//	if (skyTime[i].asMilliseconds() < playedTime.asMilliseconds() % TIME_SKY) { // có cần thiết phải thêm một biến time
	//		skySprite.setTexture(skyTexture[i]);
	//	}
	//}

	// character
	player.updateAnimation(playedTime);
	
	for(int i = 0; i < enemies.size(); i++) {
		// castAnimation

		enemies[i]->updateAnimation(enemyTexture,playedTime);

		// xóa 
		if (!enemies[i]->isAlive()) 
		{
			if (enemies[i]->statusTime + sf::milliseconds(TIME_DIE) < playedTime) {
				enemies.erase(enemies.begin() + i);
				i--;
			}
		}
	}
	// playedTime
	int min = (int)playedTime.asSeconds() / 60;
	int second = (int)playedTime.asSeconds() % 60;
	std::string s = ((min<10) ? "0" : "") + (std::to_string(min)) + ":" + ((second < 10) ? "0" : "")+(std::to_string(second));
	playedTimeText.setString(s);
}
	
void Game::spawnEnemies_InGame() {
	if (dataBalance.wave == 0 || playedTime.asMilliseconds() > dataBalance.wave * TIME_SPAWN) {
		/// backup spawn
		for (int i = 0; i < enemyPerSpawn.size(); i++) {
			enemyPerSpawn[i]->spawn(enemyTexture);
		}
		enemyPerSpawn.clear();

		//clockSpawn.restart();
		
		// cân bang
		dataBalance.balance();
		// create new wave
		if (dataBalance.wave % WAVE_PER_ELITE == 0) { // SPAWN ELITE
			Elite* tmp = new Elite;
			tmp->init(dataBalance, playedTime);
			enemyPerSpawn.push_back(tmp);
		}
		else {
			int quantityEnemyPerSpawn = randomQuantityEmemy(dataBalance.rate[0], dataBalance.rate[1]);

			for (int i = 0; i < quantityEnemyPerSpawn; i++) {
				Enemy* tmp = new Enemy;
				tmp->init(dataBalance, playedTime);
				enemyPerSpawn.push_back(tmp);
			}
		}
	}
	sf::Time time = playedTime;
	for (int i = 0; i < enemyPerSpawn.size(); i++) {
		if (enemyPerSpawn[i]->statusTime < time )
		{
			// spawn
			//console
			//for (int u = 0; u < enemyPerSpawn[i]->element.size() ; u++) {
			//	enemyPerSpawn[i]->element[u].inE();
			//}
			
			enemyPerSpawn[i]->spawn(enemyTexture);
			enemies.push_back(enemyPerSpawn[i]);
			
			enemyPerSpawn.erase(enemyPerSpawn.begin() + i);
			break;
		}
	}
}
   
void Game::moveEnemies_InGame() {
	double x = 1 * speedBuffFromEnemies * speedItem ;
	for (auto& enemy : enemies) {
		enemy->move(x);
	}
}

void Game::updateData_InGame() {
	/// Enemies

	if (durationItem.asMilliseconds() < clockItem.getElapsedTime().asMilliseconds()) {
		indexUsedItem = -1;
		resetDataInGame();
	}
	/// player
}
	
void Game::eventPlayerDie() {
	for (auto& enemy : enemies) {
		int positionX = enemy->getPosition().x;
		if (positionX < END_GAME_POSITION_X  && enemy->isAlive()) {
			if (gameMode == 0) // story mode
			{
				player.live--;
				HPSprite[player.live].setTexture(emptyHPTexture);
			}
			else player.live -= 3; // endless mode


			if (player.live > 0) {
				choseWindow = 2;
				runReviveMenu();
			}

			if (player.live == 0) {
				choseWindow = 3;
				// run Animation EndGame
				endGameAnimationClock = new sf::Clock();
				runEndGameAnimation();
				delete endGameAnimationClock;
				runEndGameMenu();
			}
		}
	}
}

void Game::render_InGame() {
	window->clear();


	window->draw(skySprite);
	window->draw(backgroundSprite); 
	
	for (int i = 0; i < 3; i++) {
		window->draw(elementSprite[i]);
	}
	window->draw(playedTimeText);

	for (int i = 0; i < 3; i++) {
		window->draw(HPSprite[i]);
	}


	std::vector<Enemy*> tmpEnemies = enemies;
	std::sort(tmpEnemies.begin(), tmpEnemies.end());
	for (auto& enemy : tmpEnemies) {
		window->draw(enemy->sprite);

		for (int i = enemy->spellOrbSprite.size() - 1; i >= 0; i--) {
			window->draw(enemy->spellOrbSprite[i]);
		}
		if (enemy->normalCast) 
			window->draw(enemy->normalCastSprite);
	}
	window->draw(treeBackgroundSprite);
	window->draw(player.characterSprite);              
	window->draw(player.faceCharSprite);
	// layer Cast
	window->draw(mainTableSprite);

	if (player.chatBox) {
		window->draw(player.miniChatBoxSpite);
		window->draw(player.chatBoxSprite);
		window->draw(player.chatText);
	}

	window->draw(player.faceCharSprite);
	window->draw(borderStressSprite);
	window->draw(sliderStressSprite);
	window->draw(castButtonSprite);

	for (int i = 0; i < 3; i++) {
		window->draw(layerCastSprite[i]);
	}
	window->draw(inventoryButtonSprite);
	window->draw(pauseButtonSprite);

	if(choseWindow == 1)
		window->display();
}
// inventory

void Game::setup_inventory() {
	for (int i = 0; i < 4; i++) {
		itemSprite[i].setPosition(width * 0.86 / 3, height * 1.2 / 5 + i * height / 7.5);
		itemSprite[i].setScale(0.45, 0.45);
		scriptItemText[i].setPosition(width * 1.7 / 4, height * 3 / 10);
		quantityItemsText[i].setPosition(width * 1.7 / 4, height * 2.8 / 5);
	}
	tmpItemSprite.setPosition(width * 6.1 / 12, height / 12);

	xButtonSprite.setPosition(width * 2.6 / 4, height * 1.05 / 5);
}

void Game::processInput_Inventory() {
	sf::Event event;
	while (window->pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		//int click = 1;
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				choseWindow = 1;
				soundManager->playSound(2);
			}
		}

		if (event.type == sf::Event::MouseButtonPressed) 
		{
			if (event.mouseButton.button == sf::Mouse::Left) 
			{
				int click = 1;
				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
				for (int i = 0; i < 4; i++)
				{
					if (itemSprite[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) 
					{
						pointerItem = i;
						tmpItemSprite.setTexture(itemTexture[i]);
						click = 1;
					}
				}
				if (useItemButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					if (player.inventory.getItemByIndex(pointerItem).getQuantity() > 0) {
						useItem();
						useEnhanceItem(); // sử dụng Item Enhance
						click = 2;
					}
				}
				if (xButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					choseWindow = 1;
					click = 2;
				}
				soundManager->playSound(click);
			}
		}
	}
}

void Game::render_Inventory() {
	render_InGame();
	window->draw(tableItemSprite);
	window->draw(xButtonSprite);
	window->draw(useItemButtonSprite );
	for (int i = 0; i < 4; i++) {
		window->draw(itemSprite[i]);
	}
	window->draw(quantityItemsText[pointerItem]);
	window->draw(scriptItemText[pointerItem]);
	window->draw(tmpItemSprite);
	window->display();
}

// useItem

void Game::useItem() {
	choseWindow = 1;
	indexUsedItem = pointerItem;
	player.useItemByIndex(indexUsedItem);
	quantityItemsText[indexUsedItem].setString(std::to_string(player.inventory.getItemByIndex(indexUsedItem).getQuantity()));
	durationItem = player.inventory.getItemByIndex(indexUsedItem).getTime();
	clockItem.restart();
}

void Game::useEnhanceItem() {
	switch (indexUsedItem)
	{
		case 3:
			player.currentStressPoints = 0;
			break;
		case 4:
			break;
		default:
			break;
	}
	// console
}

void Game::useMagicItem() {  /// sử dụng item Magic
	switch (indexUsedItem)
	{
	case 0:
		speedItem =   0.3;
		/// update

		break;
	case 1:
		// update
		speedItem = 0;

		break;
	case 2:	/// tính năng ;)))
		// explosion
		for (auto& enemy : enemies) {
			enemy->eventNormalCast(enemyTexture, playedTime);
			enemy->die(playedTime);
		}
		player.castMagic(playedTime, 1);
		soundManager->normalCastSound.play();
		break;
	default:
		break;
	}
} 

// pauseGame

void Game::processInput_PauseGame() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape) {
				soundManager->playSound(1);
				choseWindow = 1;
			}
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				int click = 1;
				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
				if (continueButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					choseWindow = 1;
					click = 2;
				}
				if (settingMenuButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					choseWindow = 100;
					click = 2;
				}
				if (exitButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					// exit
					choseWindow = -1;
					click = 2;
				}
				soundManager->playSound(click);
			}
		}
	}
}

void Game::render_PauseGame() {
	// ko clear
	render_InGame();

	window->draw(continueButtonSprite);		/// continue
	window->draw(settingMenuButtonSprite);	///	settingMenu
	window->draw(exitButtonSprite);			///	exitInGame -> Menu
	if(choseWindow == 10)
		window->display();
}

// reviveMenu

void Game::processInput_ReviveMenu() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window->close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				int click = 1;
				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);			
				if (reviveButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{
					click = 2;
					choseWindow = 1;
					// animation revive
					player.revive(playedTime);
					for (auto& enemy : enemies) {
						enemy->eventNormalCast(enemyTexture, playedTime);
						enemy->die(playedTime);
					}
					player.castMagic(playedTime, 1);
					soundManager->normalCastSound.play();
				}
				if (xButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					player.live = 0;
					choseWindow = 3;
					click = 2;
				}
				soundManager->playSound(click);
			}
		}
	}
}

void Game::render_ReviveMenu() {
	sf::Texture tmpTexture;
	sf::Sprite	tmpSprite;
	tmpTexture.loadFromFile("./assets/images/BackgroundTutorial.png");
	tmpSprite.setTexture(tmpTexture);
	window->draw(tmpSprite);
	//window->draw(reviveTableSprite);
	window->draw(reviveButtonSprite);
	window->draw(xButtonSprite);

	window->display();
}

// AnimationEndGame

void Game::runEndGameAnimation() {
	while (window->isOpen() && endGameAnimationClock->getElapsedTime().asMilliseconds() < TIME_END_GAME_ANIMATION ) {
		while (clockRunGame.getElapsedTime() - lastFrameTime < minDeltaTime);
		lastFrameTime = clockRunGame.getElapsedTime();
		// updateAnimation

		for (int i = 0; i < FRAME_END_GAME_ANIMATION; i++) {
			if (endGameAnimationTime[i] < endGameAnimationClock->getElapsedTime()) {
				endGameAnimationSprite.setTexture(endGameAnimationTexture[i]);
			}
		}
		// render
		render_InGame();
		window->draw(endGameAnimationSprite);
		window->display();
	}
}

/// DATA

void Game::updateFullscreen() {
	if (dataSetting->isFullscreen)
	{
		window->create(sf::VideoMode(width, height), "itIsNotAGame", sf::Style::Fullscreen);
	}
	else
	{
		window->create(sf::VideoMode(width, height), "itIsNotAGame", sf::Style::Default);
		width = window->getSize().x;
		height = window->getSize().y;
	}
	setup_Game();
	settingMenu->setup_SettingMenu();
	endGameMenu->setup_EndGameMenu();
	tutorialMenu->setup();
}

void Game::updateVolume() {
	soundManager->updateVolume(*dataSetting);
}

/// reset DataGame

void Game::resetDataGame() {
	//  reset display
	for (int i = 0; i < 3; i++) {
		HPSprite[i].setTexture(HPTexture);
	}
	setup_Game();
	//
	pointerItem = 0;
	enemies.clear();
	player.reset();
	dataBalance.reset();
	playedTime = sf::milliseconds(0);
	beginPointsText.setString("Current point: " + std::to_string(player.beginPoints));
	playedTimeText.setString("00:00");
	for (int i = 0; i < 3; i++) {
		layerCastSprite[i].setTexture(layerCastTexture);
	}
}
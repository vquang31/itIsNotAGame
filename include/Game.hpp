#pragma once

#include <SFML/Graphics.hpp>
#include "DataSetting.hpp"
#include "RandomGenerator.hpp"
#include "Enemy.hpp"
#include "Elite.hpp"
#include "Element.hpp"
#include "SettingMenu.hpp"
#include "Player.hpp"
#include "DataBalance.hpp"
#include "EndGameMenu.hpp"
#include "SoundManager.hpp"
#include "TutorialMenu.hpp"
#include "EnemyTexture.hpp"


class Game {
public:
	void init(sf::RenderWindow& window, DataSetting* dataSetting
		, SettingMenu* a, SoundManager* s);
	void run();
private:
	Player player;
	void initData();
	void initSource();
	void setup_Game();
	void resetDataGame();


	//
	sf::Font*						font = new sf::Font();
	int								width, height;
	sf::RenderWindow*				window;
	DataSetting*					dataSetting;

	///////////
	// 
	// 0	->	setupGame
	// 1	->	inGame
	// 10	->	pauseGame	
	//		100	->	settingMenu	
	//		-1	->	out
	// 
	// 11	->	onInventory
	// 
	// 3	->	endGameMenu
	//		0		->	setupGame (replay)
	//		-1		->	out
	// 2	->	revive?Menu
	// 
	// 
	// 4	->	tutorial
	///////////

	int choseWindow = 0;


	// settingMenu

	SettingMenu*					settingMenu;
	SoundManager*					soundManager;

	void updateFullscreen();
	void updateVolume();


	// 
	

	//////////
	// 0 -> story mode
	// 1 ->	endless mode
	//
	///////////
	int gameMode = 0;



	// endGameMenu

	TutorialMenu*					tutorialMenu = new TutorialMenu();
	EndGameMenu*					endGameMenu = new EndGameMenu();

	//








	/// data
	
	// 




	//time

	
	sf::Clock						clockRunGame;	// khác với thời gian runInGame
	sf::Time						minDeltaTime ; /// để làm FPS
	sf::Time						lastFrameTime;	
	sf::Clock						playedClockPerFrame;
	sf::Time						playedTime;

	// sound effect


	// setupGame

	
	sf::Texture						runInGameButtonTexture;
	sf::Sprite						runInGameButtonSprite;

	sf::Texture						tableSetupTexture;
	sf::Sprite						tableSetupSprite;

	sf::Texture						getItemButtonTexture;
	sf::Sprite						getItemButtonSprite;

	sf::Texture						resetItemButtonTexture;
	sf::Sprite						resetItemButtonSprite;

	sf::Sprite						tmpItemSpite;
	int								pointerItem = 0 ;

	void increaseItem_SetupGame();
	void resetItem_SetupGame();


	// input to Play

	void updateLayerCast(int i);
	void castMagic();

	// dataInGame

	double							speedItem = 1;
	double							speedBuffFromEnemies = 1;

	void resetDataInGame() {
		speedItem = 1;
	}


	///// UI

	// dataDisplay

	//text

	std::array<sf::Text, 12>		quantityItemsText;
	sf::Text						beginPointsText;

	sf::Text						playedTimeText;


	//  inGame
	// sinh quai
	DataBalance						dataBalance;
	EnemyTexture*					enemyTexture = new EnemyTexture();


	std::vector<Enemy *>				enemyPerSpawn;
	//sf::Clock clockSpawn;

	std::vector<Enemy *>				enemies;


	// background
	
	sf::Time						skyTime[FRAME_SKY];
	std::vector<sf::Texture>		skyTexture;
	sf::Sprite						skySprite;

	sf::Texture						HPTexture;
	sf::Texture						emptyHPTexture;
	std::array<sf::Sprite , 3>		HPSprite;


	sf::Texture						backgroundTexture;
	sf::Sprite						backgroundSprite;

	sf::Texture						treeBackgroundTexture;
	sf::Sprite						treeBackgroundSprite;

	// table

	sf::Texture						mainTableTexture;
	sf::Sprite						mainTableSprite;

	sf::Texture						tableCastTexture;
	sf::Sprite						tableCastSprite;

	sf::Texture						tableFaceCharacterTexture;
	sf::Sprite						tableFaceCharacterSprite;
	  

	// layer cast

	sf::Texture						layerCastTexture;
	std::array<sf::Sprite,3>		layerCastSprite;

	sf::Texture						castButtonTexture;
	sf::Sprite						castButtonSprite;

	std::array<sf::Texture, 3>		elementCastTexture; // dùng cho bên trên 

	std::array<sf::Texture, 3>		elementTexture; // dùng cho bên trên 
	std::array<sf::Sprite,  3>		elementSprite; // hiển thị bên dưới 

	// slider Stress

	sf::Texture						borderStressTexture;
	sf::Sprite						borderStressSprite;

	sf::Texture						sliderStressTexture;
	sf::Sprite						sliderStressSprite;

	
	// pauseButton

	sf::Texture						pauseButtonTexture;
	sf::Sprite						pauseButtonSprite;		

	// Inventory

	sf::Texture						inventoryButtonTexture;
	sf::Sprite						inventoryButtonSprite;

	std::array<sf::Texture, 12>		itemTexture;
	std::array<sf::Sprite, 12>		itemSprite;

	sf::Texture						tableItemTexture;
	sf::Sprite						tableItemSprite;

	sf::Texture						xButtonTexture;
	sf::Sprite						xButtonSprite;

	sf::Texture						useItemButtonTexture;
	sf::Sprite						useItemButtonSprite;

	// pauseGame

	sf::Texture						continueButtonTexture;				
	sf::Sprite						continueButtonSprite;

	sf::Texture						settingMenuButtonTexture;
	sf::Sprite						settingMenuButtonSprite;

	sf::Texture						exitButtonTexture;
	sf::Sprite						exitButtonSprite;


	// revive

	sf::Texture						reviveButtonTexture;
	sf::Sprite						reviveButtonSprite;

	sf::Texture						reviveTableTexture;
	sf::Sprite						reviveTableSprite;

	// cần thêm một màn hinh animation hiệu ứng hồi sinh




	//




	// Animation

	sf::Time												endGameAnimationTime[FRAME_END_GAME_ANIMATION];
	std::array<sf::Texture, FRAME_END_GAME_ANIMATION>		endGameAnimationTexture;
	sf::Sprite												endGameAnimationSprite;

	// method

	void runSetupGame();

	void runTutorial();

	void runInGame();

	void runPauseGame();

	void runSettingMenu();

	void runInventory();

	void runEndGameMenu();

	void runReviveMenu();

	// run Animation EndGame

	void runEndGameAnimation(); // gồm cả 3 giai đoạn do khá gắn
	sf::Clock*				endGameAnimationClock = new sf::Clock();
	/// runSetupGame

	void processInput_SetupGame();

	void updateDataPerFrame_SetupGame();

	void render_SetupGame();

	///  runInGame

	void processInput_InGame();

	void updateDataPerFrame_InGame();

		void updateStressPoints();
		void updateData_InGame();   /////// cho quái, player
		void updateAnimation_InGame();
		void spawnEnemies_InGame();
		void moveEnemies_InGame();
		void eventPlayerDie();

	void render_InGame();

	// inventory  // có thể làm một hệ thống riêng để tinh giảm 

	void setup_inventory();
	void processInput_Inventory();
	void render_Inventory();
	
	// use item
	void useItem();
	void useEnhanceItem();
	void useMagicItem();
	sf::Clock						clockItem;
	int								indexUsedItem = -1;
	sf::Time						durationItem;

	// runPauseGame

	void processInput_PauseGame();

	void render_PauseGame();


	// runReviveMenu

	void processInput_ReviveMenu();
	void render_ReviveMenu();


};
#pragma once

#include <SFML/Graphics.hpp>
#include "DATA.hpp"
#include "Element.hpp"
#include "Inventory.hpp"
#include "array"


class Player {
private:
	/////////// 
	// priority tăng dần
	//	0 - > rest
	//  2 - > stress
	//  3 - > revive
	//  chat
	//  1 - > cast
	///////////
	int							status = 0;

public:

	Player();

	Inventory						inventory;
	int								beginPoints = BEGIN_POINTS;
	Element							cast;
	int								pointerCast = 0;
	int								damage = 1;
	int								live = 3;

	//  giờ có 2 cách
	//  1 là fix cứng ô thoại
	//  2 là biến đổi ô thoại theo script
	std::vector<std::string>		chatString;
	sf::Text						chatText;
	bool							chatBox = false;

	// Lưu thời điểm kết thúc Chat
	sf::Time						chatTime = sf::milliseconds(3000);


	//  Lưu trữ mốc thời gian đầu tiên của hành động theo status 
	sf::Time					statusTime;

	sf::Clock					animationClock; //


	int				currentStressPoints = 0;  // 0 ->> 1000 /   ->> 1s trừ 100(có thể cần balance) -> 1 frame -> trừ 100 / MAX_FPS
	bool			stress = false;  /// đang setup nếu stress thì không thể cast 

	sf::Time		intervalTime;	// stress // lưu thời gian để bắt đầu giảm stress

	int sum() {
		return cast.fire + cast.water + cast.earth;
	}

	void useItemByIndex(int index) {
		if(index != -1)
			inventory.increaseItemByIndex(index, -1);
	}

	void reset() {
		live = 3;
		beginPoints = BEGIN_POINTS;
		inventory.reset();
		stress = false;
		currentStressPoints = 0;
		intervalTime = sf::microseconds(0);
	}


	bool						normalCastAnimation = false;
	
	//sf::Time						castAnimationTime;
	//sf::Time						restAnimationTime;

	std::array<sf::Time, FRAME_ANIMATION>			castAnimationTime;  /// CAST pheps // 1
	std::array<sf::Time, FRAME_ANIMATION>			restAnimationTime;  /// khoon lafm j // 0
	std::array<sf::Time, REVIVE_FRAME_ANIMATION>	reviveAnimationTime;/// REVIVE	 //3 

	std::array<sf::Texture, FRAME_ANIMATION>		castAnimationTexture;
	std::array<sf::Texture, FRAME_ANIMATION>		restAnimationTexture;
	std::array<sf::Texture, REVIVE_FRAME_ANIMATION>	reviveAnimationTexture;

	sf::Sprite						characterSprite;

	sf::Texture						miniChatBoxTexture;
	sf::Sprite						miniChatBoxSpite;

	std::vector<sf::Texture>		faceCharTexture;
	sf::Sprite						faceCharSprite;

	sf::Texture						chatBoxTexture;
	sf::Sprite						chatBoxSprite;

	void initData();
	void initSource();

	void setup(sf::Font* font);

	void updateAnimation(sf::Time playedTime);

	void revive(sf::Time playedTime);

	void castMagic(sf::Time playedTime, bool hit);

};
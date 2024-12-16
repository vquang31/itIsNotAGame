#include "Player.hpp"
#include <iostream>


Player::Player() {
	initData();
	initSource();
}

void Player::initData() {
	// initDataChat
	std::fstream chatChar_file("./assets/data/ChatChar.txt");
	std::string	line;
	std::string chat = "";
	while (std::getline(chatChar_file, line)) {
		if ( line != "------")
			chat = chat + line + "\n";
		else {
			chat.erase(chat.length() - 1);
			chatString.push_back(chat);
			chat = "";
		}
	}
	chat.erase(chat.length() - 1);
	chatString.push_back(chat);

	chatChar_file.close();

}

void Player::initSource() {
	for (int i = 0; i < CAST_FRAME_ANIMATION; i++) {
		castAnimationTime[i] = sf::milliseconds(i * TIME_CAST / CAST_FRAME_ANIMATION);
		castAnimationTexture[i].loadFromFile("./assets/images/animation/castAnimation/CastAnimation" + (std::to_string(i)) + ".png");
	}

	for (int i = 0; i < REST_FRAME_ANIMATION; i++) {
		restAnimationTime[i] = sf::milliseconds(i * TIME_REST / REST_FRAME_ANIMATION);
		restAnimationTexture[i].loadFromFile("./assets/images/animation/restAnimation/RestAnimation" + (std::to_string(i)) + ".png");

	}


	

	for (int i = 0; i < REVIVE_FRAME_ANIMATION; i++) {
		reviveAnimationTime[i] = sf::milliseconds(i * TIME_REVIVE/ REVIVE_FRAME_ANIMATION);
		reviveAnimationTexture[i].loadFromFile("./assets/images/animation/reviveAnimation/ReviveAnimation" + (std::to_string(i)) + ".png");
	}

	for (int i = 0; i < CASTING_FRAME_ANIMATION; i++) {
		castingAnimationTime[i] = sf::milliseconds(i * TIME_CASTING / CASTING_FRAME_ANIMATION);
		castingAnimationTexture[i].loadFromFile("./assets/images/animation/castingAnimation/castingAnimation" + (std::to_string(i)) + ".png");
	}



	//miniChatBoxTexture.loadFromFile("./assets/images/MsiniChatBox.png");
	//miniChatBoxSpite.setTexture(miniChatBoxTexture);

	for (int i = 0; i < 1; i++) {
		sf::Texture tmp;
		tmp.loadFromFile("./assets/images/animation/faceCharAnimation/FaceCharacterAnimation" + (std::to_string(i)) + ".png");
		faceCharTexture.push_back(tmp);	
	}
	faceCharSprite.setTexture(faceCharTexture[0]);

	//chatBoxTexture.loadFromFile("./assets/images/ChatBox.png");
	//chatBoxSprite.setTexture(chatBoxTexture);

}

void Player::setup(sf::Font* font) {

	int x = sf::VideoMode::getDesktopMode().width;
	int y = sf::VideoMode::getDesktopMode().height;

	characterSprite.setTexture( restAnimationTexture[0]);
	characterSprite.setPosition(x / 5, y / 2.5); 
	characterSprite.setScale(SCALE * 0.5, SCALE * 0.5);

	//miniChatBoxSpite.setPosition(50 ,HEIGHT / 3);
	//miniChatBoxSpite.setScale(0.1, 0.1);

	faceCharSprite.setPosition( x / 40, y * 3.2/ 5);
	faceCharSprite.setScale(SCALE,SCALE);

	//chatBoxSprite.setPosition(WIDTH / 5, HEIGHT * 4 / 5 );
	//chatBoxSprite.setScale(0.2 ,0.2);

	//chatText.setScale
	//chatText.setPosition(100, 700);
	//chatText.setColor(sf::Color::Red);
	//chatText.setFont(*font);

}


void Player::updateAnimation(sf::Time playedTime) {
	if (status == 0) {
		for (int i = 0; i < REST_FRAME_ANIMATION; i++)
		{

			if (statusTime + restAnimationTime[i] < playedTime) {
				characterSprite.setTexture(restAnimationTexture[i]);
			}
		}
		if (statusTime + sf::milliseconds(TIME_REST) < playedTime) {
			status = 0;
			statusTime = playedTime;
		}
	}

	if (status == 3) {
		for (int i = 0; i < REVIVE_FRAME_ANIMATION; i++) {
			if (statusTime + reviveAnimationTime[i] < playedTime)
				characterSprite.setTexture(reviveAnimationTexture[i]);
		}
		if (statusTime + sf::milliseconds(TIME_REVIVE) < playedTime) {
			status = 0;
			statusTime = playedTime;
		}
	}

	if (status == 1) {
		for (int i = 0; i < CAST_FRAME_ANIMATION; i++) {
			if (statusTime + castAnimationTime[i] < playedTime) {
				characterSprite.setTexture(castAnimationTexture[i]);
			}
		}
		if (statusTime + sf::milliseconds(TIME_CAST) < playedTime) {
			status = 0;
			statusTime = playedTime;
		}
	}


	if (status == 2) {
		for (int i = CASTING_FRAME_ANIMATION - 1; i >=0 ; i--) {
			if (statusTime + castingAnimationTime[i] < playedTime) {
				characterSprite.setTexture(castingAnimationTexture[i]);
				break;
			}
		}
		if (statusTime + sf::milliseconds(TIME_CASTING) < playedTime) {
			status = 2;
			statusTime = playedTime;
		}

	}



	// NÓI KHI NÀO 
	//	   xuất hiện ngẫu nhiên 
	// HAY theo số lượng kill được 
	// HAY theo số lượng wave
	// HAY theo Elite và Boss
	// HAY kết hợp cả 4 
	//if (chatBox) { /// ddang test
	//	if (chatTime < playedTime) {
	//		chatBox = false;
	//	}
	//}
	//else {
	//	if ( sf::milliseconds(1000) < playedTime) {
	//		chatText.setString(chatString[0]);
	//		chatTime = playedTime + sf::milliseconds(3000);
	//		chatBox = true;
	//	}
	//	if (sf::milliseconds(10000) < playedTime) 
	//	{
	//		chatText.setString(chatString[1]);
	//		chatTime = playedTime + sf::milliseconds(5000);
	//		chatBox = true;
	//	}
	//	//......
	//}
}

void Player::revive(sf::Time playedTime) {
	status = 3;
	statusTime = playedTime ;
}

void Player::castMagic(sf::Time playedTime, bool hit) {
	if (!hit && !stress) {
		if (currentStressPoints + INCREASE_PER_WRONG_CAST >= MAX_STRESS_POINTS) {
			currentStressPoints = MAX_STRESS_POINTS;
			stress = true;
		}
		else currentStressPoints += INCREASE_PER_WRONG_CAST;
		intervalTime = (playedTime + sf::milliseconds(INTERVAL_TIME)); // lưu thời gian để bắt đầu giảm stress
	}
	pointerCast = 0;
	status = 1;
	statusTime = playedTime;
	cast.reset();
}

void Player::castingMagic(sf::Time playedTime) {
	status = 2;
	statusTime = playedTime;
}
#pragma once

#include "Enemy.hpp"
#include <iostream>

class Elite : public Enemy {
public:
	Elite() {
		Enemy();
		HP = 3;
		type = 1;
	}


	///////////////////////////////////
	// 0 - > chưa cast
	// 1 - > đang cast
	// 2 - > đã   cast 
	///////////////////////////////////
	int cast = 0;


	//sf::Clock	castSkillClock; /// đang cast thì chết ->> cần để ý đến độ ưu tiên hành động (priority Action)
	sf::Time	castSkillTime;

	void init(DataBalance dataBalance, sf::Time playedTime) {
		Enemy::init(dataBalance, playedTime);
		//castSkillClock.restart();
		castSkillTime = sf::milliseconds(randomInRange(1000,3000) + statusTime.asMilliseconds()); 
	
		// console 
		//std::cout << "cast" << castSkillTime.asMilliseconds() << std::endl;
	}






	/////////
	// idType
	// 0 - > enhance tốc độ của quái 
	// 1 - > lấy đà
	// 2 - > tốc độ của bản thân cực nhanh
	// 
	// 
	//
	////////
	// idType

	void updateAnimation(EnemyTexture* eT,sf::Time playedTime ) {
		//

		if ( cast == 0 && castSkillTime.asMilliseconds() <= playedTime.asMilliseconds()) {
			cast = 1;
		}

		if ( isAlive() && cast == 1 ) {
			if (idType != 2) {
				for (int i = 0; i < FRAME_CAST_SKILL_ELITE; i++) {
					if (castSkillTime.asMilliseconds() + i *  TIME_CAST_SKILL_ELITE / FRAME_CAST_SKILL_ELITE < playedTime.asMilliseconds()) {
					
						sprite.setTexture(eT->castSkillEliteTexture[i]);

					}
				}
				if (castSkillTime.asMilliseconds() + TIME_CAST_SKILL_ELITE < playedTime.asMilliseconds()) {
					castSkill(eT);
				}
			}
			if (idType == 2) {
	
			}
		}

		Enemy::updateAnimation(eT, playedTime); // giống super bên JAVA // tính kế thừa 
	}

	void castSkill(EnemyTexture* eT) {
		if (idType == 1) {
			velocity.x += (-100);
			sprite.setTexture(eT->elite1_1Texture);
		}
		cast = 2;
	}

	void move(double x) {
		if (cast != 1) {
			Enemy::move(x);
		}
	}
};
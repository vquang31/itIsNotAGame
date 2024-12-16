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
		//Enemy::init(dataBalance, playedTime);
		
		statusTime = sf::milliseconds(randomInRange(0, TIME_SPAWN)) + playedTime;

		idType = randomInRange(0, 1);
		//idType = 1;

		if (idType == 1) {
			castSkillTime = sf::milliseconds(randomInRange(1000,3000) + statusTime.asMilliseconds()); 
		}
		else {
			HP += 2;
		}
		// console 
		//std::cout << "cast" << castSkillTime.asMilliseconds() << std::endl;
	

		Enemy::init(dataBalance, playedTime);
	
	}






	/////////
	// idType
	// 0 - > +3 máu
	// 1 - > lấy đà
	////////
	// idType

	void updateAnimation(EnemyTexture* eT,sf::Time playedTime ) {
		//

		if ( cast == 0 && castSkillTime.asMilliseconds() <= playedTime.asMilliseconds()) {
			cast = 1;
		}

		if ( isAlive() && cast == 1 ) {
			if (idType == 1) {
				for (int i = 0; i < FRAME_CAST_SKILL_ELITE; i++) {
					if (castSkillTime.asMilliseconds() + i *  TIME_CAST_SKILL_ELITE / FRAME_CAST_SKILL_ELITE < playedTime.asMilliseconds()) {				
						sprite.setTexture(eT->castSkillEliteTexture[i]);
					}
				}
				if (castSkillTime.asMilliseconds() + TIME_CAST_SKILL_ELITE < playedTime.asMilliseconds()) {
					castSkill(eT);
				}
			}
			else {
				castSkill(eT);
			}
		}

		int timeRun = 500;
		if ( status == 1 &&  type == 1 && idType == 1 && cast == 2) {

			for (int i = 0; i < 4; i++) {
				if (statusTime.asMilliseconds() + i * timeRun / 4 < playedTime.asMilliseconds()) {
					sprite.setTexture(eT->moveElite1Texture[i]);
				}
			}
			if (statusTime.asMilliseconds() + timeRun < playedTime.asMilliseconds()) {
				statusTime = playedTime;
			}
		}
		Enemy::updateAnimation(eT, playedTime); // giống super bên JAVA // tính kế thừa 
	}

	void castSkill(EnemyTexture* eT) {
		if (idType == 1) {
			velocity.x += (-100);  ///// tăng vận tốc 100
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
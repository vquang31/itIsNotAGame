#pragma once
#include "DATA.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class EnemyTexture {
public:
	sf::Texture normalEnemyTexture[13]; // normal
	sf::Texture eliteEnemyTexture[2];

	sf::Texture spellOrbTexture[19];

	// dieAnimation
	std::vector<sf::Texture>		dieAnimationTexture;
	sf::Time	normalCastTime[FRAME_NORMAL_CAST];

	// lightning
	std::vector<sf::Texture>		normalCastTexture;
	sf::Time	dieTime[FRAME_DIE];

	// 
	sf::Time	castSkillEliteTime[FRAME_CAST_SKILL_ELITE];
	sf::Texture	castSkillEliteTexture[FRAME_CAST_SKILL_ELITE];


	sf::Texture elite1_1Texture;

	std::array<sf::Texture, 4> moveElite1Texture;



	void init() {

		for (int i = 0; i < FRAME_DIE; i++) {
			dieTime[i] = sf::milliseconds(i * (TIME_DIE / FRAME_DIE));
		}

		for (int i = 0; i < FRAME_NORMAL_CAST; i++) {
			normalCastTime[i] = sf::milliseconds(i * (TIME_NORMAL_CAST / FRAME_NORMAL_CAST));
			//std::cout << normalCastTime[i].asMilliseconds() << std::endl;
			//std::cout << 1 << std::endl;
		}
		
		for (int i = 0; i < FRAME_CAST_SKILL_ELITE; i++) {
			castSkillEliteTime[i] = sf::milliseconds(i * (TIME_CAST_SKILL_ELITE / FRAME_CAST_SKILL_ELITE));
		}

		// die Animation 

		for (int i = 0; i < FRAME_DIE; i++) {
			sf::Texture tmp;
			tmp.loadFromFile("./assets/images/animation/dieAnimation/DieAnimation" + (std::to_string(i)) + ".png");
			dieAnimationTexture.push_back(tmp);
		}

		// normalCast

		for (int i = 0; i < FRAME_NORMAL_CAST * 3; i++) {
			sf::Texture tmp;
			tmp.loadFromFile("./assets/images/normalCasts/NormalCast" + (std::to_string(i)) + ".png");
			normalCastTexture.push_back(tmp);
		}

		//for (int i = 0; i < 2; i++) {
			for (int u = 0; u < FRAME_CAST_SKILL_ELITE; u++) {
				castSkillEliteTexture[u].loadFromFile("./assets/images/animation/castSkillEliteAnimation/1/CastSkillElite1_" + (std::to_string(u)) + ".png");
			}
		//}

		// Enemy Texture
		for (int i = 0; i < 13; i++) {
			normalEnemyTexture[i].loadFromFile("./assets/images/enemy/normal/NormalEnemy" + (std::to_string(i)) + ".png");
		}
		

		for (int i = 0; i < 2; i++) {
			eliteEnemyTexture[i].loadFromFile("./assets/images/enemy/elite/Elite" + (std::to_string(i)) + ".png");
		}

		for (int i = 0; i < 4; i++) {
			moveElite1Texture[i].loadFromFile("./assets/images/animation/eliteMoveAnimation/1/" + (std::to_string(i)) + ".png");
		}


		elite1_1Texture.loadFromFile("./assets/images/animation/eliteMoveAnimation/1/0.png");
		for (int i = 0; i < 19; i++)
		{
			spellOrbTexture[i].loadFromFile("./assets/images/spellOrb/SpellOrb" + (std::to_string(i)) + ".png");
		}
		
	}
	EnemyTexture() {
		init();
	}

};
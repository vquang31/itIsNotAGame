#pragma once
#include "DATA.hpp"
#include <SFML/Graphics.hpp>

class EnemyTexture {
public:
	sf::Texture normalEnemyTexture; // normal
	sf::Texture eliteEnemyTexture[4];

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

	void init() {

		for (int i = 0; i < FRAME_DIE; i++) {
			dieTime[i] = sf::milliseconds(i * (TIME_DIE / FRAME_DIE));
		}

		for (int i = 0; i < FRAME_NORMAL_CAST; i++) {
			normalCastTime[i] = sf::milliseconds(i * (TIME_NORMAL_CAST / FRAME_NORMAL_CAST));
		}
		
		for (int i = 0; i < FRAME_CAST_SKILL_ELITE; i++) {
			castSkillEliteTime[i] = sf::milliseconds(i * (TIME_CAST_SKILL_ELITE / FRAME_CAST_SKILL_ELITE));
		}

		// die Animtion 

		for (int i = 0; i < FRAME_DIE; i++) {
			sf::Texture tmp;
			tmp.loadFromFile("./assets/images/animation/dieAnimation/DieAnimation" + (std::to_string(i)) + ".png");
			dieAnimationTexture.push_back(tmp);
		}

		// normalCast

		for (int i = 0; i < FRAME_NORMAL_CAST; i++) {
			sf::Texture tmp;
			tmp.loadFromFile("./assets/images/normalCasts/NormalCast" + (std::to_string(i + 1)) + ".png");
			normalCastTexture.push_back(tmp);
		}

		//for (int i = 0; i < 2; i++) {
			for (int u = 0; u < FRAME_CAST_SKILL_ELITE; u++) {
				castSkillEliteTexture[u].loadFromFile("./assets/images/animation/castSkillElite/"+(std::to_string(0))+"/CastSkillElite" + (std::to_string(0))+"_" + (std::to_string(u)) + ".png");
			}
		//}

		// Enemy Texture
		normalEnemyTexture.loadFromFile("./assets/images/enemy/normal/tickV.png");

		for (int i = 0; i < 4; i++) {
			eliteEnemyTexture[i].loadFromFile("./assets/images/enemy/elite/Elite" + (std::to_string(i)) + ".png");
		}

		elite1_1Texture.loadFromFile("./assets/images/enemy/elite/Elite1_1.png");

		//for (int i = 0; i < 3; i++) {

		//}

		//

		for (int i = 0; i < 19; i++)
		{
			spellOrbTexture[i].loadFromFile("./assets/images/spellOrb/SpellOrb" + (std::to_string(i)) + ".png");
		}
	}
	EnemyTexture() {
		init();
	}

};
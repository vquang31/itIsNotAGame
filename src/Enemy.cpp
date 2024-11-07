﻿#include "Enemy.hpp"
#include <iostream>
#include <algorithm>
Enemy::Enemy() {
	HP = 1;
	//complex = 0;
	//complex[0] = 0;
	velocity.x = BASE_VELOCITY_X;
	velocity.y = BASE_VELOCITY_Y;
	normalCast = false;
}

void Enemy::init(DataBalance dataBalance, sf::Time playedTime) {
	//HP = 2; // HP có thể để random hoặc 1 
	HP = 3;
	for (int k = 0; k < HP; k++) {
		int com = randomComplex(dataBalance.rate[0], dataBalance.rate[1]);
		complex.push_back(com);
		//int x = complex;
		int x = com;
		Element tmpE;
		for (int i = 0; i < x; i++) {
			int ran = randomInRange(0, 1000);
			if (ran > 666) {
				tmpE.fire++; 
			}
			else if (ran > 333) {
				tmpE.water++;
			}
			else {
				tmpE.earth++;
			}
		}
		element.push_back(tmpE);

		int tmp = element[k].fire * 100 + element[k].water * 10 + element[k].earth;
		id.push_back(tmp);
	}		
	// random tọa độ
	position.x = WIDTH * 3 / 4  ;				//// begin position
	beginYPosition = randomInRange(HEIGHT / 8, 600); 
	position.y = beginYPosition;
	sprite.setPosition(position.x, position.y);

	// tăng speed
	// cân bằng 
	double y = (-1) * randomInRange(0, dataBalance.wave) * 5.0f ;
	velocity.x += y;

	statusTime = sf::milliseconds(randomInRange(0, TIME_SPAWN)) + playedTime;
}

int Enemy::getIdTextureByid(int x) {   /// x là id 
	for (int i = 0; i < 19; i++) {
		if (x == SPELL_ID[i]) {
			return i;
			break;
		}
	}
}

void Enemy::spawn(EnemyTexture* eT) {
	status = 1;
	if (type == 0) {
		// setTexture

		int f = 0;
		int w = 0;
		int e = 0;

		for (int i = 0; i < HP; i++) {
			f += element[i].fire;
			w += element[i].water;
			e += element[i].earth;
		}
		 
		/// 3 TH Tổng quát
		// --- 3 ele bằng nhau -> tmp = 12
		// 
		// --- 2 ele = nhau , 1 ele ko có hoặc ít hơn
		//  tmp = 9, 10, 11
		// 
		// --- 1 ele lớn nhất, 2 ele bằng nhau 
		// 
		// 
		// --- 1 ele đơn  tmp = 0 -> 8 
		int tmp = randomEleTexture(f, w, e);
		sprite.setTexture(eT->normalEnemyTexture[tmp]);
		
		
		sprite.setScale(0.2, 0.2);
	}
	if (type == 1) {
		idType = randomInRange(0,1);
		sprite.setTexture(eT->eliteEnemyTexture[idType]);
		sprite.setScale(0.2, 0.2);
	}
	if (type == 2) {
		//sprite.setTexture(eT->);
		//sprite.setScale(0.2, 0.2);
	}

	for (int i = 0; i < HP; i++) {
		int idText = getIdTextureByid(id[i]);
		sf::Sprite	tmp;
		tmp.setTexture(eT->spellOrbTexture[idText]);
		tmp.setScale(0.4, 0.4);
		spellOrbSprite.push_back(tmp);
	}
}

void Enemy::move(double a) {

	sf::Vector2f	currVelocity;
	currVelocity.x = velocity.x * a; // 1 là hệ số 

	degree += ( (PI / 30 ) / TRANSACTION); // 

	currVelocity.y = velocity.y * a; //


	position.x += ( currVelocity.x * 1 / MAX_FPS); 


	if (status != 0 && type == 0) { // make normal fly
		position.y = beginYPosition + AMPLITUDE * sin(degree);
	}

	sprite.setPosition(position.x , position.y);


	// 
	if (HP == 3) {
		spellOrbSprite[0].setPosition(position.x, position.y);
		spellOrbSprite[1].setPosition(position.x, position.y);
		spellOrbSprite[2].setPosition(position.x, position.y);
	}
	if (HP == 2) {
		spellOrbSprite[0].setPosition(position.x, position.y);
		spellOrbSprite[1].setPosition(position.x, position.y);
	}
	if(HP == 1){
		spellOrbSprite[0].setPosition(position.x, position.y);
	}
}

void Enemy::decreaseHpByNormalCast(int u ) {
	HP--;
	complex.erase(complex.begin() + u);
	id.erase(id.begin() + u);
	element.erase(element.begin() + u);
	spellOrbSprite.erase(spellOrbSprite.begin() + u);
}


void Enemy::eventNormalCast(EnemyTexture* eT, sf::Time playedTime) {
	// cast Magic by wirazd
	normalCast = true;
	normalCastSprite.setTexture(eT->normalCastTexture[0]);
	normalCastSprite.setTextureRect(sf::IntRect(0, 0, eT->normalCastTexture[0].getSize().x + 100, eT->normalCastTexture[0].getSize().y + 50));
	normalCastSprite.setPosition(position.x - 137 // free style // tinh chỉnh display 
								,position.y - 930); // * tỉ số scale
	normalCastSprite.setScale(1,1);
	
	normalCastTime = playedTime;

	//clock.restart();
}

void Enemy::die(sf::Time playedTime) {
	//alive = false;
	status = 0;
	velocity.x = 0;
	velocity.y = 0;
	statusTime = playedTime;
	//clock.restart();
}

bool Enemy::isAlive() {
	return status;
}

sf::Vector2i Enemy::getPosition() {
	return position;
}

bool Enemy::operator<(const Enemy other) const {
	return position.y < other.position.y;
}

void Enemy::updateAnimation(EnemyTexture* eT, sf::Time playedTime) {
	if (normalCast) {
		for (int u = 0; u < FRAME_NORMAL_CAST; u++) {
			if (normalCastTime + eT->normalCastTime[u] < playedTime) {
				normalCastSprite.setTexture(eT->normalCastTexture[u]);
			}
		}
		if (normalCastTime + sf::milliseconds(TIME_NORMAL_CAST) < playedTime) {
			normalCast = false; // heest cứu
		}
	}
	// dieAnimtion
	if (status == 0)
	{
		for (int u = 0; u < FRAME_DIE; u++) {
			if ( statusTime + eT->dieTime[u] < playedTime) {
				sprite.setTexture(eT->dieAnimationTexture[u]);
			}
		}
	}
}
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <array>
#include "Element.hpp"
#include "RandomGenerator.hpp"
#include "DATA.hpp"
#include "DataBalance.hpp"
#include "EnemyTexture.hpp"


class Enemy {
private:
	sf::Vector2i position;
	int beginYPosition;
	//bool alive = true;
public:
	// phải có thanh trạng thái status 

	/////////
	// -1 -> chưa spawn
	//  0 -> die 
	//  1 -> alive
	//  BỊ TRÚNG ĐÒN KHÔNG GỌI LÀ BỊ DÍNH TRẠNG THÁI
	/////////
	int							status = -1;

	sf::Time					statusTime;
	sf::Time					normalCastTime; // lưu mốc thời gian bị trúng đòn


	//////
	// 0 -> normal
	// 1 -> Elite
	// 2 -> boss
	//
	//
	//////
	int type = 0;

	int idType = 0; /// 


	Enemy();
	void init(DataBalance dataBalance, sf::Time playedTime);
	// attribute
	int							HP = 1;
	std::vector<int>			complex;     // 1 2 3 // element + randomComplex
	std::vector<int>			id;
	std::vector<Element>		element;
	std::vector<sf::Sprite>		spellOrbSprite;


	double						degree = 0;
	sf::Vector2f				velocity;		// pos
	sf::Sprite					sprite;

	// 0
	// 1
	// 2 
	int							indexNormalCast;

	sf::Sprite					normalCastSprite; // bị trúng đòn

	//sf::Clock					clock;	 // bỏ 		
	// lưu thời gian để chạy frame của normalCast + lưu thời gian chết 

	int getIdTextureByid(int x);

	bool						normalCast = false;

	//void spawn(sf::Texture* texture , sf::Texture* ele);
	void spawn(EnemyTexture* eT);

	virtual void move(double x);

	void decreaseHpByNormalCast(int u);

	void eventNormalCast(EnemyTexture* eT, sf::Time playedTime);

	void die(sf::Time playedTime); 

	bool isAlive();

	bool operator<(const Enemy other) const;

	sf::Vector2i getPosition();

	virtual void updateAnimation(EnemyTexture* eT, sf::Time playedTime);


};

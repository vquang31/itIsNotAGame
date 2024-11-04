#pragma once
#include <string>
#include <SFML/System.hpp>

class Item {
private:
	int id;
	std::string name;
	std::string description;
	std::string type;
	int cost;
	int quantity;
	sf::Time duration;

public:
	// Constructor
	Item();
	Item(int id, std::string name,
		std::string description, std::string type
		, int cost, int duration);

	// setter
	void setQuantity(int x);


	// getter
	int getId();
	int getIndex();
	std::string getName();
	std::string getDescription();
	int getQuantity();
	int getCost();
	sf::Time getTime();

	void increaseQuantity(int x);
	void decreaseQuantity(int x);

};
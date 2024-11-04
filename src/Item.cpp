#include "Item.hpp"


Item::Item() {
	this->quantity = 0;
}

Item::Item(int id, std::string name, std::string description, std::string type, int cost, int duration) {
	this->id = id;
	this->name = name;
	this->description = description;
	this->type = type;
	this->cost = cost;
	this->quantity = 0;
	this->duration = sf::milliseconds(duration);
};

void Item::setQuantity(int x) {
	this->quantity = x;
}

int Item::getId() {
	return this->id;
}

int Item::getIndex() {
	return (this->id - 1);
}

std::string Item::getName() {
	return this->name;
}

std::string Item::getDescription() {
	return this->description;
}

int Item::getQuantity() {
	return this->quantity;
}

sf::Time Item::getTime() {
	return duration;
}

int Item::getCost() {
	return this->cost;
}

void Item::increaseQuantity(int x) {
	this->quantity += x;
}

void Item::decreaseQuantity(int x) {
	this->quantity -= x;
}


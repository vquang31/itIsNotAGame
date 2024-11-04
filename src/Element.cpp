#include "Element.hpp"
#include "iostream"

Element::Element() {
	reset();
}

void Element::inE() {
	std::cout << fire << " " << water << " " << earth << std::endl;
}

void Element::reset() {
	fire = 0;
	water = 0;
	earth = 0;
}

bool Element::operator==(const Element& other) const {
	return (fire == other.fire 
		&& water == other.water 
		&& earth == other.earth);
}
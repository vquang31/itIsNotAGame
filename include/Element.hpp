#pragma once 

class Element {
public:
	int fire = 0;
	int water = 0;
	int earth = 0;
	Element();

	void inE();


	void reset();

	bool operator==(const Element& other) const;
};
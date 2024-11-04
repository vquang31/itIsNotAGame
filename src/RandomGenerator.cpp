#include "RandomGenerator.hpp"


long long randomInRange(long long min, long long max) {
	return min + rand() % (max - min + 1);
}

bool rollRate(double x) {
	return (randomInRange(0, 1 / x) == 1);
}


bool rollInRange(long long x) {
	return (randomInRange(0, x) == 1);
}



	//// a < b
int randomComplex(int a, int b) {


	int x = randomInRange(0, 10000);
	if (x > b) return 3;
	if (x > a) return 2;
	return 1;
}

int randomQuantityEmemy(int a, int b){
	int x = randomInRange(0, 10000);
	if (x > b) return 4;
	if (x > a) return 3;
	return 2;
}
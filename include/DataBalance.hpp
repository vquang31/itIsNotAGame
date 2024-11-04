# pragma once

class DataBalance {
public:
	int wave = 0;
	int rate[2] = { 10000, 10000 }; // rateComplex
	int heso[2] = { 0, 0 };

	void reset() {
		wave = 0;
		rate[0] = rate[1] = 10000;
		heso[0] = heso[1] = 0;
	}

	void balance() {
		this->heso[0] = wave * 200;
		this->heso[1] = wave * 100;
		wave++;
		if (this->rate[0] - this->heso[0] < 0) this->rate[0] = 0;
		else this->rate[0] -= this->heso[0];
		if (this->rate[1] - this->heso[1] < 0) this->rate[1] = 0;
		else this->rate[1] -= this->heso[1];
	}
};
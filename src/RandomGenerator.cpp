#include "RandomGenerator.hpp"
#include "DATA.hpp"

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

int randomEleTexture(int f, int w, int e) {
	int x = 0;
	int trongSo[13];
	for (int i = 0; i < 13; i++) trongSo[i] = 0;
	int rate[14] = { 0 };

	int sum = f + w + e;
	int sumC = C[sum][3];
	if (sum >= 3) {

		// f = 2 , w = 3, e = 2 

		trongSo[2] = C[f][3] ;  // f	0
		trongSo[5] = C[w][3] ;  // w	1
		trongSo[8] = C[e][3] ;  // e	0
		trongSo[9]	= ( C[f][1] * C[w][2] + C[f][2] * C[w][1] );	/// fw  2*3 + 1*3  = 9
		trongSo[10] = ( C[f][1] * C[e][2] + C[f][2] * C[e][1] );	/// fe  2*1 + 1*2  = 4   
		trongSo[11] = ( C[w][1] * C[e][2] + C[w][2] * C[e][1] );	/// we  3*1 + 3*2  = 9
		trongSo[12] = f * w * e ;									/// fwe	2 * 3 * 2  = 12 -> total 35 = 7C3
		 
		rate[0] = 0;
		for (int i = 1; i <= 13; i++) {
			rate[i] = rate[i-1] + trongSo[i-1];
		}
		int random = randomInRange(0, sumC - 1);
		for (int i = 0; i < 13; i++)
		{
			if (rate[i] <= random && random < rate[i + 1])
			{
				x = i;
				break;
			}
		}
	}
	else {
		if (sum == 2) {					// ff , fw, fe , ww, we, ee
			if (f > 0) {
				if (f == 1) {
					if (w) x = 9;		// fw
					else x = 10;		// fe
				}
				else x = 1;				// ff
			}
			else {
				if (w == 1) {
					x = 11;				// we
				}
				else {
					if (w == 2) x = 4;	// ww
					else		x = 7;	// ee
				}
			}
		}
		else { // sum = 1
			if (f) {
				x = 0;					//f
			}
			else {
				if (w) x = 3;			//w
				else x = 6;				//e
			}
		}
	}
	//0, 1,  2,   3,  4,   5, 6,  7,   8,  9, 10, 11,  12
	//f, ff, fff, w, ww, www, e, ee, eee, fw, fe, we, fwe
	return x;
}
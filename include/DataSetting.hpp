#pragma once

class DataSetting {
public:
	int masterVolume = 50;
	int musicVolume = 50;
	int SFXVolume = 50;
	int isFullscreen = 0;
	DataSetting();

	bool operator ==(DataSetting);

	void increaseMasterVolume(int x) {
		masterVolume += (x * 10);
	}

	void increaseMusicVolume(int x) {
		musicVolume += (x * 10);
	}

	void increaseSFXVolume(int x) {
		SFXVolume += (x * 10);
	}


};
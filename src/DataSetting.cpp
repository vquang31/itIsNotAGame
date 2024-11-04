#include "DataSetting.hpp"

DataSetting::DataSetting() {
	masterVolume = 50;
	musicVolume = 50;
	SFXVolume = 50;
	isFullscreen = 0;
}

bool DataSetting::operator == (DataSetting o) {
	if (this->masterVolume == o.masterVolume
		&& this->musicVolume == o.musicVolume
		&& this->SFXVolume == o.SFXVolume
		&& this->isFullscreen == o.isFullscreen)
		return true;
	return false;
}


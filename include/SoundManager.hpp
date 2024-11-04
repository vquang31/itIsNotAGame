#pragma once 

#include <SFML/Audio.hpp>
#include "DataSetting.hpp"

class SoundManager {
public:

	SoundManager() {
		initSource();
		initData();
	}

	~SoundManager() {
		cleanup();
	}

	void cleanup() {
		backgroundTrackSound.stop();
	}


	void initSource();
	void initData();

	sf::SoundBuffer                 backgroundTrackBuffer;
	sf::Sound                       backgroundTrackSound;

	sf::SoundBuffer					normalCastSoundBuffer;
	sf::Sound						normalCastSound;

	sf::SoundBuffer					clickSoundBuffer;
	sf::Sound						clickSound;

	//sf::SoundBuffer				SoundBuffer;
	//sf::Sound						Sound;

	sf::SoundBuffer					clickButtonSoundBuffer;
	sf::Sound						clickButtonSound;

	sf::SoundBuffer					characterTalkSoundBuffer;
	sf::Sound						characterTalkSound;

	void updateVolume(DataSetting data);


};
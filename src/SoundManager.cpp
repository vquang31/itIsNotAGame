#include "SoundManager.hpp"


void SoundManager::initSource() {

    //backgroundTrackBuffer.loadFromFile("./assets/audio/testSHIKANOKO.ogg");
    backgroundTrackSound.setBuffer(backgroundTrackBuffer);

    normalCastSoundBuffer.loadFromFile("./assets/audio/bruh2.ogg");
    normalCastSound.setBuffer(normalCastSoundBuffer);

    clickSoundBuffer.loadFromFile("./");
    clickSound.setBuffer(clickSoundBuffer);

    clickButtonSoundBuffer.loadFromFile("./assets/audio");
    clickButtonSound.setBuffer(clickButtonSoundBuffer);

    characterTalkSoundBuffer.loadFromFile("./assets/audio");
    characterTalkSound.setBuffer(characterTalkSoundBuffer);





}

void SoundManager::initData() {
    backgroundTrackSound.setLoop(true);
    backgroundTrackSound.play();
    backgroundTrackSound.setVolume(50);
}

void SoundManager::updateVolume(DataSetting dataSetting) {
    backgroundTrackSound.setVolume(dataSetting.musicVolume * dataSetting.masterVolume / 100);
    normalCastSound.setVolume(dataSetting.SFXVolume * dataSetting.masterVolume / 100);
}
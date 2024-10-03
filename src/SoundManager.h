#pragma once
#include <raylib.h>

class SoundManager{
public:
    SoundManager();
    ~SoundManager();
    Music music;
    void initSounds();
    void playMusic();
    void updateMusic();
    void setVolume(float volume);
private:
    Sound explosionSound;
    float m_volume;
};
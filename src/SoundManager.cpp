#include "SoundManager.h"

SoundManager::SoundManager()
{
    initSounds();
    setVolume(0.6);
}

SoundManager::~SoundManager()
{
    UnloadMusicStream(music);
}

void SoundManager::initSounds()
{
    music=LoadMusicStream("Resources/Sounds/music.mp3");
}

void SoundManager::playMusic()
{
    PlayMusicStream(music);
}

void SoundManager::updateMusic()
{
    UpdateMusicStream(music);
}

void SoundManager::setVolume(float volume)
{
    SetMusicVolume(music,volume);
}

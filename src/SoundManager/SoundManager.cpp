#include "SoundManager.h"
#include "spdlog/spdlog.h"
namespace Agregat
{
	SoundManager::SoundManager(Engine& e)
		:engine(e)
	{
	
	}

	void SoundManager::Init()
	{
		InitAudioDevice();
	}

	void SoundManager::Shutdown()
	{
		CloseAudioDevice();
	}
	void SoundManager::Play(const std::string& nameOfTheSound)
	{
		if (nameSoundHashMap.contains(nameOfTheSound))
		{
			PlaySound(nameSoundHashMap[nameOfTheSound]);
		}
		else
		{
			spdlog::error("Tried to play the sound: " + nameOfTheSound + " But it doesn't exist.");
		}
	}
}

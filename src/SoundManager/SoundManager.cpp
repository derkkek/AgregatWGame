#include "SoundManager.h"

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
}

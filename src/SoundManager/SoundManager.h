#pragma once

#include "Types.h"
#include <unordered_map>
#include <string>
#include "raylib.h"
namespace Agregat
{
	class SoundManager
	{
	public:
		SoundManager(Engine& e);
		~SoundManager() = default;

		void Init();
		void Shutdown();

		std::unordered_map<std::string, Sound> nameSoundHashMap;

	private:
		Engine& engine;

	};
}


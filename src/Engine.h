#pragma once
#include "Types.h"
#include "GraphicsManager/GraphicsManager.h"
#include "InputManager/InputManager.h"
#include "SoundManager/SoundManager.h"
#include "ResourceManager/ResourceManager.h"

namespace Agregat
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		void Init();
		void RunGameLoop(const UpdateCallback& callback);
		void Shutdown();

		GraphicsManager graphics;
		InputManager input;
		SoundManager sound;
		ResourceManager resource;
	private:

	};

}

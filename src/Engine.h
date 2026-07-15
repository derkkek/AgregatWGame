#pragma once
#include "Types.h"
#include "GraphicsManager/GraphicsManager.h"
#include "InputManager/InputManager.h"
#include "SoundManager/SoundManager.h"

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
	private:

	};

}

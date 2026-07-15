#pragma once
#include "Types.h"
#include "GraphicsManager/GraphicsManager.h"
#include "InputManager/InputManager.h"

namespace Agregat
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		void Init();
		void RunGameLoop(const UpdateCallback& callback);

		GraphicsManager graphics;
		InputManager input;
	private:

	};

}

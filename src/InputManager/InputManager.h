#pragma once
#include "Types.h"

namespace Agregat
{
	class InputManager
	{
	public:
		InputManager(Engine& e);
		~InputManager();
		void Update();
		bool KeyIsPressed(int key);
	private:
		Engine& engine;
	};

}

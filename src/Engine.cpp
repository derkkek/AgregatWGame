#include "Engine.h"
#include <iostream>

namespace Agregat
{
	Engine::Engine()
		:graphics(*this), input(*this)
	{
		Init();
	}
	
	Engine::~Engine()
	{
	}

	void Engine::Init()
	{
		graphics.Init();
	}

	void Engine::RunGameLoop(const UpdateCallback& callback)
	{
		while (!graphics.ShouldWindowClosed())
		{

			callback();
			graphics.Draw();
		}
	}
}
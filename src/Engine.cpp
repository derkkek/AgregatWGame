#include "Engine.h"
#include <iostream>

namespace Agregat
{
	Engine::Engine()
		:graphics(*this), input(*this), sound(*this)
	{
		Init();
	}
	
	Engine::~Engine()
	{
	}

	void Engine::Init()
	{
		graphics.Init();
		sound.Init();
	}

	void Engine::RunGameLoop(const UpdateCallback& callback)
	{
		while (!graphics.ShouldWindowClosed())
		{

			callback();
			graphics.Draw();
		}
	}
	void Engine::Shutdown()
	{
		sound.Shutdown();
		graphics.Shutdown();
	}
}
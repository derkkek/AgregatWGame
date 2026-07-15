#include "InputManager.h"
#include "spdlog/spdlog.h"
#include "raylib.h"

namespace Agregat
{
	InputManager::InputManager(Engine& e)
		:engine(e)
	{

	}
	InputManager::~InputManager()
	{
	}
	void InputManager::Update()
	{
	}
	bool InputManager::KeyIsPressed(int key)
	{
		return IsKeyPressed(key);
	}
}


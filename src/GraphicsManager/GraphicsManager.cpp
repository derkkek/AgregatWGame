#include "GraphicsManager.h"
#include "../Engine.h"
#include <raylib.h>

namespace Agregat
{
	GraphicsManager::GraphicsManager(Engine& e)
		:engine(e)
	{
	}
	GraphicsManager::~GraphicsManager()
	{
	}

	void GraphicsManager::Init()
	{
		InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

		SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	}
	void GraphicsManager::Draw()
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}

	bool GraphicsManager::ShouldWindowClosed()
	{
		return WindowShouldClose();
	}

}


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

		camera = { 0 };
		camera.position = Vector3{ 0.0f, 3.0f, 3.0f };
		camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
		camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
		camera.fovy = 45.0f;
		camera.projection = CAMERA_PERSPECTIVE;

		model = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));

		DisableCursor();
		SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	}
	void GraphicsManager::Draw()
	{
		UpdateCamera(&camera, CAMERA_FREE);

		BeginDrawing();

		ClearBackground(RAYWHITE);

		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		
		BeginMode3D(camera);
		
		DrawModel(model, Vector3{ 0.0, 0.0, 0.0 }, 1.0f, RED);
		
		EndMode3D();


		EndDrawing();
		
	}

	bool GraphicsManager::ShouldWindowClosed()
	{
		return WindowShouldClose();
	}

	void GraphicsManager::Shutdown()
	{
		UnloadModel(model);
		CloseWindow();
	}

}


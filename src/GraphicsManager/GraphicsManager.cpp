#include "GraphicsManager.h"
#include "GraphicsManager.h"
#include "../Engine.h"
#include <raylib.h>
#include "Geometries.h"

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
		camera.position = Vector3{ 0.0f, 6.0f, 6.0f };
		camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
		camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
		camera.fovy = 45.0f;
		camera.projection = CAMERA_PERSPECTIVE;

		LoadMeshData();
		engine.resource.LoadShader("shaders/default.vs", "shaders/default.fs", "default");
		model.materials[0].shader = nameToShaderHashMap["default"];

		lightPos = Vector3{ 0.0f, -3.0f, 0.0f };

		DisableCursor();
		SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	}
	void GraphicsManager::Draw()
	{
		UpdateCamera(&camera, CAMERA_FREE);

		BeginDrawing();

		ClearBackground(RAYWHITE);

		Shader shader = nameToShaderHashMap["default"];
		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		int lightPos = GetShaderLocation(shader, "lightPos");
		int lightColor = GetShaderLocation(shader, "lightColor");

		Vector3 lightCol = Vector3{ 1,1,1 };
		SetShaderValue(shader, lightPos, &this->lightPos, SHADER_UNIFORM_VEC3);
		SetShaderValue(shader, lightColor, &lightCol, SHADER_UNIFORM_VEC3);
		
		BeginMode3D(camera);
		
		DrawModelEx(model, Vector3{ 0,0,0 }, Vector3{ 1.0, 0.0, 0.0 }, 180, Vector3{ 1,1,1 }, WHITE);
		
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

	void GraphicsManager::LoadMeshData()
	{
		int vertexCount = sizeof(planeVertices) / (8 * sizeof(float)); // 6
		mesh = engine.resource.LoadMeshFromInterleavedData(planeVertices, vertexCount, 8);
		model = LoadModelFromMesh(mesh);
		engine.resource.LoadTexture("textures/wood.png", "wood");
		model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = nameToTextureHashMap["wood"];
	}

}


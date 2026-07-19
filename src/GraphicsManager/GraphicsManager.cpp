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
		SetConfigFlags(FLAG_MSAA_4X_HINT);
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
		
		lightPos = Vector3{ 0.0f, 1.0f, 0.0f };

		DisableCursor();
		
		SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	}
	void GraphicsManager::Draw()
	{
		UpdateCamera(&camera, CAMERA_FREE);

		BeginDrawing();

		ClearBackground(CLITERAL(Color){20,20,20,255});
		

		Shader shader = nameToShaderHashMap["default"];
		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		int lightPos = GetShaderLocation(shader, "lightPos");
		int lightColor = GetShaderLocation(shader, "lightColor");
		int viewPos = GetShaderLocation(shader, "viewPos");

		Vector3 lightCol = Vector3{ 1,1,1 };
		SetShaderValue(shader, lightPos, &this->lightPos, SHADER_UNIFORM_VEC3);
		SetShaderValue(shader, lightColor, &lightCol, SHADER_UNIFORM_VEC3);
		SetShaderValue(shader, viewPos, &camera.position, SHADER_UNIFORM_VEC3);
		
		BeginMode3D(camera);
		
		DrawModel(model, Vector3{ 0,0,0 }, 1.0f, WHITE);
		
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
		SetTextureFilter(nameToTextureHashMap["wood"], TEXTURE_FILTER_BILINEAR);
		model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = nameToTextureHashMap["wood"];
	}

}


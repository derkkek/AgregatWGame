#pragma once
#include "Types.h"
#include "raylib.h"
#include <unordered_map>
#include <string>
namespace Agregat
{
	class Engine;

	class GraphicsManager
	{
	public:
		GraphicsManager(Engine& e);
		~GraphicsManager();

		void Init();
		void Draw();
		bool ShouldWindowClosed();
		void Shutdown();
		std::unordered_map<std::string, Texture2D> nameToTextureHashMap;
		std::unordered_map<std::string, Shader> nameToShaderHashMap;

	private:
		Engine& engine;
		Camera camera;
		Model model;
		Mesh mesh;
		Vector3 lightPos;
		const int screenWidth = 1600;
		const int screenHeight = 900;
		bool shouldCloseWindow;

		void LoadMeshData();

	};

}
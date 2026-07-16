#pragma once
#include "Types.h"
#include "raylib.h"
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

	private:
		Engine& engine;
		Camera camera;
		Model model;
		const int screenWidth = 800;
		const int screenHeight = 450;
		bool shouldCloseWindow;
	};

}
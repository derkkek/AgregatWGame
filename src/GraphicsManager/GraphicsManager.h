#pragma once
#include "Types.h"
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

	private:
		Engine& engine;

		const int screenWidth = 800;
		const int screenHeight = 450;
		bool shouldCloseWindow;
	};

}
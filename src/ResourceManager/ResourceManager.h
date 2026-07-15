#pragma once
#include "Types.h"
#include <filesystem>
#include <string>
namespace Agregat
{
	class ResourceManager
	{
	public:
		ResourceManager(Engine& e);
		~ResourceManager() = default;

		std::string ResolvePath(const std::string& relativePath);
		void SetRootPath(const std::string& path);

		bool LoadSound(const std::string& relativePath, const std::string& name);

	private:
		Engine& engine;

		std::filesystem::path root = "assets";
	};
}

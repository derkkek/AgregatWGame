#include "ResourceManager.h"
#include "../Engine.h"
#include <raylib.h>
#include "spdlog/spdlog.h"

namespace Agregat
{
	ResourceManager::ResourceManager(Engine& e)
		:engine(e), root("assets")
	{
	
	}
	std::string ResourceManager::ResolvePath(const std::string& relativePath)
	{
		return (root / relativePath).string();
	}
	void ResourceManager::SetRootPath(const std::string& path)
	{
		this->root = path;
	}
	bool ResourceManager::LoadSound(const std::string& relativePath, const std::string& name)
	{
		const std::string& resolvedPath = ResolvePath(relativePath);

		if(!resolvedPath.empty())
		{
			// Call the global raylib free function
			Sound sound = ::LoadSound(resolvedPath.c_str());
			engine.sound.nameSoundHashMap[name] = sound;
			spdlog::info("sound: " + name + " has loaded");
			return true;
		}

		return false;
	}
}
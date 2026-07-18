#include "ResourceManager.h"
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
			spdlog::info("SOUND: " + name + " has loaded");
			return true;
		}

		return false;
	}
	bool ResourceManager::LoadTexture(const std::string& relativePath, const std::string& name)
	{
		const std::string& resolvedPath = ResolvePath(relativePath);
		if (!resolvedPath.empty())
		{
			Texture2D texture = ::LoadTexture(resolvedPath.c_str());
			engine.graphics.nameToTextureHashMap[name] = texture;
			spdlog::info("TEXTURE: " + name + " has loaded");
			return true;
		}
		return false;
	}
	Mesh ResourceManager::LoadMeshFromInterleavedData(const float* vertexData, int vertexCount, int stride)
	{
		Mesh mesh = { 0 };

		mesh.vertexCount = vertexCount;
		mesh.triangleCount = vertexCount / 3;
		mesh.vertices = (float*)MemAlloc(vertexCount * 3 * sizeof(float));
		mesh.normals = (float*)MemAlloc(vertexCount * 3 * sizeof(float));
		mesh.texcoords = (float*)MemAlloc(vertexCount * 2 * sizeof(float));

		for (int i = 0; i < vertexCount; i++)
		{
			const float* v = &vertexData[i * stride];

			mesh.vertices[i * 3 + 0] = v[0];
			mesh.vertices[i * 3 + 1] = v[1];
			mesh.vertices[i * 3 + 2] = v[2];

			mesh.normals[i * 3 + 0] = v[3];
			mesh.normals[i * 3 + 1] = v[4];
			mesh.normals[i * 3 + 2] = v[5];

			mesh.texcoords[i * 2 + 0] = v[6];
			mesh.texcoords[i * 2 + 1] = v[7];
		}

		UploadMesh(&mesh, false);
		return mesh;
	}
}
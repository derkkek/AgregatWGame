#pragma once
#include "Types.h"
#include <filesystem>
#include <string>
#include "raylib.h"
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
		bool LoadTexture(const std::string& relativePath, const std::string& name);
		bool LoadShader(const std::string& relativePathVertex, const std::string& relativePathFragment, const std::string& name);

		/* Converts interleaved [pos.xyz, normal.xyz, uv.xy] data (8 (stride) floats/vertex) into raylib's SoA Mesh format and uploads it to the GPU.*/
		Mesh LoadMeshFromInterleavedData(const float* vertexData, int vertexCount, int stride);

	private:
		Engine& engine;

		std::filesystem::path root = "assets";
	};
}

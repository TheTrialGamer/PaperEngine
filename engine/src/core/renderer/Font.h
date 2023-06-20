#pragma once

#include "Engine.h"
#include "utility.h"

#include "renderer/Texture.h"

#include "renderer/MSDFData.h"

#include <filesystem>

namespace engine
{
	class Font
	{
	public:
		Font(std::string fileString);
		~Font();

		MSDFData* GetMSDFData() const { return data; };
		Shr<Texture> GetAtlasTexture() const { return atlasTexture; };

		//static Shr<Font> GetFont(std::string fontPath);

	private:
		MSDFData* data;
		std::string fontPath;
		Shr<Texture> atlasTexture;
	};

};
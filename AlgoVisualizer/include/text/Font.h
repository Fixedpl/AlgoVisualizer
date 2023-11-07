#pragma once
#include <iostream>
#include <unordered_map>
#include <glm/glm.hpp>
#include "OpenGL/GL_Texture.h"

#include "dll_algo.h"


struct CharacterDescription
{
	AV_API CharacterDescription();

	float width, height;
	float bearing_left, bearing_right, bearing_bot, bearing_top;
	float advance;
	float size;
	glm::vec2 glyph_coords[4];
};

class Font
{
public:

	AV_API Font(const std::string& font_texture_path, const std::string& font_description_path);

	AV_API CharacterDescription getCharacterDescription(const uint32_t& ascii_code) const;

	AV_API OpenGL::TextureData loadFontTexture();
	AV_API void releaseFontTexture();

	AV_API OpenGL::TextureData getFontData() const;

private:

	AV_API void loadCharacters(const std::string& path);

private:

	std::unordered_map<uint32_t, CharacterDescription> m_characters;

	OpenGL::TextureData m_font_texture;

	std::string m_font_texture_path;
};


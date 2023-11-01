#include "Font.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <stb_image/stb_image.h>

using json = nlohmann::json;


CharacterDescription::CharacterDescription()
	:
	width(0.0f),
	height(0.0f),
	bearing_left(0.0f),
	bearing_right(0.0f),
	bearing_bot(0.0f),
	bearing_top(0.0f),
	advance(0.0f),
	size(0.0f)
{
}

Font::Font(const std::string& font_texture_path, const std::string& font_description_path)
	:
	m_font_texture_path(font_texture_path)
{
	loadCharacters(font_description_path);
}

CharacterDescription Font::getCharacterDescription(const uint32_t& ascii_code) const
{
	return m_characters.at(ascii_code);
}

OpenGL::TextureData Font::loadFontTexture()
{
	stbi_set_flip_vertically_on_load(1);

	int width, height, bpp;
	m_font_texture.data = stbi_load(m_font_texture_path.c_str(), &width, &height, &bpp, 4);
	if (!m_font_texture.data) {
		std::cout << "[ERROR] Font.cpp: Couldn't find font texture\n";
	}
	m_font_texture.width = width;
	m_font_texture.height = height;
	return m_font_texture;
}

void Font::releaseFontTexture()
{
	stbi_image_free(m_font_texture.data);
}

void Font::loadCharacters(const std::string& font_path)
{
	std::ifstream file(font_path);

	if (file.is_open()) {
		std::string whole_file;
		file >> whole_file;

		json top = json::parse(whole_file);

		json atlas_info = top["atlas"];
		json glyphs = top["glyphs"];
		json kerning = top["kerning"];

		float atlas_width = std::stoi(atlas_info["width"].dump());
		float atlas_height = std::stoi(atlas_info["height"].dump());

		for (auto& glyph : glyphs) {
			uint8_t ascii_code = glyph["unicode"];
			CharacterDescription& character = m_characters[ascii_code];

			float advance = std::stof(glyph["advance"].dump());
			float size = std::stof(atlas_info["size"].dump());

			character.advance = advance;
			character.size = size;

			if (ascii_code == ' ') {
				continue;
			}

			json atlas_bounds = glyph["atlasBounds"];
			json plane_bounds = glyph["planeBounds"];

			uint32_t left_coord = std::stoi(atlas_bounds["left"].dump());
			uint32_t right_coord = std::stoi(atlas_bounds["right"].dump());
			uint32_t bot_coord = std::stoi(atlas_bounds["bottom"].dump());
			uint32_t top_coord = std::stoi(atlas_bounds["top"].dump());

			float left_bound = std::stof(plane_bounds["left"].dump());
			float bot_bound = std::stof(plane_bounds["bottom"].dump());
			float right_bound = std::stof(plane_bounds["right"].dump());
			float top_bound = std::stof(plane_bounds["top"].dump());


			character.width = right_coord - left_coord;
			character.height = top_coord - bot_coord;

			character.bearing_left = left_bound;
			character.bearing_bot = bot_bound;
			character.bearing_right = right_bound;
			character.bearing_top = top_bound;

			character.glyph_coords[0] = glm::vec2(left_coord, top_coord);
			character.glyph_coords[1] = glm::vec2(left_coord, bot_coord);
			character.glyph_coords[2] = glm::vec2(right_coord, bot_coord);
			character.glyph_coords[3] = glm::vec2(right_coord, top_coord);
		}

	}
	else {
		std::cout << "[ERROR]Font.cpp: Couldn't open file \n";
	}
	file.close();
}

OpenGL::TextureData Font::getFontData() const
{
	return m_font_texture;
}

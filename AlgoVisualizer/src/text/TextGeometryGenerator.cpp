#include "TextGeometryGenerator.h"


CharacterBufferArray* TextGeometryGenerator::generate(const Text& text)
{
	CharacterBufferArray* text_buffer = new CharacterBufferArray(text.text.length());
	SingleTextGeometryGenerator(text).generate(text_buffer->character_arr);
	return text_buffer;
}

TextBufferArray* TextGeometryGenerator::generate(const std::vector<Text>& texts)
{
	int summary_length = 0;
	for (auto& text : texts) {
		summary_length += text.text.length();
	}
	TextBufferArray* buffer_array = new TextBufferArray(summary_length);
	int index = 0;
	for (auto& text : texts) {
		SingleTextGeometryGenerator(text).generate(buffer_array->character_arr->character_arr + index);
		index += text.text.length();
	}
	return buffer_array;
}

TextGeometryGenerator::SingleTextGeometryGenerator::SingleTextGeometryGenerator(const Text& text)
	:
	text_str(text.text),
	props(text.props),
	font(*text.font),
	alignment(text.alignment)
{
}

void TextGeometryGenerator::SingleTextGeometryGenerator::generate(CharacterBuffer buffer_arr[])
{
	z_fight = 0.0001f;

	int text_length = text_str.length();

	font_size_portion = props.font_size / 48.0f;

	float x_offset = 0.0f;

	calculateAlignment();

	for (int i = 0; i < text_length; i++) {
		CharacterBuffer& char_buffer = buffer_arr[i];

		char letter = text_str[i];
		CharacterDescription char_desc = font.getCharacterDescription(letter);
		
		fillCharBuffer(char_buffer, char_desc);

		glm::vec3 text_shift = glm::vec3(0.0f);
		text_shift.x = x_offset + char_desc.bearing_left * char_desc.size * font_size_portion;
		text_shift.y = char_desc.bearing_bot * char_desc.size * font_size_portion;

		char_buffer.vertices[0].position += text_shift + glm::vec3(horizontal_alignment, vertical_alignment, z_fight);
		char_buffer.vertices[1].position += text_shift + glm::vec3(horizontal_alignment, vertical_alignment, z_fight);
		char_buffer.vertices[2].position += text_shift + glm::vec3(horizontal_alignment, vertical_alignment, z_fight);
		char_buffer.vertices[3].position += text_shift + glm::vec3(horizontal_alignment, vertical_alignment, z_fight);

		z_fight += 0.0001f;
		x_offset += char_desc.advance * char_desc.size * font_size_portion;
	}
}

void TextGeometryGenerator::SingleTextGeometryGenerator::fillCharBuffer(CharacterBuffer& buffer, const CharacterDescription& char_desc)
{
	CharacterVertex& top_left = buffer.vertices[0];
	CharacterVertex& bot_left = buffer.vertices[1];
	CharacterVertex& bot_right = buffer.vertices[2];
	CharacterVertex& top_right = buffer.vertices[3];

	int letter_width = char_desc.width * font_size_portion;
	int letter_height = char_desc.height * font_size_portion;

	OpenGL::TextureData font_texture = font.getFontData();
	glm::vec2 font_texture_size = glm::vec2(font_texture.width, font_texture.height);

	top_left.position = props.position + glm::vec3(0.0f, letter_height, 0.0f);
	top_left.color = props.color;
	top_left.tex_coord = char_desc.glyph_coords[0] / font_texture_size;
	top_left.aa_low = props.aa_low;
	top_left.aa_high = props.aa_hight;

	bot_left.position = props.position;
	bot_left.color = props.color;
	bot_left.tex_coord = char_desc.glyph_coords[1] / font_texture_size;
	bot_left.aa_low = props.aa_low;
	bot_left.aa_high = props.aa_hight;

	bot_right.position = props.position + glm::vec3(letter_width, 0.0f, 0.0f);
	bot_right.color = props.color;
	bot_right.tex_coord = char_desc.glyph_coords[2] / font_texture_size;
	bot_right.aa_low = props.aa_low;
	bot_right.aa_high = props.aa_hight;

	top_right.position = props.position + glm::vec3(letter_width, letter_height, 0.0f);
	top_right.color = props.color;
	top_right.tex_coord = char_desc.glyph_coords[3] / font_texture_size;
	top_right.aa_low = props.aa_low;
	top_right.aa_high = props.aa_hight;
}

void TextGeometryGenerator::SingleTextGeometryGenerator::calculateAlignment()
{
	int text_length = text_str.length();

	float lowest_y = 0.0f;
	float highest_y = 0.0f;
	float width = 0.0f;
	for (int i = 0; i < text_length; i++) {
		char letter = text_str[i];
		CharacterDescription char_desc = font.getCharacterDescription(letter);

		highest_y = std::max(char_desc.height * font_size_portion +
			char_desc.bearing_bot * char_desc.size * font_size_portion, highest_y);
		lowest_y = std::min(char_desc.bearing_bot * char_desc.size * font_size_portion, lowest_y);
		width += char_desc.advance * char_desc.size * font_size_portion;
	}

	vertical_alignment = 0.0f;
	if (alignment == TextAlignment::LEFT_CORNER) {
		vertical_alignment = std::abs(lowest_y);
	}
	else if (alignment == TextAlignment::CENTER) {
		float vertical_center = (highest_y - lowest_y) / 2.0f;
		vertical_alignment = (vertical_center + lowest_y) * -1.0f;
	}
	horizontal_alignment = alignment == TextAlignment::CENTER ? -1.0f * (width / 2.0f) : 0.0f;
}


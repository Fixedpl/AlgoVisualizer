#include "TextBufferFiller.h"

#include "FontDescriptor.h"



TextBufferArray* TextBufferFiller::generate(Entity& text)
{
	TextProps text_props = text.get<TextProps>();
	TextBufferArray* text_buffer = new TextBufferArray(text_props.text.length());
	SingleTextGeometryGenerator(text).fill(text_buffer->character_arr->character_arr);
	return text_buffer;
}

TextBufferArray* TextBufferFiller::generate(std::vector<Entity>& texts)
{
	int summary_length = 0;
	for (auto& text : texts) {
		TextProps text_props = text.get<TextProps>();
		summary_length += text_props.text.length();
	}
	TextBufferArray* buffer_array = new TextBufferArray(summary_length);
	int index = 0;
	for (auto& text : texts) {
		TextProps text_props = text.get<TextProps>();
		SingleTextGeometryGenerator(text).fill(buffer_array->character_arr->character_arr + index);
		index += text_props.text.length();
	}
	return buffer_array;
}

void TextBufferFiller::update(Entity& text, CharacterBuffer* character_arr)
{
	SingleTextGeometryGenerator(text).fill(character_arr);
}

TextBufferFiller::SingleTextGeometryGenerator::SingleTextGeometryGenerator(Entity& text)
{
	transform = text.get<Transform>();
	color = text.get<Color>();
	text_props = text.get<TextProps>();
	font = FontDescriptor::inst()->getFontDescriptor(text_props.font);
}

void TextBufferFiller::SingleTextGeometryGenerator::fill(CharacterBuffer buffer_arr[])
{
	z_fight = 0.0001f;

	int text_length = text_props.text.length();

	font_size_portion = text_props.font_size / 48.0f;

	float x_offset = 0.0f;

	calculateAlignment();

	for (int i = 0; i < text_length; i++) {
		CharacterBuffer& char_buffer = buffer_arr[i];

		char letter = text_props.text[i];
		CharacterDescription char_desc = font->getCharacterDescription(letter);

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

void TextBufferFiller::SingleTextGeometryGenerator::fillCharBuffer(CharacterBuffer& buffer, const CharacterDescription& char_desc)
{
	CharacterVertex& top_left = buffer.vertices[0];
	CharacterVertex& bot_left = buffer.vertices[1];
	CharacterVertex& bot_right = buffer.vertices[2];
	CharacterVertex& top_right = buffer.vertices[3];

	int letter_width = char_desc.width * font_size_portion;
	int letter_height = char_desc.height * font_size_portion;

	OpenGL::TextureData font_texture = font->getFontData();
	glm::vec2 font_texture_size = glm::vec2(font_texture.width, font_texture.height);

	top_left.position = transform.pos + glm::vec3(0.0f, letter_height, 0.0f);
	top_left.color = color.col;
	top_left.tex_coord = char_desc.glyph_coords[0] / font_texture_size;
	top_left.aa_low = text_props.aa_low;
	top_left.aa_high = text_props.aa_hight;

	bot_left.position = transform.pos;
	bot_left.color = color.col;
	bot_left.tex_coord = char_desc.glyph_coords[1] / font_texture_size;
	bot_left.aa_low = text_props.aa_low;
	bot_left.aa_high = text_props.aa_hight;

	bot_right.position = transform.pos + glm::vec3(letter_width, 0.0f, 0.0f);
	bot_right.color = color.col;
	bot_right.tex_coord = char_desc.glyph_coords[2] / font_texture_size;
	bot_right.aa_low = text_props.aa_low;
	bot_right.aa_high = text_props.aa_hight;

	top_right.position = transform.pos + glm::vec3(letter_width, letter_height, 0.0f);
	top_right.color = color.col;
	top_right.tex_coord = char_desc.glyph_coords[3] / font_texture_size;
	top_right.aa_low = text_props.aa_low;
	top_right.aa_high = text_props.aa_hight;
}

void TextBufferFiller::SingleTextGeometryGenerator::calculateAlignment()
{
	int text_length = text_props.text.length();

	float lowest_y = 0.0f;
	float highest_y = 0.0f;
	float width = 0.0f;
	for (int i = 0; i < text_length; i++) {
		char letter = text_props.text[i];
		CharacterDescription char_desc = font->getCharacterDescription(letter);

		highest_y = std::max(char_desc.height * font_size_portion +
			char_desc.bearing_bot * char_desc.size * font_size_portion, highest_y);
		lowest_y = std::min(char_desc.bearing_bot * char_desc.size * font_size_portion, lowest_y);
		width += char_desc.advance * char_desc.size * font_size_portion;
	}

	vertical_alignment = 0.0f;
	if (text_props.alignment == TextAlignment::LEFT_CORNER) {
		vertical_alignment = std::abs(lowest_y);
	}
	else if (text_props.alignment == TextAlignment::CENTER) {
		float vertical_center = (highest_y - lowest_y) / 2.0f;
		vertical_alignment = (vertical_center + lowest_y) * -1.0f;
	}
	horizontal_alignment = text_props.alignment == TextAlignment::CENTER ? -1.0f * (width / 2.0f) : 0.0f;
}

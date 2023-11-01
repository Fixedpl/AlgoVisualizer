#pragma once
#include <vector>
#include "Text.h"
#include "Font.h"




class TextGeometryGenerator
{
public:

	static CharacterBufferArray* generate(const Text& text);
	static TextBufferArray* generate(const std::vector<Text>& texts);

private:

	class SingleTextGeometryGenerator
	{
	public:

		SingleTextGeometryGenerator(const Text& text);

		void generate(CharacterBuffer buffer_arr[]);

	private:

		void fillCharBuffer(CharacterBuffer& vertex, const CharacterDescription& char_desc);

		void calculateAlignment();

	private:

		const std::string& text_str;
		const TextProperties& props;
		const Font& font;
		TextAlignment alignment;

		float horizontal_alignment;
		float vertical_alignment;

		float font_size_portion;
		float font_sharpness;

		float z_fight;
	};

};



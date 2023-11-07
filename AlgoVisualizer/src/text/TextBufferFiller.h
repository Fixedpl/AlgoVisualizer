#pragma once
#include <vector>
#include "text/TextBuffer.h"
#include "text/Font.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"


class TextBufferFiller
{
public:

	static TextBufferArray* generate(Entity& text);
	static TextBufferArray* generate(std::vector<Entity>& texts);
	static void update(Entity& text, CharacterBuffer* character_arr);

private:

	class SingleTextGeometryGenerator
	{
	public:

		SingleTextGeometryGenerator(Entity& text);

		void fill(CharacterBuffer buffer_arr[]);

	private:

		void fillCharBuffer(CharacterBuffer& vertex, const CharacterDescription& char_desc);

		void calculateAlignment();

	private:

		Transform transform;
		Color color;
		TextProps text_props;
		Font* font;

		float horizontal_alignment;
		float vertical_alignment;

		float font_size_portion;
		float font_sharpness;

		float z_fight;
	};

};




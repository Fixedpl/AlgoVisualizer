#pragma once
#include <vector>
#include "text/TextBuffer.h"
#include "text/Font.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"

#include "dll_algo.h"


class TextBufferFiller
{
public:

	AV_API static TextBufferArray* generate(Entity& text);
	AV_API static TextBufferArray* generate(std::vector<Entity>& texts);
	AV_API static void update(Entity& text, CharacterBuffer* character_arr);

private:

	class SingleTextGeometryGenerator
	{
	public:

		AV_API SingleTextGeometryGenerator(Entity& text);

		AV_API void fill(CharacterBuffer buffer_arr[]);

	private:

		AV_API void fillCharBuffer(CharacterBuffer& vertex, const CharacterDescription& char_desc);

		AV_API void calculateAlignment();

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




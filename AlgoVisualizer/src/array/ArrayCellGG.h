#pragma once
#include "rectangle/RectangleBuffer.h"
#include "text/TextBuffer.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"


struct ArrayCellBuffer
{
	RectangleBufferArray* rect_buffer;
	TextBufferArray* text_buffer;
};


class ArrayCellGG
{
public:

	static ArrayCellBuffer generate(Entity& array_cell);
	static void generate(Entity& array_cell, RectangleBuffer* rect_buffer, CharacterBuffer* text_buffer);

	class SimpleArrayCellGG
	{
	public:

		SimpleArrayCellGG(Entity& array_cell);

		void generate(RectangleBuffer* rect_buffer, CharacterBuffer* text_buffer);

	private:

		ArrayCellProps& cell_props;
	};


};


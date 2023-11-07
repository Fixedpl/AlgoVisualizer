#pragma once
#include "rectangle/RectangleBuffer.h"
#include "text/TextBuffer.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"

#include "dll_algo.h"


struct ArrayCellBuffer
{
	RectangleBufferArray* rect_buffer;
	TextBufferArray* text_buffer;
};


class ArrayCellGG
{
public:

	AV_API static ArrayCellBuffer generate(Entity& array_cell);
	AV_API static void update(Entity& array_cell, RectangleBuffer* rect_buffer, CharacterBuffer* text_buffer);

	class SimpleArrayCellGG
	{
	public:

		AV_API SimpleArrayCellGG(Entity& array_cell);

		AV_API void fill(RectangleBuffer* rect_buffer, CharacterBuffer* text_buffer);

	private:

		ArrayCellProps& cell_props;
	};


};


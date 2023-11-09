#pragma once
#include "text/TextBuffer.h"
#include "rectangle/RectangleBuffer.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"

#include "dll_algo.h"


struct ArrayBuffer
{
	RectangleBufferArray* rect_buffer;
	TextBufferArray* text_buffer;
};

class ArrayGG
{
public:

	AV_API static ArrayBuffer generate(Entity& array);
	AV_API static void update(Entity& array, RectangleBufferArray* rect_buffer_array,
		TextBufferArray* text_buffer_array);

	class SimpleArrayGG
	{
	public:

		AV_API SimpleArrayGG(Entity& array);

		AV_API void fill(RectangleBuffer* rect_buffer, CharacterBuffer* text_buffer);

	private:

		ArrayProps& props;
	};


};


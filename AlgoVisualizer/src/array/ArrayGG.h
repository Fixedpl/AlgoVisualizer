#pragma once
#include "text/TextBuffer.h"
#include "rectangle/RectangleBuffer.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"


struct ArrayBuffer
{
	RectangleBufferArray* rect_buffer;
	TextBufferArray* text_buffer;
};

class ArrayGG
{
public:

	static ArrayBuffer generate(Entity& array);
	static void update(Entity& array, RectangleBufferArray* rect_buffer_array,
		TextBufferArray* text_buffer_array);

	class SimpleArrayGG
	{
	public:

		SimpleArrayGG(Entity& array);

		void fill(RectangleBufferArray* rect_buffer_array, TextBufferArray* text_buffer_array);

	private:

		ArrayProps& props;
	};


};


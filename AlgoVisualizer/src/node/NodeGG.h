#pragma once
#include "text/TextBuffer.h"
#include "circle/CircleBuffer.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"


struct NodeBuffer
{
	CircleBufferArray* circle_buffer;
	TextBufferArray* text_buffer;
};

class NodeGG
{
public:

	static NodeBuffer generate(Entity& node);
	static void update(Entity& array, CircleBufferArray* circle_buffer_array, 
		TextBufferArray* text_buffer_array);

	class SimpleNodeGG
	{
	public:

		SimpleNodeGG(Entity& node);

		void fill(CircleBufferArray* circle_buffer_array, TextBufferArray* text_buffer_array);

	private:

		NodeProps& props;
	};

};



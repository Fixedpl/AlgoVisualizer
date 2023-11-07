#pragma once
#include "text/TextBuffer.h"
#include "circle/CircleBuffer.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"

#include "dll_algo.h"


struct NodeBuffer
{
	CircleBufferArray* circle_buffer;
	TextBufferArray* text_buffer;
};

class NodeGG
{
public:

	AV_API static NodeBuffer generate(Entity& node);
	AV_API static void update(Entity& array, CircleBufferArray* circle_buffer_array,
		TextBufferArray* text_buffer_array);

	class SimpleNodeGG
	{
	public:

		AV_API SimpleNodeGG(Entity& node);

		AV_API void fill(CircleBufferArray* circle_buffer_array, TextBufferArray* text_buffer_array);

	private:

		NodeProps& props;
	};

};



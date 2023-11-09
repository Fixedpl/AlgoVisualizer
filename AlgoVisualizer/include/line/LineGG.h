#pragma once
#include "rectangle/RectangleBuffer.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"

#include "dll_algo.h"



class LineGG
{
public:

	AV_API static RectangleBufferArray* generate(Entity& line);

	class SimpleLineGG
	{
	public:

		AV_API SimpleLineGG(Entity& line);

		AV_API void fill(RectangleBuffer* rect_buffer);

	private:

		LineProps& props;
	};

};

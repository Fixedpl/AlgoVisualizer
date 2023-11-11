#pragma once
#include <vector>
#include "Entity/Entity.h"
#include "LineBuffer.h"
#include "BaseComponents.h"

#include "dll_algo.h"


class LineBufferFiller
{
public:

	AV_API static LineBufferArray* generate(Entity& line);
	AV_API static void update(Entity& line, LineBuffer* buffer);

private:

	class SingleLineGG
	{
	public:

		AV_API SingleLineGG(Entity& line);

		AV_API void fill(LineBuffer& buffer);

	private:

		AV_API void fillVertex(LineVertex& vertex);

	private:

		Transform transform;
		Color color;
		Border border;
		LineProps props;

		float len;
	};

};



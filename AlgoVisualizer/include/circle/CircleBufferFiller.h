#pragma once
#include <vector>
#include "CircleBuffer.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"

#include "dll_algo.h"


class CircleBufferFiller
{
public:

	AV_API static CircleBufferArray* generate(Entity& circle);
	AV_API static CircleBufferArray* generate(std::vector<Entity>& circles);
	AV_API static void update(Entity& rect, CircleBuffer* buffer);

	class SingleCircleGeometryGenerator
	{
	public:

		AV_API SingleCircleGeometryGenerator(Entity& circle);

		AV_API void fill(CircleBuffer& buffer);

	private:

		AV_API void fillVertex(CircleVertex& vertex);

	private:

		Transform transform;
		Color color;
		Border border;
		CircleProps circle_props;
	};

};



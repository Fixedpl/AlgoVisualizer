#pragma once
#include <vector>
#include "CircleBuffer.h"
#include "Entity/Entity.h"
#include "BaseComponents.h"


class CircleBufferFiller
{
public:

	static CircleBufferArray* generate(Entity& circle);
	static CircleBufferArray* generate(std::vector<Entity>& circles);
	static void update(Entity& rect, CircleBuffer* buffer);

	class SingleCircleGeometryGenerator
	{
	public:

		SingleCircleGeometryGenerator(Entity& circle);

		void fill(CircleBuffer& buffer);

	private:

		void fillVertex(CircleVertex& vertex);

	private:

		Transform transform;
		Color color;
		Border border;
		CircleProps circle_props;
	};

};



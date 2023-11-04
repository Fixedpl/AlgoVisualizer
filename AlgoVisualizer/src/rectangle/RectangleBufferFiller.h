#pragma once
#include <vector>
#include "Entity/Entity.h"
#include "RectangleBuffer.h"
#include "BaseComponents.h"


class RectangleBufferFiller
{
public:

	static RectangleBufferArray* generate(Entity& rect);
	static RectangleBufferArray* generate(std::vector<Entity>& rects);
	static void update(Entity& rect, RectangleBuffer* buffer);

private:

	class SingleRectangleGeometryGenerator
	{
	public:

		SingleRectangleGeometryGenerator(Entity& rect);

		void fill(RectangleBuffer& buffer);

	private:

		void fillVertex(RectangleVertex& vertex);

	private:

		Transform transform;
		Color color;
		Border border;
		RectProps rect_props;
	};

};



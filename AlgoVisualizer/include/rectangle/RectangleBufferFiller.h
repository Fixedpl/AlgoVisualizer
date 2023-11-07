#pragma once
#include <vector>
#include "Entity/Entity.h"
#include "RectangleBuffer.h"
#include "BaseComponents.h"

#include "dll_algo.h"


class RectangleBufferFiller
{
public:

	AV_API static RectangleBufferArray* generate(Entity& rect);
	AV_API static RectangleBufferArray* generate(std::vector<Entity>& rects);
	AV_API static void update(Entity& rect, RectangleBuffer* buffer);

private:

	class SingleRectangleGeometryGenerator
	{
	public:

		AV_API SingleRectangleGeometryGenerator(Entity& rect);

		AV_API void fill(RectangleBuffer& buffer);

	private:

		AV_API void fillVertex(RectangleVertex& vertex);

	private:

		Transform transform;
		Color color;
		Border border;
		RectProps rect_props;
	};

};



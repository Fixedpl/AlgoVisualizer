#pragma once
#include <vector>
#include "Rectangle.h"




class RectangleGeometryGenerator
{
public:

	static RectangleBuffer* generate(const RectangleProperties& props);
	static RectangleBufferArray* generate(const std::vector<RectangleProperties>& props);
	
private:

	class SingleRectangleGeometryGenerator
	{
	public:

		SingleRectangleGeometryGenerator(const RectangleProperties& props);

		void generate(RectangleBuffer& buffer);

	private:

		void fillVertex(RectangleVertex& vertex);

	private:

		const RectangleProperties& props;

	};

};


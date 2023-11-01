#pragma once
#include <vector>
#include "Circle.h"



class CircleGeometryGenerator
{
public:

	static CircleBuffer* generate(const CircleProperties& props);
	static CircleBufferArray* generate(const std::vector<CircleProperties>& props);
	
	class SingleCircleGeometryGenerator
	{
	public:

		SingleCircleGeometryGenerator(const CircleProperties& props);

		void generate(CircleBuffer& buffer);

	private:

		void fillVertex(CircleVertex& vertex);

	private:

		const CircleProperties& props;
	};

};

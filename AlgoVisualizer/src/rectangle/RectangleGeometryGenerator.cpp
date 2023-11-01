#include "RectangleGeometryGenerator.h"


RectangleBuffer* RectangleGeometryGenerator::generate(const RectangleProperties& props)
{
	RectangleBuffer* buffer = new RectangleBuffer();
	SingleRectangleGeometryGenerator(props).generate(*buffer);
	return buffer;
}

RectangleBufferArray* RectangleGeometryGenerator::generate(const std::vector<RectangleProperties>& props)
{
	int length = props.size();
	RectangleBufferArray* buffer_array = new RectangleBufferArray(length);
	for (int i = 0; i < length; i++) {
		SingleRectangleGeometryGenerator(props[i]).generate(buffer_array->buffer[i]);
	}
	return buffer_array;
}

void RectangleGeometryGenerator::SingleRectangleGeometryGenerator::generate(RectangleBuffer& buffer)
{
	RectangleVertex& top_left = buffer.vertices[0];
	fillVertex(top_left);
	top_left.position += glm::vec3(0.0f, props.size.y, 0.0f);

	RectangleVertex& bot_left = buffer.vertices[1];
	fillVertex(bot_left);

	RectangleVertex& bot_right = buffer.vertices[2];
	fillVertex(bot_right);
	bot_right.position += glm::vec3(props.size.x, 0.0f, 0.0f);

	RectangleVertex& top_right = buffer.vertices[3];
	fillVertex(top_right);
	top_right.position += glm::vec3(props.size.x, props.size.y, 0.0f);
}

void RectangleGeometryGenerator::SingleRectangleGeometryGenerator::fillVertex(RectangleVertex& vertex)
{
	vertex.position = props.position;
	vertex.color = props.color;
	vertex.size = props.size;
	vertex.bot_left_corner = props.position;
	vertex.radius = props.radius;
	vertex.border_width = props.border_width;
	vertex.border_color = props.border_color;
	vertex.sharpness = props.sharpness;
}

RectangleGeometryGenerator::SingleRectangleGeometryGenerator::SingleRectangleGeometryGenerator(const RectangleProperties& props)
	:
	props(props)
{
}

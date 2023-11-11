#include "RectangleBufferFiller.h"

#include <glm/gtx/rotate_vector.hpp>


RectangleBufferArray* RectangleBufferFiller::generate(Entity& rect)
{
	RectangleBufferArray* buffer_array = new RectangleBufferArray(1);
	SingleRectangleGeometryGenerator(rect).fill(buffer_array->buffer[0]);
	return buffer_array;
}

RectangleBufferArray* RectangleBufferFiller::generate(std::vector<Entity>& rects)
{
	int length = rects.size();
	RectangleBufferArray* buffer_array = new RectangleBufferArray(length);
	for (int i = 0; i < length; i++) {
		SingleRectangleGeometryGenerator(rects[i]).fill(buffer_array->buffer[i]);
	}
	return buffer_array;
}

void RectangleBufferFiller::update(Entity& rect, RectangleBuffer* buffer)
{
	SingleRectangleGeometryGenerator(rect).fill(*buffer);
}

RectangleBufferFiller::SingleRectangleGeometryGenerator::SingleRectangleGeometryGenerator(Entity& rect)
{
	transform = rect.get<Transform>();
	color = rect.get<Color>();
	border = rect.get<Border>();
	rect_props = rect.get<RectProps>();
}

void RectangleBufferFiller::SingleRectangleGeometryGenerator::fill(RectangleBuffer& buffer)
{
	RectangleVertex& top_left = buffer.vertices[0];
	fillVertex(top_left);
	top_left.position += glm::vec3(0.0f, rect_props.size.y, 0.0f);

	RectangleVertex& bot_left = buffer.vertices[1];
	fillVertex(bot_left);

	RectangleVertex& bot_right = buffer.vertices[2];
	fillVertex(bot_right);
	bot_right.position += glm::vec3(rect_props.size.x, 0.0f, 0.0f);

	RectangleVertex& top_right = buffer.vertices[3];
	fillVertex(top_right);
	top_right.position += glm::vec3(rect_props.size.x, rect_props.size.y, 0.0f);
}

void RectangleBufferFiller::SingleRectangleGeometryGenerator::fillVertex(RectangleVertex& vertex)
{
	vertex.position = transform.pos;
	vertex.color = color.col;
	vertex.size = rect_props.size;
	vertex.bot_left_corner = transform.pos;
	vertex.radius = rect_props.radius;
	vertex.border_width = border.width;
	vertex.border_color = border.color;
	vertex.sharpness = rect_props.sharpness;
}

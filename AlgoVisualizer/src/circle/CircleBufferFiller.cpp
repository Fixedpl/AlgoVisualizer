#include "CircleBufferFiller.h"



CircleBufferArray* CircleBufferFiller::generate(Entity& circle)
{
	CircleBufferArray* buffer_array = new CircleBufferArray(1);
	SingleCircleGeometryGenerator(circle).fill(buffer_array->buffer[0]);
	return buffer_array;
}

CircleBufferArray* CircleBufferFiller::generate(std::vector<Entity>& circles)
{
	int length = circles.size();
	CircleBufferArray* buffer_array = new CircleBufferArray(length);
	for (int i = 0; i < length; i++) {
		SingleCircleGeometryGenerator(circles[i]).fill(buffer_array->buffer[i]);
	}
	return buffer_array;
}

void CircleBufferFiller::update(Entity& rect, CircleBuffer* buffer)
{
	SingleCircleGeometryGenerator(rect).fill(*buffer);
}

CircleBufferFiller::SingleCircleGeometryGenerator::SingleCircleGeometryGenerator(Entity& circle)
{
	transform = circle.get<Transform>();
	color = circle.get<Color>();
	border = circle.get<Border>();
	circle_props = circle.get<CircleProps>();
}

void CircleBufferFiller::SingleCircleGeometryGenerator::fill(CircleBuffer& buffer)
{
	float twice_radius = circle_props.radius * 2;

	CircleVertex& top_left = buffer.vertices[0];
	fillVertex(top_left);
	top_left.position += glm::vec3(0.0f, twice_radius, 0.0f);

	CircleVertex& bot_left = buffer.vertices[1];
	fillVertex(bot_left);

	CircleVertex& bot_right = buffer.vertices[2];
	fillVertex(bot_right);
	bot_right.position += glm::vec3(twice_radius, 0.0f, 0.0f);

	CircleVertex& top_right = buffer.vertices[3];
	fillVertex(top_right);
	top_right.position += glm::vec3(twice_radius, twice_radius, 0.0f);
}

void CircleBufferFiller::SingleCircleGeometryGenerator::fillVertex(CircleVertex& vertex)
{
	vertex.position = transform.pos;
	vertex.center = glm::vec2(transform.pos) + glm::vec2(circle_props.radius);
	vertex.radius = circle_props.radius;
	vertex.color = color.col;
	vertex.border_width = border.width;
	vertex.border_color = border.color;
}

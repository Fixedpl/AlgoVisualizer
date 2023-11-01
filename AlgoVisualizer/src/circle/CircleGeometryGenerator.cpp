#include "CircleGeometryGenerator.h"


CircleBuffer* CircleGeometryGenerator::generate(const CircleProperties& props)
{
	CircleBuffer* circle_buffer = new CircleBuffer();
	SingleCircleGeometryGenerator(props).generate(*circle_buffer);
    return circle_buffer;
}

CircleBufferArray* CircleGeometryGenerator::generate(const std::vector<CircleProperties>& props)
{
	int length = props.size();
	CircleBufferArray* buffer_array = new CircleBufferArray(length);
	for (int i = 0; i < length; i++) {
		SingleCircleGeometryGenerator(props[i]).generate(buffer_array->buffer[i]);
	}
	return buffer_array;
}

CircleGeometryGenerator::SingleCircleGeometryGenerator::SingleCircleGeometryGenerator(const CircleProperties& props)
	:
	props(props)
{
}

void CircleGeometryGenerator::SingleCircleGeometryGenerator::generate(CircleBuffer& buffer)
{
	float twice_radius = props.radius * 2;

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

void CircleGeometryGenerator::SingleCircleGeometryGenerator::fillVertex(CircleVertex& vertex)
{
	vertex.position = props.position;
	vertex.center = glm::vec2(props.position) + glm::vec2(props.radius);
	vertex.radius = props.radius;
	vertex.color = props.color;
	vertex.border_width = props.border_width;
	vertex.border_color = props.border_color;
}

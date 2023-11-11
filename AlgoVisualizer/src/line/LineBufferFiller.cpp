#include "LineBufferFiller.h"

#include <glm/gtx/rotate_vector.hpp>


LineBufferArray* LineBufferFiller::generate(Entity& line)
{
	LineBufferArray* buffer_array = new LineBufferArray(1);
	SingleLineGG(line).fill(buffer_array->buffer[0]);
	return buffer_array;
}

void LineBufferFiller::update(Entity& line, LineBuffer* buffer)
{
	SingleLineGG(line).fill(*buffer);
}

LineBufferFiller::SingleLineGG::SingleLineGG(Entity& line)
{
	transform = line.get<Transform>();
	color = line.get<Color>();
	border = line.get<Border>();
	props = line.get<LineProps>();
}

void LineBufferFiller::SingleLineGG::fill(LineBuffer& buffer)
{
	len = glm::length(props.vec);
	float angle = glm::atan(props.vec.y, props.vec.x);
	float half_thick = props.thickness / 2.0f;

	LineVertex& top_left = buffer.vertices[0];
	fillVertex(top_left);
	top_left.position += glm::vec3(glm::rotate(glm::vec2(0.0f, half_thick), angle), 0.0f);
	top_left.norm = glm::vec2(-1.0f, 1.0f);

	LineVertex& bot_left = buffer.vertices[1];
	fillVertex(bot_left);
	bot_left.position += glm::vec3(glm::rotate(glm::vec2(0.0f, -1.0f * half_thick), angle), 0.0f);
	bot_left.norm = glm::vec2(-1.0f, -1.0f);

	LineVertex& bot_right = buffer.vertices[2];
	fillVertex(bot_right);
	bot_right.position += glm::vec3(glm::rotate(glm::vec2(len, -1.0f * half_thick), angle), 0.0f);
	bot_right.norm = glm::vec2(1.0f, -1.0f);

	LineVertex& top_right = buffer.vertices[3];
	fillVertex(top_right);
	top_right.position += glm::vec3(glm::rotate(glm::vec2(len, half_thick), angle), 0.0f);
	top_right.norm = glm::vec2(1.0f, 1.0f);
}

void LineBufferFiller::SingleLineGG::fillVertex(LineVertex& vertex)
{
	vertex.position = transform.pos;
	vertex.color = color.col;
	vertex.size = glm::vec2(len, props.thickness);
	vertex.border_width = border.width;
	vertex.border_color = border.color;
	vertex.sharpness = props.sharpness;
}

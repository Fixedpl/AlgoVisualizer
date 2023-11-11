#pragma once
#include <string>
#include <glm/glm.hpp>
#include "text/FontEnum.h"
#include "Entity/Entity.h"

enum class TextAlignment
{
	DEFAULT,
	LEFT_CORNER,
	CENTER
};

struct Transform
{
	glm::vec3 pos;
};

struct Color
{
	glm::vec4 col;
};

struct Border
{
	float width;
	glm::vec4 color;
};

struct CircleProps
{
	float radius;
};

struct RectProps
{
	glm::vec2 size;
	float radius;
	float sharpness;
};

struct TextProps
{
	std::string text;
	float font_size;
	float aa_low;
	float aa_hight;
	TextAlignment alignment;
	FontEnum font;
};

struct ArrayCellProps
{
	Entity rect;
	Entity text;
};

struct ArrayProps
{
	std::vector<Entity> array_cells;
};

struct NodeProps
{
	Entity circle;
	Entity text;
};

struct LineProps
{
	glm::vec2 vec;
	float thickness;
	float radius;
	float sharpness;
};

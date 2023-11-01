#pragma once
#include <glm/glm.hpp>

struct RectangleProperties;

struct RectangleVertex
{
	glm::vec3 position;
	glm::vec2 bot_left_corner;
	glm::vec4 color;
	glm::vec2 size;
	float radius;
	float border_width;
	glm::vec4 border_color;
	float sharpness;
};

struct RectangleBuffer
{
	RectangleVertex vertices[4];
};

struct RectangleBufferArray
{
	RectangleBufferArray(int length) {
		buffer = new RectangleBuffer[length]();
		size = sizeof(RectangleBuffer) * length;
		count = length;
	}

	~RectangleBufferArray() {
		delete[] buffer;
	}

	RectangleBuffer* buffer;
	int size;
	int count;
};

struct RectangleProperties
{
	glm::vec3 position;
	glm::vec4 color;
	glm::vec2 size;
	float radius;
	float border_width;
	glm::vec4 border_color;
	float sharpness;
};


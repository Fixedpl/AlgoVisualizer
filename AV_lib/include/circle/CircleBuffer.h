#pragma once
#include <glm/glm.hpp>


struct CircleVertex
{
	glm::vec3 position;
	glm::vec2 center;
	float radius;
	glm::vec4 color;
	float border_width;
	glm::vec4 border_color;
};

struct CircleBuffer
{
	CircleVertex vertices[4];
};

struct CircleBufferArray
{
	CircleBufferArray(int length) {
		buffer = new CircleBuffer[length]();
		size = sizeof(CircleBuffer) * length;
		count = length;
	}

	~CircleBufferArray() {
		delete[] buffer;
	}

	CircleBuffer* buffer;
	int size;
	int count;
};


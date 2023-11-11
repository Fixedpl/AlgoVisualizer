#pragma once
#include <glm/glm.hpp>



struct LineVertex
{
	glm::vec3 position;
	glm::vec4 color;
	glm::vec2 norm;
	glm::vec2 size;
	float border_width;
	glm::vec4 border_color;
	float sharpness;
};

struct LineBuffer
{
	LineVertex vertices[4];
};

struct LineBufferArray
{
	LineBufferArray(int length) {
		buffer = new LineBuffer[length]();
		size = sizeof(LineBuffer) * length;
		count = length;
	}

	~LineBufferArray() {
		delete[] buffer;
	}

	LineBuffer* buffer;
	int size;
	int count;
};

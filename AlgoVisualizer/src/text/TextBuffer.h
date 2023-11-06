#pragma once
#include <glm/glm.hpp>
#include <string>



struct CharacterVertex
{
	glm::vec3 position;
	glm::vec4 color;
	glm::vec2 tex_coord;
	float aa_low;
	float aa_high;
};

struct CharacterBuffer
{
	CharacterVertex vertices[4];
};

struct CharacterBufferArray
{
	CharacterBufferArray(int summary_text_length) {
		character_arr = new CharacterBuffer[summary_text_length]();
		size = sizeof(CharacterBuffer) * summary_text_length;
		count = summary_text_length;
	}

	~CharacterBufferArray() {
		if (character_arr) {
			delete[] character_arr;
		}
	}

	CharacterBuffer* character_arr;
	int size;
	int count;
};

struct TextBufferArray
{
	TextBufferArray(int summary_text_length) {
		character_arr = new CharacterBufferArray(summary_text_length);
	}

	~TextBufferArray() {
		if (character_arr) {
			delete character_arr;
		}
	}

	CharacterBufferArray* character_arr;
};

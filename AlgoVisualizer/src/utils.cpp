#include "utils.h"


uint32_t* Utils::generateIndicesForRects(const uint32_t& rect_count)
{
	uint32_t indice_count = rect_count * 6;
	uint32_t* indices = new uint32_t[indice_count];

	for (int i = 0; i < indice_count / 6; i++) {
		indices[i * 6 + 0] = i * 4 + 0;
		indices[i * 6 + 1] = i * 4 + 1;
		indices[i * 6 + 2] = i * 4 + 2;

		indices[i * 6 + 3] = i * 4 + 0;
		indices[i * 6 + 4] = i * 4 + 2;
		indices[i * 6 + 5] = i * 4 + 3;
	}
	return indices;
}

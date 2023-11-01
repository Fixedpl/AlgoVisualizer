#pragma once
#include <vector>
#include <cstdint>

#include "GL_DrawTypeEnum.h"
#include "dll.h"


namespace OpenGL
{
    class IndexBuffer
	{
	public:

        L4_API IndexBuffer();
        L4_API IndexBuffer(uint32_t* indices, const uint32_t& count);
        L4_API ~IndexBuffer();

        L4_API IndexBuffer(const IndexBuffer& obj) = delete;
        L4_API IndexBuffer& operator=(const IndexBuffer& obj) = delete;

        L4_API IndexBuffer(IndexBuffer&& obj) = delete;
        L4_API IndexBuffer& operator=(IndexBuffer&& obj) = delete;

        L4_API void create(uint32_t* indices, const uint32_t& count);

        L4_API void bind() const;

        L4_API uint32_t getIndiceCount() const;

	private:

		uint32_t m_id;

		uint32_t m_indice_count;
	};
}




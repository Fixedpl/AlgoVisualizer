#pragma once
#include <cstdint>
#include <vector>
#include <cassert>

#include "GL_IndexBuffer.h"
#include "GL_DrawTypeEnum.h"
#include "GL_gl.h"
#include "dll.h"

namespace OpenGL
{
    struct VertexAttributeElement {
		uint32_t vertex_dim;
		uint32_t data_type;

        L4_API static uint32_t getTypeSize(const uint32_t& data_type);
	};



    class BufferLayout
	{
	public:

		template <typename T>
        L4_API void addAttribute(const uint32_t& vertex_dim);

        L4_API const std::vector<VertexAttributeElement>& getAttributeElements() const;

        L4_API uint32_t getStride() const;

	private:

		void _addAttribute(const uint32_t& vertex_dim, const uint32_t& data_type);

	private:

		std::vector<VertexAttributeElement> m_va_elements;

		uint32_t m_stride;

	};



    class VertexBuffer
	{
	public:

		L4_API VertexBuffer();
		L4_API VertexBuffer(const uint32_t& size, const DrawType& draw_type);
		L4_API VertexBuffer(void* data, const uint32_t& size, const DrawType& draw_type);
		L4_API ~VertexBuffer();

		L4_API VertexBuffer(const VertexBuffer& obj) = delete;
		L4_API VertexBuffer& operator=(const VertexBuffer& obj) = delete;

        L4_API VertexBuffer(VertexBuffer&& obj) = delete;
        L4_API VertexBuffer& operator=(VertexBuffer&& obj) = delete;

        L4_API void bind() const;

        L4_API void create(const uint32_t& size, const DrawType& draw_type) const;
        L4_API void create(void* data, const uint32_t& size, const DrawType& draw_type) const;

        L4_API void update(void* data, const uint32_t& size, const uint32_t& offset);

	private:

		uint32_t m_id;

	};



    class VertexArray
	{
	public:

		L4_API VertexArray();
		L4_API ~VertexArray();

		L4_API VertexArray(const VertexArray& obj) = delete;
		L4_API VertexArray& operator=(const VertexArray& obj) = delete;

		L4_API VertexArray(VertexArray&& obj) = delete;
		L4_API VertexArray& operator=(VertexArray&& obj) = delete;

        L4_API void bind() const;

        L4_API void addVertexBuffer(VertexBuffer* vertex_buffer);

        L4_API const IndexBuffer& getIndexBuffer() const;
        L4_API void setIndexBuffer(IndexBuffer* index_buffer);

        L4_API BufferLayout getBufferLayout() const;
        L4_API void setBufferLayout(const BufferLayout& buffer_layout);

	private:

		uint32_t m_id;

		std::vector<VertexBuffer*> m_vertex_buffers;

		IndexBuffer* m_index_buffer;

		BufferLayout m_buffer_layout;
	};

    template <>
    L4_API inline void BufferLayout::addAttribute<float>(const uint32_t& vertex_dim);

	template <>
    inline void BufferLayout::addAttribute<float>(const uint32_t& vertex_dim)
	{
		_addAttribute(vertex_dim, GL_FLOAT);
	}

    template <>
    L4_API inline void BufferLayout::addAttribute<uint32_t>(const uint32_t& vertex_dim);

	template <>
    inline void BufferLayout::addAttribute<uint32_t>(const uint32_t& vertex_dim)
	{
		_addAttribute(vertex_dim, GL_UNSIGNED_INT);
	}

}


#pragma once
#include <unordered_map>

#include "GL_VertexBuffer.h"
#include "GL_Shader.h"
#include "dll.h"


namespace OpenGL
{
    class Renderer
	{
	public:

        L4_API static void init();

        L4_API static void setClearColor(const glm::vec4& color);
        L4_API static void clear();

        L4_API static void drawArrays(const VertexArray& buffer, const DrawUsage& draw_usage, const uint32_t& vertice_count);
        L4_API static void drawIndexed(const VertexArray& buffer, const DrawUsage& draw_usage, uint32_t size = 0);

	};
}

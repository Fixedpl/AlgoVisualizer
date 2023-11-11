#pragma once
#include <memory>
#include <vector>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "LineBuffer.h"

#include "dll_algo.h"


class LineRenderer
{
public:

	AV_API LineRenderer();

	AV_API void onUpdate(const glm::mat4& mvp);

	AV_API void push(LineBufferArray* buffer);

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;
	std::unique_ptr<OpenGL::IndexBuffer> m_ib;

	std::vector<LineBufferArray*> m_buffers;
};

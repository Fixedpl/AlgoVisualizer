#pragma once
#include <memory>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "CircleBuffer.h"


class CircleRenderer
{
public:

	CircleRenderer();

	void onUpdate(const glm::mat4& mvp);

	void push(CircleBufferArray* buffer);

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;
	std::unique_ptr<OpenGL::IndexBuffer> m_ib;

	CircleBufferArray* m_buffer;
};

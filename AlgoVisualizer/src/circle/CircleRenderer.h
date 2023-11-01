#pragma once
#include <memory>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "Circle.h"


class CircleRenderer
{
public:

	CircleRenderer();

	void onUpdate(const glm::mat4& mvp);

	void push(const CircleProperties& props);

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;
	std::unique_ptr<OpenGL::IndexBuffer> m_ib;

	std::vector<CircleProperties> m_circles;
};

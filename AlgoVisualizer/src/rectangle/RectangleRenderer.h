#pragma once
#include <memory>
#include <vector>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "Rectangle.h"


class RectangleRenderer
{
public:

	RectangleRenderer();

	void onUpdate(const glm::mat4& mvp);

	void push(const RectangleProperties& rect);

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;
	std::unique_ptr<OpenGL::IndexBuffer> m_ib;

	std::vector<RectangleProperties> m_rects;

};


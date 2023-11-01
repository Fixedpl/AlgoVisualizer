#pragma once
#include <memory>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "Tests/Test.h"
#include "rectangle/Rectangle.h"


class RectangleTest : public Test
{
public:

	RectangleTest(Window* window);

protected:

	void onUpdate(const float& dt);

	void onImGuiUpdate();

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;
	std::unique_ptr<OpenGL::IndexBuffer> m_ib;

	glm::mat4 m_mvp;

	RectangleProperties props;
};


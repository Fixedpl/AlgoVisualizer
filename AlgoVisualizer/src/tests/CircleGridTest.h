#pragma once
#include <memory>
#include <vector>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "Tests/Test.h"
#include "circle/Circle.h"



class CircleGridTest : public Test
{
public:

	CircleGridTest(Window* window);

protected:

	void onUpdate(const float& dt);

	void onImGuiUpdate();

private:

	void generateGrid();

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;
	std::unique_ptr<OpenGL::IndexBuffer> m_ib;

	glm::mat4 m_mvp;

	CircleProperties m_circle_props;

	std::vector<CircleProperties> m_circles;

	int m_circle_count_vertical;
	int m_circle_count_horizontal;
};


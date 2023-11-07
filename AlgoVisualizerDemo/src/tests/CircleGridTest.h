#pragma once
#include <memory>
#include <vector>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "Test/Test.h"
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"
#include "BaseComponents.h"


class CircleGridTest : public Test
{
public:

	CircleGridTest(Window* window);

protected:

	void onUpdate(const float& dt);

	void onImGuiUpdate();

private:

	void generateGrid();

	Entity generateCircle();

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;
	std::unique_ptr<OpenGL::IndexBuffer> m_ib;

	glm::mat4 m_mvp;

	EntityRegistry registry;
	std::vector<Entity> m_circles;

	int m_circle_count_vertical;
	int m_circle_count_horizontal;

	Transform transform;
	Color color;
	CircleProps props;
	Border border;

};


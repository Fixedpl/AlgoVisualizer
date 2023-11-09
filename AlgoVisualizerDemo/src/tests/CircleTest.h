#pragma once
#include <memory>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "Test/Test.h"
#include "circle/CircleBuffer.h"
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"
#include "BaseComponents.h"


class CircleTest : public Test
{
public:

	CircleTest(Window* window);

protected:

	void onUpdate(const float& dt);

	void onImGuiUpdate();

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;
	std::unique_ptr<OpenGL::IndexBuffer> m_ib;

	glm::mat4 m_mvp;

	EntityRegistry registry;
	Entity circle;
	Transform* transform;
	Color* color;
	CircleProps* props;
	Border* border;
};


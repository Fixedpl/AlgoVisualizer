#pragma once
#include <memory>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "Test/Test.h"
#include "rectangle/RectangleBuffer.h"
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"
#include "BaseComponents.h"


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

	EntityRegistry registry;
	Entity rect;
	Transform* transform;
	Color* color;
	RectProps* props;
	Border* border;
};


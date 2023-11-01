#pragma once
#include <memory>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "Tests/Test.h"


class ShadertoyTest : public Test
{
public:

	ShadertoyTest(Window* window);

protected:

	void onUpdate(const float& dt);

	void onImGuiUpdate();

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;

	glm::mat4 m_mvp;

	float iTime = 0.0f;
	glm::vec2 iResolution;
};


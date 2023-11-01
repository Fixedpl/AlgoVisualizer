#pragma once
#include <memory>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "OpenGL/GL_Texture.h"
#include "OpenGL/GL_TextureSlots.h"
#include "Tests/Test.h"
#include "text/Text.h"
#include "text/Font.h"


class TextTest : public Test
{
public:

	TextTest(Window* window);

protected:

	void onUpdate(const float& dt);

	void onImGuiUpdate();

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;
	std::unique_ptr<OpenGL::IndexBuffer> m_ib;
	std::unique_ptr<OpenGL::Texture> m_texture;
	std::unique_ptr<OpenGL::TextureSlots> m_texture_slots;
	std::unique_ptr<Font> font;

	glm::mat4 m_mvp;
	TextProperties props;
	std::string text_str;
};

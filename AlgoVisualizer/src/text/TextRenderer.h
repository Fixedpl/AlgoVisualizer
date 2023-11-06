#pragma once
#include <memory>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "OpenGL/GL_Texture.h"
#include "OpenGL/GL_TextureSlots.h"
#include "TextBuffer.h"
#include "Font.h"


class TextRenderer
{
public:

	TextRenderer();

	void onUpdate(const glm::mat4& mvp);

	void push(TextBufferArray* buffer);

	Font* getFont();

private:

	std::unique_ptr<OpenGL::Shader> m_shader;
	std::unique_ptr<OpenGL::VertexArray> m_va;
	std::unique_ptr<OpenGL::VertexBuffer> m_vb;
	std::unique_ptr<OpenGL::IndexBuffer> m_ib;
	std::unique_ptr<OpenGL::Texture> m_texture;
	std::unique_ptr<OpenGL::TextureSlots> m_texture_slots;
	std::unique_ptr<Font> m_font;

	std::vector<TextBufferArray*> m_buffers;
};

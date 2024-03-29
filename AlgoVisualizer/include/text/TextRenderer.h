#pragma once
#include <memory>

#include "OpenGL/GL_Shader.h"
#include "OpenGL/GL_VertexBuffer.h"
#include "OpenGL/GL_Texture.h"
#include "OpenGL/GL_TextureSlots.h"
#include "TextBuffer.h"
#include "Font.h"

#include "dll_algo.h"


class TextRenderer
{
public:

	AV_API TextRenderer();

	AV_API void onUpdate(const glm::mat4& mvp);

	AV_API void push(TextBufferArray* buffer);

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

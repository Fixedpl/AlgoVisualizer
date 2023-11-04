#include "TextRenderer.h"
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "utils.h"


TextRenderer::TextRenderer()
{
	m_shader = std::make_unique<OpenGL::Shader>("res/shaders/vText.glsl", "res/shaders/fText.glsl");
	m_shader->bind();

	m_shader->setUniform1i("u_texture", 0);

	m_va = std::make_unique<OpenGL::VertexArray>();
	m_vb = std::make_unique<OpenGL::VertexBuffer>(sizeof(CharacterBufferArray) * 1, DrawType::DYNAMIC);

	m_font = std::make_unique<Font>("res/fonts/arial_atlas.png", "res/fonts/arial_atlas.json");

	OpenGL::TextureData texture_data = m_font->loadFontTexture();

	m_texture_slots = std::make_unique<OpenGL::TextureSlots>();
	m_texture = std::make_unique<OpenGL::Texture>(texture_data);

	m_texture_slots->setActiveTextureSlot(0);
	m_texture_slots->bindTexture(m_texture.get());

	OpenGL::BufferLayout layout;
	layout.addAttribute<float>(3);
	layout.addAttribute<float>(4);
	layout.addAttribute<float>(2);
	layout.addAttribute<float>(1);
	layout.addAttribute<float>(1);

	uint32_t indices[] = {
		0, 1, 2, 0, 2, 3
	};
	m_ib = std::make_unique<OpenGL::IndexBuffer>(indices, 6);

	m_va->addVertexBuffer(m_vb.get());
	m_va->setBufferLayout(layout);
	m_va->setIndexBuffer(m_ib.get());
}

void TextRenderer::onUpdate(const glm::mat4& mvp)
{
	m_shader->bind();
	m_shader->setUniformMat4f("u_MVP", mvp);
	
	m_va->bind();

	for (auto& buffer : m_buffers) {
		m_vb->create(buffer->character_arr->character_arr, buffer->character_arr->size, DrawType::DYNAMIC);

		uint32_t* indices = Utils::generateIndicesForRects(buffer->character_arr->count);
		m_ib->create(indices, buffer->character_arr->count * 6);

		delete[] indices;

		OpenGL::Renderer::drawIndexed(*m_va, DrawUsage::TRIANGLE);
	}
}

void TextRenderer::push(TextBufferArray* buffer)
{
	m_buffers.push_back(buffer);
}

Font* TextRenderer::getFont()
{
	return m_font.get();
}


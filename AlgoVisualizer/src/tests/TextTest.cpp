#include "TextTest.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "text/TextBufferFiller.h"
#include "utils.h"


TextTest::TextTest(Window* window)
{
	OpenGL::Renderer::setClearColor(glm::vec4(100.0f / 256.0f, 100.0f / 256.0f, 100.0f / 256.0f, 1.0f));

	m_shader = std::make_unique<OpenGL::Shader>("res/shaders/vText.glsl", "res/shaders/fText.glsl");
	m_shader->bind();

	m_shader->setUniform1i("u_texture", 0);

	m_va = std::make_unique<OpenGL::VertexArray>();
	m_vb = std::make_unique<OpenGL::VertexBuffer>(sizeof(CharacterBufferArray) * 1, DrawType::DYNAMIC);

	font = std::make_unique<Font>("res/fonts/CascadiaMono.png", "res/fonts/CascadiaMono.json");

	OpenGL::TextureData texture_data = font->loadFontTexture();
	
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

	text = registry.createEntity();
	text.add<Transform>(Transform());
	transform = &text.get<Transform>();
	transform->pos = glm::vec3(0.0f, 0.0f, 0.0f);

	text.add<Color>(Color());
	color = &text.get<Color>();
	color->col = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

	text.add<TextProps>(TextProps());
	props = &text.get<TextProps>();
	props->text = "Ninja ;._.;";
	props->font_size = 48.0f;
	props->aa_low = 0.5f;
	props->aa_hight = 0.6f;
	props->alignment = TextAlignment::DEFAULT;
	props->font = FontEnum::ARIAL;

	WindowSettings window_settings = window->getWindowSettings();

	glm::mat4 ortho_projection = glm::ortho(0.0f, (float)window_settings.width, 0.0f, (float)window_settings.height);

	m_mvp = ortho_projection;
}

void TextTest::onUpdate(const float& dt)
{
	m_shader->bind();
	m_shader->setUniformMat4f("u_MVP", m_mvp);

	TextBufferArray* buffer = TextBufferFiller::generate(text);
	m_vb->create(buffer->character_arr->size, DrawType::DYNAMIC);
	m_vb->update(buffer->character_arr->character_arr->vertices, buffer->character_arr->size, 0);
	
	uint32_t* indices = Utils::generateIndicesForRects(buffer->character_arr->count);
	m_ib->create(indices, buffer->character_arr->count * 6);
	delete[] indices;

	delete buffer;

	OpenGL::Renderer::drawIndexed(*m_va, DrawUsage::TRIANGLE);
}

void TextTest::onImGuiUpdate()
{
	ImGui::SliderFloat3("Position", &transform->pos.x, 0.0f, 1280.0f);
	ImGui::ColorEdit3("Color", &color->col.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat("Font size", &props->font_size, 10.0f, 120.0f);
	ImGui::SliderFloat("AA low", &props->aa_low, 0.0f, 1.0f);
	ImGui::SliderFloat("AA high", &props->aa_hight, 0.0f, 1.0f);
}

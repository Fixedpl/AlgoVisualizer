#include "CircleRenderer.h"
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "utils.h"


CircleRenderer::CircleRenderer()
{
	m_shader = std::make_unique<OpenGL::Shader>("res/shaders/vCircle.glsl", "res/shaders/fCircle.glsl");
	m_va = std::make_unique<OpenGL::VertexArray>();
	m_vb = std::make_unique<OpenGL::VertexBuffer>(sizeof(CircleBuffer) * 1, DrawType::STATIC);

	OpenGL::BufferLayout circle_layout;
	circle_layout.addAttribute<float>(3);
	circle_layout.addAttribute<float>(2);
	circle_layout.addAttribute<float>(1);
	circle_layout.addAttribute<float>(4);
	circle_layout.addAttribute<float>(1);
	circle_layout.addAttribute<float>(4);

	uint32_t indices[] = {
		0, 1, 2, 0, 2, 3
	};
	m_ib = std::make_unique<OpenGL::IndexBuffer>(indices, 6);

	m_va->addVertexBuffer(m_vb.get());
	m_va->setBufferLayout(circle_layout);
	m_va->setIndexBuffer(m_ib.get());
}

void CircleRenderer::onUpdate(const glm::mat4& mvp)
{
	m_shader->bind();
	m_shader->setUniformMat4f("u_MVP", mvp);
	
	m_va->bind();

	m_vb->create(m_buffer->buffer, m_buffer->size, DrawType::DYNAMIC);
	
	uint32_t* indices = Utils::generateIndicesForRects(m_buffer->count);
	m_ib->create(indices, m_buffer->count * 6);

	delete[] indices;

	OpenGL::Renderer::drawIndexed(*m_va, DrawUsage::TRIANGLE);
}

void CircleRenderer::push(CircleBufferArray* buffer)
{
	m_buffer = buffer;
}

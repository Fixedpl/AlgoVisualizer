#include "LineRenderer.h"
#include <imgui/imgui.h>
#include "OpenGL/GL_Renderer.h"
#include "utils.h"


LineRenderer::LineRenderer()
{
	m_shader = std::make_unique<OpenGL::Shader>("res/shaders/vLine.glsl", "res/shaders/fLine.glsl");
	m_va = std::make_unique<OpenGL::VertexArray>();
	m_vb = std::make_unique<OpenGL::VertexBuffer>(sizeof(LineBuffer) * 1, DrawType::STATIC);

	OpenGL::BufferLayout layout;
	layout.addAttribute<float>(3);
	layout.addAttribute<float>(4);
	layout.addAttribute<float>(2);
	layout.addAttribute<float>(2);
	layout.addAttribute<float>(1);
	layout.addAttribute<float>(4);
	layout.addAttribute<float>(1);

	uint32_t indices[] = {
		0, 1, 2, 0, 2, 3
	};
	m_ib = std::make_unique<OpenGL::IndexBuffer>(indices, 6);

	m_va->addVertexBuffer(m_vb.get());
	m_va->setBufferLayout(layout);
	m_va->setIndexBuffer(m_ib.get());
}

void LineRenderer::onUpdate(const glm::mat4& mvp)
{
	m_shader->bind();
	m_shader->setUniformMat4f("u_MVP", mvp);

	m_va->bind();

	for (auto& buffer : m_buffers) {
		m_vb->create(buffer->buffer, buffer->size, DrawType::DYNAMIC);

		uint32_t* indices = Utils::generateIndicesForRects(buffer->count);
		m_ib->create(indices, buffer->count * 6);

		delete[] indices;

		OpenGL::Renderer::drawIndexed(*m_va, DrawUsage::TRIANGLE);
	}
}

void LineRenderer::push(LineBufferArray* buffer)
{
	m_buffers.push_back(buffer);
}

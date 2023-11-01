#include "CircleRenderer.h"
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "CircleGeometryGenerator.h"
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

	CircleBufferArray* buffer_arr = CircleGeometryGenerator::generate(m_circles);
	m_vb->create(buffer_arr->buffer, buffer_arr->size, DrawType::DYNAMIC);
	
	uint32_t* indices = Utils::generateIndicesForRects(buffer_arr->count);
	m_ib->create(indices, buffer_arr->count * 6);

	delete buffer_arr;
	m_circles.clear();
	delete[] indices;

	OpenGL::Renderer::drawIndexed(*m_va, DrawUsage::TRIANGLE);
}

void CircleRenderer::push(const CircleProperties& props)
{
	m_circles.push_back(props);
}

#include "ArrayTest.h"

#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "array/ArrayCellFactory.h"
#include "array/ArrayCellGG.h"
#include "array/ArrayFactory.h"
#include "anims/AnimationChainBuilder.h"

#include "Colors.h"


ArrayTest::ArrayTest(Window* window)
	:
	Test(window)
{
	m_text_ren = std::make_unique<TextRenderer>();
	m_rect_ren = std::make_unique<RectangleRenderer>();

	std::vector<std::string> string_array = {
		"14",
		"56",
		"132"
	};

	m_array_position = glm::vec3(100.0f, 100.0f, 0.0f);
	float cell_size = 100.0f;

	m_tween = new Tween(TWEENS::LINEAR, 2.0f);

	//array_cell = ArrayCellFactory::arrayCell("14", cell_size, m_array_position, m_text_ren->getFont(), &m_registry);

	array = ArrayFactory::array(string_array, cell_size, m_array_position, &m_registry);
	array_buffer = ArrayGG::generate(array);
	WindowSettings window_settings = window->getWindowSettings();

	AnimationChain* anims = AnimationChainBuilder(array)
		.move(TWEENS::EASE_IN_OUT_BACK, 2, glm::vec3(400.0f, 0.0f, 0.0f))
		.move(TWEENS::EASE_IN_OUT_SIN, 2, glm::vec3(0.0f, 400.0f, 0.0f))
		.move(TWEENS::LINEAR, 2, glm::vec3(-400.0f, 0.0f, 0.0f))
		.move(TWEENS::EASE_IN_OUT_ELASTIC, 2, glm::vec3(0.0f, -400.0f, 0.0f))
		.color(TWEENS::EASE_IN_OUT_BACK, 3, COLOR::PINK, COLOR::BLACK)
		.build();

	m_anim_player.play(anims);
	delete anims;

	glm::mat4 ortho_projection = glm::ortho(0.0f, (float)window_settings.width, 0.0f, (float)window_settings.height);

	m_mvp = ortho_projection;
}

void ArrayTest::onUpdate(const float& frame_time)
{
	//m_array_position.x = 100.0f + m_tween->update(frame_time) * 500.0f;

	m_anim_player.onUpdate(frame_time);

	ArrayFactory::update(array);
	ArrayGG::update(array, array_buffer.rect_buffer, array_buffer.text_buffer);

	m_text_ren->push(array_buffer.text_buffer);
	m_rect_ren->push(array_buffer.rect_buffer);

	m_text_ren->onUpdate(m_mvp);
	m_rect_ren->onUpdate(m_mvp);
}

void ArrayTest::onImGuiUpdate()
{
	ImGui::SliderFloat3("Position", &m_array_position.x, 0.0f, 1280.0f);
	//ImGui::ColorEdit4("Color", &rect1.color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	//ImGui::SliderFloat2("Size", &rect1.size.x, 0.0f, 400.0f);
	//ImGui::SliderFloat("Border radius", &rect1.radius, 0.0f, 40.0f);
	//ImGui::SliderFloat("Border width", &rect1.border_width, 0.0f, 20.0f);
	//ImGui::ColorEdit3("Border color", &rect1.border_color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	//ImGui::SliderFloat("Border sharpness", &rect1.sharpness, 0.0f, 10.0f);

	//ImGui::SliderFloat3("Position2", &text1.props.position.x, 0.0f, 1280.0f);
	//ImGui::ColorEdit3("Color2", &text1.props.color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	//ImGui::SliderFloat("Font size2", &text1.props.font_size, 10.0f, 120.0f);
	//ImGui::SliderFloat("AA low2", &text1.props.aa_low, 0.0f, 1.0f);
	//ImGui::SliderFloat("AA high2", &text1.props.aa_hight, 0.0f, 1.0f);
}

#pragma once
#include <iostream>
#include <glm/glm.hpp>

#include "text/Text.h"
#include "rectangle/Rectangle.h"


class ArrayCell
{
public:

	ArrayCell(const std::string& text, const float& size, const glm::vec3& position)
		: m_size(size), m_position(position) {
		m_rect_props.color = glm::vec4(0.0f);
		m_rect_props.size = glm::vec2(size);
		m_rect_props.radius = 20.0f;
		m_rect_props.border_width = 6.0f;
		m_rect_props.border_color = glm::vec4(glm::vec3(0.0f), 1.0f);
		m_rect_props.sharpness = 1.5f;

		m_text.text = text;
		m_text.props.color = glm::vec4(glm::vec3(0.0f), 1.0f);
		m_text.props.font_size = 30.0f;
		m_text.props.aa_low = 0.0f;
		m_text.props.aa_hight = 0.5f;
		m_text.alignment = TextAlignment::CENTER;

		setPosition(position);
	}

	RectangleProperties getRect() const {
		return m_rect_props;
	}

	Text getText() const {
		return m_text;
	}

	void setPosition(const glm::vec3& position) {
		m_position = position;

		m_rect_props.position = position;
		m_text.props.position = position + glm::vec3(m_rect_props.size / 2.0f, 0.0f);
	}

private:

	float m_size;
	RectangleProperties m_rect_props;
	Text m_text;

	glm::vec3 m_position;
};


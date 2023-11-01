#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>

#include "rectangle/Rectangle.h"
#include "text/Text.h"
#include "ArrayCell.h"


class Array
{
public:

	Array(const std::vector<std::string>& values, const float& cell_size, const glm::vec3 position)
		: m_values(values), m_position(position), m_cell_size(cell_size) {
		for (auto& value : m_values) {
			m_cells.push_back({ value, cell_size, m_position });
			m_position.x += cell_size;
		}
	}

	const std::vector<ArrayCell>& getCells() const {
		return m_cells;
	}

	void setPosition(const glm::vec3& position) {
		m_position = position;
		for (auto& cell : m_cells) {
			cell.setPosition(m_position);
			m_position.x += m_cell_size;
		}
	}

private:

	std::vector<std::string> m_values;
	glm::vec3 m_position;
	float m_cell_size;

	std::vector<ArrayCell> m_cells;

};


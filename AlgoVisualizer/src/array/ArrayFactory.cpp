#include "ArrayFactory.h"

#include "ArrayCellFactory.h"
#include "BaseComponents.h"


Entity ArrayFactory::array(const std::vector<std::string>& texts, const float& cell_size,
	const glm::vec3& pos, Font* font, EntityRegistry* registry)
{
	Entity array = registry->createEntity();
	Transform transform;
	transform.pos = pos;
	array.add<Transform>(transform);

	Color color;
	color.col = glm::vec4(glm::vec3(0.0f), 1.0f);
	array.add<Color>(color);

	ArrayProps props;

	float char_offset = 0.0f;
	for (auto& text : texts) {
		Entity array_cell = ArrayCellFactory::arrayCell(text, cell_size, pos + glm::vec3(char_offset, 0.0f, 0.0f),
			font, registry);
		props.array_cells.push_back(array_cell);
		
		char_offset += cell_size;
	}
	array.add<ArrayProps>(props);
	return array;
}

void ArrayFactory::update(Entity& array)
{
	ArrayProps& props = array.get<ArrayProps>();
	Transform& transform = array.get<Transform>();
	Color& color = array.get<Color>();

	float cell_offset = 0.0f;
	for (auto& cell : props.array_cells) {
		ArrayCellProps& cell_props = cell.get<ArrayCellProps>();

		cell.get<Transform>().pos = transform.pos + glm::vec3(cell_offset, 0.0f, 0.0f);
		cell_offset += cell_props.rect.get<RectProps>().size.x;

		cell.get<Color>().col = color.col;

		ArrayCellFactory::update(cell);
	}
}

void ArrayFactory::updatePosition(Entity& array)
{
	ArrayProps& props = array.get<ArrayProps>();
	Transform& transform = array.get<Transform>();

	float cell_offset = 0.0f;
	for (auto& cell : props.array_cells) {
		ArrayCellProps& cell_props = cell.get<ArrayCellProps>();

		cell.get<Transform>().pos = transform.pos + glm::vec3(cell_offset, 0.0f, 0.0f);
		ArrayCellFactory::updatePosition(cell);
		cell_offset += cell_props.rect.get<RectProps>().size.x;
	}

}


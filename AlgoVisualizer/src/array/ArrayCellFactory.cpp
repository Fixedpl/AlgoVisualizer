#include "ArrayCellFactory.h"

#include "BaseComponents.h"


Entity ArrayCellFactory::arrayCell(const std::string& text_str, const float& size, 
    const glm::vec3& pos, EntityRegistry* registry)
{
    Entity array_cell = registry->createEntity();
    Transform transform;
    transform.pos = pos;
    array_cell.add<Transform>(transform);

    Color color;
    color.col = glm::vec4(glm::vec3(0.0f), 1.0f);
    array_cell.add<Color>(color);

    Entity rect = ArrayCellFactory::rect(registry, pos, size);
    Entity text = ArrayCellFactory::text(registry, text_str, 
        pos + glm::vec3(glm::vec2(size / 2.0f), 0.0f));

    ArrayCellProps props;
    props.rect = rect;
    props.text = text;
    array_cell.add<ArrayCellProps>(props);

    return array_cell;
}

void ArrayCellFactory::update(Entity& array_cell)
{
    Transform& transform = array_cell.get<Transform>();
    ArrayCellProps& props = array_cell.get<ArrayCellProps>();

    props.rect.get<Transform>().pos = transform.pos;
    props.text.get<Transform>().pos = transform.pos + glm::vec3(glm::vec2(props.rect.get<RectProps>().size.x / 2.0f), 0.0f);

    props.rect.get<Border>().color = array_cell.get<Color>().col;
}

void ArrayCellFactory::updatePosition(Entity& array_cell)
{
    Transform& transform = array_cell.get<Transform>();
    ArrayCellProps& props = array_cell.get<ArrayCellProps>();

    props.rect.get<Transform>().pos = transform.pos;
    props.text.get<Transform>().pos = transform.pos + glm::vec3(glm::vec2(props.rect.get<RectProps>().size.x / 2.0f), 0.0f);
}

Entity ArrayCellFactory::rect(EntityRegistry* registry, const glm::vec3& pos, const float& size)
{
    Entity rect = registry->createEntity();
    Transform transform;
    transform.pos = pos;
    rect.add<Transform>(transform);

    Color color;
    color.col = glm::vec4(0.0f);
    rect.add<Color>(color);

    Border border;
    border.color = glm::vec4(glm::vec3(0.0f), 1.0f);
    border.width = 6.0f;
    rect.add<Border>(border);

    RectProps props;
    props.radius = 20.0f;
    props.sharpness = 1.5f;
    props.size = glm::vec2(size);
    rect.add<RectProps>(props);

    return rect;
}

Entity ArrayCellFactory::text(EntityRegistry* registry, const std::string& text_str, const glm::vec3& pos)
{
    Entity text = registry->createEntity();
    Transform transform;
    transform.pos = pos;
    text.add<Transform>(transform);

    Color color = Color();
    color.col = glm::vec4(glm::vec3(0.0f), 1.0f);
    text.add<Color>(color);

    TextProps props;
    props.text = text_str;
    props.font_size = 30.0f;
    props.aa_low = 0.0f;
    props.aa_hight = 0.5f;
    props.alignment = TextAlignment::CENTER;
    props.font = FontEnum::ARIAL;
    text.add<TextProps>(props);
  
    return text;
}

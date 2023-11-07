#include "NodeFactory.h"

#include "BaseComponents.h"

Entity NodeFactory::node(const std::string& text_str, const float& radius, const glm::vec4& color_vec, 
    const glm::vec3& pos, EntityRegistry* registry)
{
    Entity node = registry->createEntity();
    Transform transform;
    transform.pos = pos;
    node.add<Transform>(transform);

    Entity circle = NodeFactory::circle(registry, pos, radius, color_vec);
    Entity text = NodeFactory::text(registry, text_str,
        pos + glm::vec3(glm::vec2(radius), 0.0f));

    NodeProps props;
    props.circle = circle;
    props.text = text;
    node.add<NodeProps>(props);

    return node;
}

void NodeFactory::update(Entity& node)
{
    Transform& transform = node.get<Transform>();
    NodeProps& props = node.get<NodeProps>();

    props.circle.get<Transform>().pos = transform.pos;
    props.text.get<Transform>().pos = transform.pos + glm::vec3(glm::vec2(props.circle.get<CircleProps>().radius), 0.0f);
}

void NodeFactory::updatePosition(Entity& node)
{
    Transform& transform = node.get<Transform>();
    NodeProps& props = node.get<NodeProps>();

    props.circle.get<Transform>().pos = transform.pos;
    props.text.get<Transform>().pos = transform.pos + glm::vec3(glm::vec2(props.circle.get<CircleProps>().radius), 0.0f);
}

Entity NodeFactory::circle(EntityRegistry* registry, const glm::vec3& pos, const float& radius, const glm::vec4& color_vec)
{
    Entity circle = registry->createEntity();
    Transform transform;
    transform.pos = pos;
    circle.add<Transform>(transform);

    Color color;
    color.col = color_vec;
    circle.add<Color>(color);

    Border border;
    border.color = glm::vec4(glm::vec3(0.0f), 1.0f);
    border.width = 6.0f;
    circle.add<Border>(border);

    CircleProps props;
    props.radius = radius;
    circle.add<CircleProps>(props);

    return circle;
}

Entity NodeFactory::text(EntityRegistry* registry, const std::string& text_str, const glm::vec3& pos)
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

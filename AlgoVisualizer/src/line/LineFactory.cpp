#include "LineFactory.h"

#include "BaseComponents.h"


Entity LineFactory::line(const glm::vec3& pos, const glm::vec3& line_vec, const glm::vec4& color_vec,
    const float& thickness, EntityRegistry* registry)
{
    Entity line = registry->createEntity();
    Transform transform;
    transform.pos = pos;
    line.add<Transform>(transform);

    Color color;
    color.col = color_vec;
    line.add<Color>(color);

    LineProps props;
    props.vec = line_vec;
    props.thickness = thickness;
    props.radius = 0.0f;
    props.sharpness = 0.0f;
    line.add<LineProps>(props);

    return line;
}


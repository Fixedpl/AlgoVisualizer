#include "LineGG.h"

#include "rectangle/RectangleBufferFiller.h"



RectangleBufferArray* LineGG::generate(Entity& line)
{
    RectangleBufferArray* buffer = new RectangleBufferArray(1);

    SimpleLineGG(line).fill(buffer->buffer);
    return buffer;
}

LineGG::SimpleLineGG::SimpleLineGG(Entity& line)
    :
    props(line.get<LineProps>())
{
}

void LineGG::SimpleLineGG::fill(RectangleBuffer* rect_buffer)
{
    RectangleBufferFiller::update(rect_buffer);
}

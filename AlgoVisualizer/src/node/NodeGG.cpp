#include "NodeGG.h"

#include "circle/CircleBufferFiller.h"
#include "text/TextBufferFiller.h"


NodeBuffer NodeGG::generate(Entity& node)
{
    int text_length = node.get<NodeProps>().text.get<TextProps>().text.size();

    NodeBuffer buffer = NodeBuffer();
    buffer.circle_buffer = new CircleBufferArray(1);
    buffer.text_buffer = new TextBufferArray(text_length);

    SimpleNodeGG(node).fill(buffer.circle_buffer, buffer.text_buffer);
    return buffer;
}

void NodeGG::update(Entity& array, CircleBufferArray* circle_buffer_array, TextBufferArray* text_buffer_array)
{
    SimpleNodeGG(array).fill(circle_buffer_array, text_buffer_array);
}

NodeGG::SimpleNodeGG::SimpleNodeGG(Entity& node)
    :
    props(node.get<NodeProps>())
{
}

void NodeGG::SimpleNodeGG::fill(CircleBufferArray* circle_buffer_array, TextBufferArray* text_buffer_array)
{
    CircleBufferFiller::update(props.circle, circle_buffer_array->buffer);
    TextBufferFiller::update(props.text, text_buffer_array->character_arr->character_arr);
}

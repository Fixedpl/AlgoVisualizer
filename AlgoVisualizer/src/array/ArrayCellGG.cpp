#include "ArrayCellGG.h"

#include "rectangle/RectangleBufferFiller.h"
#include "text/TextBufferFiller.h"


ArrayCellBuffer ArrayCellGG::generate(Entity& array_cell)
{
    int text_length = array_cell.get<ArrayCellProps>().text.get<TextProps>().text.size();

    ArrayCellBuffer buffer = ArrayCellBuffer();
    buffer.rect_buffer = new RectangleBufferArray(1);
    buffer.text_buffer = new TextBufferArray(text_length);

    SimpleArrayCellGG(array_cell).fill(buffer.rect_buffer->buffer, 
        buffer.text_buffer->character_arr->character_arr);
    return buffer;
}

void ArrayCellGG::update(Entity& array_cell, RectangleBuffer* rect_buffer, CharacterBuffer* text_buffer)
{
    SimpleArrayCellGG(array_cell).fill(rect_buffer, text_buffer);
}

ArrayCellGG::SimpleArrayCellGG::SimpleArrayCellGG(Entity& array_cell)
    : 
    cell_props(array_cell.get<ArrayCellProps>())
{
}

void ArrayCellGG::SimpleArrayCellGG::fill(RectangleBuffer* rect_buffer, CharacterBuffer* text_buffer)
{
    RectangleBufferFiller::update(cell_props.rect, rect_buffer);
    TextBufferFiller::update(cell_props.text, text_buffer);
}

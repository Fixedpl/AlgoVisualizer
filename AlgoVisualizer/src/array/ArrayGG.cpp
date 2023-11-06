#include "ArrayGG.h"

#include "ArrayCellGG.h"


ArrayBuffer ArrayGG::generate(Entity& array)
{
    std::vector<Entity>& array_cells = array.get<ArrayProps>().array_cells;

    int summary_text_length = 0;
    for (auto& array_cell : array_cells) {
        std::string& cell_text = array_cell.get<ArrayCellProps>().text.get<TextProps>().text;
        summary_text_length += cell_text.size();
    }

    ArrayBuffer array_buffer;
    array_buffer.rect_buffer = new RectangleBufferArray(array_cells.size());
    array_buffer.text_buffer = new TextBufferArray(summary_text_length);

    SimpleArrayGG(array).fill(array_buffer.rect_buffer, array_buffer.text_buffer);
    return array_buffer;
}

void ArrayGG::update(Entity& array, RectangleBufferArray* rect_buffer_array, TextBufferArray* text_buffer_array)
{
    SimpleArrayGG(array).fill(rect_buffer_array, text_buffer_array);
}

ArrayGG::SimpleArrayGG::SimpleArrayGG(Entity& array)
    :
    props(array.get<ArrayProps>())
{
}

void ArrayGG::SimpleArrayGG::fill(RectangleBufferArray* rect_buffer_array, TextBufferArray* text_buffer_array)
{
    RectangleBuffer* rect_buffer = rect_buffer_array->buffer;
    CharacterBuffer* char_buffer = text_buffer_array->character_arr->character_arr;

    int char_buffer_idx = 0;
    for (int i = 0; i < props.array_cells.size(); i++) {
        Entity& cell = props.array_cells[i];
        std::string& text = cell.get<ArrayCellProps>().text.get<TextProps>().text;

        ArrayCellProps& array_cell_props = cell.get<ArrayCellProps>();

        ArrayCellGG::generate(cell, &rect_buffer[i], &char_buffer[char_buffer_idx]);

        char_buffer_idx += text.size();
    }
}

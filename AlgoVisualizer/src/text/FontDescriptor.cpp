#include "FontDescriptor.h"

void FontDescriptor::addFontDescriptor(FontEnum font_name, Font* font_descriptor)
{
	m_fonts[font_name] = font_descriptor;
}

Font* FontDescriptor::getFontDescriptor(const FontEnum& font_name)
{
	return m_fonts[font_name];
}

FontDescriptor* FontDescriptor::inst()
{
	static FontDescriptor* inst = nullptr;
	if (inst == nullptr) {
		inst = new FontDescriptor();
	}
	return inst;
}

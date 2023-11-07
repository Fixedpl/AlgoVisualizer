#pragma once
#include <unordered_map>
#include "FontEnum.h"
#include "Font.h"



class FontDescriptor
{
public:

	void addFontDescriptor(FontEnum font_name, Font* font_descriptor);

	Font* getFontDescriptor(const FontEnum& font_name);

	static FontDescriptor* inst();

protected:

	FontDescriptor() {}

private:

	std::unordered_map<FontEnum, Font*> m_fonts;

};


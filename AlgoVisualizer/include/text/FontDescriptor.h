#pragma once
#include <unordered_map>
#include "FontEnum.h"
#include "Font.h"

#include "dll_algo.h"


class FontDescriptor
{
public:

	AV_API void addFontDescriptor(FontEnum font_name, Font* font_descriptor);

	AV_API Font* getFontDescriptor(const FontEnum& font_name);

	AV_API static FontDescriptor* inst();

protected:

	FontDescriptor() {}

private:

	std::unordered_map<FontEnum, Font*> m_fonts;

};


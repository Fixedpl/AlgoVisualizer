#pragma once
#include <cstdint>

#include "GL_Texture.h"
#include "dll.h"

namespace OpenGL
{
    class TextureSlots
	{
	public:

        L4_API static void init();

        L4_API static void bindTexture(Texture* texture);

        L4_API static void setActiveTextureSlot(const uint32_t& slot);

        L4_API static int32_t getMaxConcurrentTextures();

        L4_API static int32_t getMaxCombinedTextures();

	private:

		static int32_t m_max_concurrent_textures;

		static int32_t m_max_combined_textures;

	};
}




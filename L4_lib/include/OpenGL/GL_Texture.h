#pragma once
#include <cstdint>
#include <string>

#include "dll.h"

namespace OpenGL
{
    struct TextureData
    {
        unsigned char* data;
        int width;
        int height;
    };

    class Texture
	{
	public:

        L4_API Texture();
        L4_API Texture(const std::string& path);
        L4_API Texture(const TextureData& texture_data);
        L4_API ~Texture();

        L4_API Texture(const Texture& obj) = delete;
        L4_API Texture& operator=(const Texture& obj) = delete;

        L4_API Texture(Texture&& obj) = delete;
        L4_API Texture& operator=(Texture&& obj) = delete;

        L4_API void loadTexture(const std::string& path);
        L4_API void loadTexture(const TextureData& texture_data);

        L4_API inline int32_t getWidth() const { return m_width; };
        L4_API inline int32_t getHeight() const { return m_height; };

	private:

		uint32_t m_id;

		int32_t m_width, m_height, m_BPP;

		friend class TextureSlots;
	};
}


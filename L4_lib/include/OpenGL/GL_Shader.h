#pragma once
#include <string>
#include <cstdint>

#include <glm/glm.hpp>
#include "dll.h"

namespace OpenGL
{
    class Shader
	{
	public:

        L4_API Shader();
        L4_API Shader(const std::string& vsPath, const std::string& fsPath);
        L4_API ~Shader();

        L4_API Shader(const Shader& obj) = delete;
        L4_API Shader& operator=(const Shader& obj) = delete;

        L4_API Shader(Shader&& obj) = delete;
        L4_API Shader& operator=(Shader&& obj) = delete;

		L4_API void setUniformMat4f(const std::string& name, const glm::mat4& matrix);
		L4_API void setUniform1i(const std::string& name, const int32_t& value);
		L4_API void setUniform1f(const std::string& name, const float& value);
        L4_API void setUniform2f(const std::string& name, const glm::vec2& value);
        L4_API void setUniform3f(const std::string& name, const glm::vec3& value);

        L4_API void bind() const;

        L4_API void loadShader(const std::string& vsPath, const std::string& fsPath);

	private:

		uint32_t createShader(const std::string& path, const int32_t& type);

		int32_t getUniformLocation(const std::string& name);

	private:

		uint32_t m_id;

	};
}



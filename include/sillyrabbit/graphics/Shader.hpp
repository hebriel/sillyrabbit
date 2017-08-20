#ifndef SILLYRABBIT_GRAPHICS_SHADER_HPP
#define SILLYRABBIT_GRAPHICS_SHADER_HPP

#include "../utils/Math.hpp"

#include "../utils/FileUtils.hpp"
#include "../utils/Log.hpp"

#include <vector>
#include <iostream>

#define GL_GLEXT_PROTOTYPES
#include <SFML/OpenGL.hpp>
#include <GL/glext.h>

namespace sr { namespace graphics {

class Shader
{
    public:
        Shader(const char* vertPath, const char* fragPath);
        ~Shader();

        void enable() const;
        void disable() const;

        void setUniformMat2(const GLchar* name, const glm::mat2& matrix);
        void setUniformMat3(const GLchar* name, const glm::mat3& matrix);
        void setUniformMat4(const GLchar* name, const glm::mat4& matrix);

        void setUniformVec2(const GLchar* name, const glm::vec2& vector);
        void setUniformVec3(const GLchar* name, const glm::vec3& vector);
        void setUniformVec4(const GLchar* name, const glm::vec4& vector);

        void setUniform1f(const GLchar* name, const float& value);
        void setUniform1i(const GLchar* name, const int& value);
        void setUniform1ui(const GLchar* name, const unsigned int& value);


    private:
        GLuint m_shaderID;
        const char* m_vertPath;
        const char* m_fragPath;

        GLint getUniformLocation(const GLchar* name);
        GLuint load();
};

} }

#endif

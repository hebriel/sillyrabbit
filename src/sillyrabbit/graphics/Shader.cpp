#include <sillyrabbit/graphics/Shader.hpp>

namespace sr { namespace graphics {

Shader::Shader(const char* vertPath, const char* fragPath)
    : m_vertPath(vertPath), m_fragPath(fragPath)
{
    m_shaderID = load();
}

GLuint Shader::load()
{
    GLuint program = glCreateProgram();
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertSourceString = utils::readFile(m_vertPath);
    std::string fragSourceString = utils::readFile(m_fragPath);

    const char* vertSource = vertSourceString.c_str();
    const char* fragSource = fragSourceString.c_str();


    glShaderSource(vertex, 1, &vertSource, NULL);
    glCompileShader(vertex);

    GLint result;
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE)
    {
        GLint length;
        glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> error(length);
        glGetShaderInfoLog(vertex, length, &length, &error[0]);
        std::cout << RED << "[OpenGL Error] Failed to compile vertex shader " << MAGENTA << &error[0] << RESET << std::endl;
        glDeleteShader(vertex);
        return 0;
    }

    glShaderSource(fragment, 1, &fragSource, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE)
    {
        GLint length;
        glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> error(length);
        glGetShaderInfoLog(fragment, length, &length, &error[0]);
        std::cout << RED << "[OpenGL Error] Failed to compile fragment shader " << MAGENTA << &error[0] << RESET << std::endl;
        glDeleteShader(fragment);
        return 0;
    }

    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return program;

}

Shader::~Shader()
{
    glDeleteProgram(m_shaderID);
}

void Shader::enable() const
{
    glUseProgram(m_shaderID);
}

void Shader::disable() const
{
    glUseProgram(0);
}

void Shader::setUniformMat2(const GLchar* name, const glm::mat2& matrix)
{
    glUniformMatrix2fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::setUniformMat3(const GLchar* name, const glm::mat3& matrix)
{
    glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::setUniformMat4(const GLchar* name, const glm::mat4& matrix)
{
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::setUniformVec2(const GLchar* name, const glm::vec2& vector)
{
    glUniform2f(getUniformLocation(name), vector.x, vector.y);
}

void Shader::setUniformVec3(const GLchar* name, const glm::vec3& vector)
{
    glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
}

void Shader::setUniformVec4(const GLchar* name, const glm::vec4& vector)
{
    glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
}

void Shader::setUniform1f(const GLchar* name, const float& value)
{
    glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform1i(const GLchar* name, const int& value)
{
    glUniform1i(getUniformLocation(name), value);
}

void Shader::setUniform1ui(const GLchar* name, const unsigned int& value)
{
    glUniform1ui(getUniformLocation(name), value);

}

GLint Shader::getUniformLocation(const GLchar* name)
{
    return glGetUniformLocation(m_shaderID, name);
}

} }

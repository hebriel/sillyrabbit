#ifndef SILLYRABBIT_VERTEXBUFFEROBJECT_HPP
#define SILLYRABBIT_VERTEXBUFFEROBJECT_HPP

#define GL_GLEXT_PROTOTYPES
#include <SFML/OpenGL.hpp>
#include <GL/glext.h>

namespace sr { namespace graphics {

class Buffer
{
    public:
        Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
        Buffer();
        ~Buffer();

        void bind() const;
        void unbind() const;

        void create(GLfloat* data, GLsizei count, GLuint componentCount);

        inline GLuint getComponentCount() const {return m_componentCount;}

    private:
        GLuint m_bufferID;
        GLuint m_componentCount;
};

} }

#endif

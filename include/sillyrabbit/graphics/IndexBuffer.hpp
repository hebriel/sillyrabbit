#ifndef SILLYRABBIT_INDEXBUFFER_HPP
#define SILLYRABBIT_INDEXBUFFER_HPP

#define GL_GLEXT_PROTOTYPES
#include <SFML/OpenGL.hpp>
#include <GL/glext.h>

namespace sr { namespace graphics {

class IndexBuffer
{
    public:
        IndexBuffer(GLushort* data, GLsizei count);
        IndexBuffer();
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

        void create(GLushort* data, GLsizei count);

        inline GLuint getCount() const {return m_count;}

    private:
        GLuint m_bufferID;
        GLuint m_count;
};

} }

#endif

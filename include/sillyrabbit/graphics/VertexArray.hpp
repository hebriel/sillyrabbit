#ifndef SILLYRABBIT_VERTEXARRAY_HPP
#define SILLYRABBIT_VERTEXARRAY_HPP

#define GL_GLEXT_PROTOTYPES
#include <SFML/OpenGL.hpp>
#include <GL/glext.h>

#include <vector>
#include "Buffer.hpp"

namespace sr { namespace graphics {

class VertexArray
{
    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(Buffer* buffer, GLuint index);
        void bind() const;
        void unbind() const;

    protected:

    private:
        GLuint m_arrayID;
        std::vector<Buffer*> m_buffers;
};

} }

#endif

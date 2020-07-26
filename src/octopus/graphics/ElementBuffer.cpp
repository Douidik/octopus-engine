#include "OctopusPCH.h"
#include "ElementBuffer.h"
#include "util/Util.h"

namespace Octo {

    ElementBuffer::ElementBuffer(const void *data, GLsizei size, GLenum type, GLenum usage)
        : m_size(size), m_type(type), m_count( size / SizeOfGLType(type) )
    {
        glGenBuffers(1, &m_uRendererID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uRendererID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
    }

    ElementBuffer::~ElementBuffer() {
        glDeleteBuffers(1, &m_uRendererID);
    }

}
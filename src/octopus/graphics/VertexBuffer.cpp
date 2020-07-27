#include "OctopusPCH.h"
#include "VertexBuffer.h"
#include "util/Util.h"

namespace Octo {

    Ref<VertexBuffer> VertexBuffer::Create(const void *data, GLsizei size, GLenum type, Layout layout, GLenum usage) {
        return CreateRef<VertexBuffer>(data, size, type, layout, usage);
    }

    VertexBuffer::VertexBuffer(const void *data, GLsizei size, GLenum type, Layout layout, GLenum usage)
        : m_size(size), m_type(type), m_layout(layout)
    {
        glGenBuffers(1, &m_uRendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_uRendererID);
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }

    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &m_uRendererID);
    }

}
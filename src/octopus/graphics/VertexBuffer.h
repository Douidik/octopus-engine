#ifndef OCTOPUS_VERTEXBUFFER_H
#define OCTOPUS_VERTEXBUFFER_H

#include "Layout.h"

namespace Octo {

    class OCTO_API VertexBuffer {
    public:
        VertexBuffer(const void *data, GLsizei size, GLenum type, Layout layout, GLenum usage = GL_STATIC_DRAW);
        ~VertexBuffer();

        inline void bind() const {
            m_layout.enable();
            glBindBuffer(GL_ARRAY_BUFFER, m_uRendererID);
        }

        inline void unbind() const {
            m_layout.disable();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        inline GLsizei size()   const { return m_size; }
        inline Layout& layout()       { return m_layout; }
        inline GLenum  type()   const { return m_type; }

    private:
        GLsizei m_size;
        GLenum m_type;
        GLuint m_uRendererID;
        Layout m_layout;
    };

}

#endif //OCTOPUS_VERTEXBUFFER_H

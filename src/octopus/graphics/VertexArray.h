#ifndef OCTOPUS_VERTEXARRAY_H
#define OCTOPUS_VERTEXARRAY_H

#include "Layout.h"

namespace Octo {

    class VertexArray {
    public:
        explicit VertexArray();
        ~VertexArray();

        void addVertexBuffer(class VertexBuffer &vertexBuffer, class ShaderProgram &program);

        inline void bind() const {
            glBindVertexArray(m_uRendererID);
        }

        inline void unbind() const {
            glBindVertexArray(0);
        }

    private:
        GLuint m_uRendererID;

    };

}

#endif //OCTOPUS_VERTEXARRAY_H

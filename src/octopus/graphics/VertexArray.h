#ifndef OCTOPUS_VERTEXARRAY_H
#define OCTOPUS_VERTEXARRAY_H

#include "Layout.h"

namespace Octo {

    class ElementBuffer;
    class VertexBuffer;
    class ShaderProgram;

    class OCTO_API VertexArray {
    public:
        static Ref<VertexArray> Create();
;
        void addVertexBuffer(Ref<VertexBuffer> &vertexBuffer, Ref<ShaderProgram> &program);
        void addElementBuffer(Ref<ElementBuffer> &elementBuffer);

        VertexArray();
        ~VertexArray();

        inline void bind() const {
            glBindVertexArray(m_uRendererID);
        }

        inline void unbind() const {
            glBindVertexArray(0);
        }

        Ref<ElementBuffer> elementBuffer() const;
        std::vector<Ref<VertexBuffer>> vertexBuffers() const;

    private:
        GLuint m_uRendererID;
        Ref<ElementBuffer> m_elementBuffer;
        std::vector<Ref<VertexBuffer>> m_vertexBuffers;

    };

}

#endif //OCTOPUS_VERTEXARRAY_H

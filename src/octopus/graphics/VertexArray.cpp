#include "OctopusPCH.h"
#include "VertexArray.h"

#include "ElementBuffer.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "util/Util.h"

namespace Octo {

    Ref <VertexArray> VertexArray::Create() {
        return CreateRef<VertexArray>();
    }

    VertexArray::VertexArray() {
        glCreateVertexArrays(1, &m_uRendererID);
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_uRendererID);
    }

    void VertexArray::addVertexBuffer(Ref<VertexBuffer> &vertexBuffer, Ref<ShaderProgram> &program) {
        this->bind();
        vertexBuffer->bind();
        program->bind();

        Layout& layout = vertexBuffer->layout();
        GLenum type = vertexBuffer->type();

        /*
         * Querying to the program the index of each attributes and
         * computing the offset between each attributes,
         * the sum of all attributes size gives the stride of a vertex.
         */
        GLsizeiptr offset = 0;

        for (Attribute &attribute : layout.attributes) {
            attribute.iIndex = program->attributeLocation(attribute.name);
            // Size in bytes of the attribute
            GLsizei size = SizeOfGLType(type) * attribute.iComponents;
            attribute.offset = offset;
            offset += size;
        }
        layout.stride = offset;

        /* Enabling each index and send the attributes */

        layout.enable();

        for (Attribute &attribute : layout.attributes) {
            if (type == GL_BYTE ||
                type == GL_UNSIGNED_BYTE ||
                type == GL_SHORT ||
                type == GL_UNSIGNED_SHORT ||
                type == GL_INT ||
                type == GL_UNSIGNED_INT) {
                GLCall(glVertexAttribIPointer(attribute.iIndex,
                                              attribute.iComponents,
                                              type,
                                              layout.stride,
                                              (const void *) attribute.offset));
            } else if (type == GL_DOUBLE) {
                GLCall(glVertexAttribLPointer(attribute.iIndex,
                                              attribute.iComponents,
                                              type,
                                              layout.stride,
                                              (const void *) attribute.offset));
            } else {
                GLCall(glVertexAttribPointer(attribute.iIndex,
                                             attribute.iComponents,
                                             type,
                                             attribute.bNormalized,
                                             layout.stride,
                                             (const void *) attribute.offset));
            }
        }

        m_vertexBuffers.push_back(vertexBuffer);
    }

    void VertexArray::addElementBuffer(Ref<ElementBuffer> &elementBuffer) {
        this->bind();
        elementBuffer->bind();
        m_elementBuffer = elementBuffer;
    }

    Ref<ElementBuffer> VertexArray::elementBuffer() const {
        if(!m_elementBuffer) {
            throw std::runtime_error("Vertex Array has no element buffer");
        }

        return m_elementBuffer;
    }

    std::vector<Ref<VertexBuffer>> VertexArray::vertexBuffers() const {
        if(m_vertexBuffers.empty()) {
            throw std::runtime_error("Vertex Array has no vertex buffers");
        }

        return m_vertexBuffers;
    }

}
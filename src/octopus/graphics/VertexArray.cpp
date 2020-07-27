#include "OctopusPCH.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "util/Util.h"

namespace Octo {

    VertexArray::VertexArray() {
        glCreateVertexArrays(1, &m_uRendererID);
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_uRendererID);
    }

    void VertexArray::addVertexBuffer(class VertexBuffer &vertexBuffer, class ShaderProgram &program) {
        this->bind();
        vertexBuffer.bind();
        program.bind();

        Layout& layout = vertexBuffer.layout();
        GLenum type = vertexBuffer.type();

        /*
         * Querying to the program the index of each attributes and
         * computing the offset between each attributes,
         * the sum of all attributes size gives the stride of a vertex.
         */
        GLsizeiptr offset = 0;

        for (Attribute &attribute : layout.attributes) {
            attribute.iIndex = program.attributeLocation(attribute.name);
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
                glVertexAttribIPointer(attribute.iIndex,
                                       attribute.iComponents,
                                       type,
                                       layout.stride,
                                       (const void *) attribute.offset);
            } else if (type == GL_DOUBLE) {
                glVertexAttribLPointer(attribute.iIndex,
                                       attribute.iComponents,
                                       type,
                                       layout.stride,
                                       (const void *) attribute.offset);
            } else {
                glVertexAttribPointer(attribute.iIndex,
                                      attribute.iComponents,
                                      type,
                                      attribute.bNormalized,
                                      layout.stride,
                                      (const void *) attribute.offset);
            }
        }
    }

}
#ifndef OCTOPUS_ELEMENTBUFFER_H
#define OCTOPUS_ELEMENTBUFFER_H

namespace Octo {

class ElementBuffer {
public:
    ElementBuffer(const void *data, GLsizei size, GLenum type, GLenum usage = GL_STATIC_DRAW);
    ~ElementBuffer();

    inline void bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uRendererID);
    }

    inline void unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    inline GLsizei size() const { return m_size; }
    inline GLsizei count() const { return m_count; }
    inline GLenum type() const { return m_type; }

private:
    GLsizei m_size, m_count;
    GLenum m_type;
    GLuint m_uRendererID;
};

}

#endif //OCTOPUS_ELEMENTBUFFER_H

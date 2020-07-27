#include "OctopusPCH.h"
#include "Renderer.h"
#include "core/Dependencies.h"

#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "graphics/Texture.h"

namespace Octo {

    Renderer::Renderer(Bitfield rendererParameters) {
        if(!Dependencies::IsGLEWActive()) {
            Dependencies::InitGLEW();
        }

        m_clearBitfield = GL_COLOR_BUFFER_BIT;

        if(rendererParameters & (Bitfield)RendererParameters::CullFace) {
            GLCall(glEnable(GL_CULL_FACE));
            GLCall(glFrontFace(GL_CCW));
            GLCall(glCullFace(GL_BACK));
        }

        if(rendererParameters & (Bitfield)RendererParameters::DepthTest) {
            GLCall(glEnable(GL_DEPTH_TEST));
            GLCall(glDepthFunc(GL_LESS));
            m_clearBitfield |= (Bitfield)GL_DEPTH_BUFFER_BIT;
        }

        // TODO: handle texture blending
    }

    Renderer::~Renderer() {
        // There is no more renderer, GLEW is not longer needed
        if(Dependencies::IsGLEWActive() && InstanceCount() == 1) {
            Dependencies::ShutdownGLEW();
        }
    }

    void Renderer::clear() const {
        glClear(m_clearBitfield);
    }

    void Renderer::submit(Ref<VertexArray> &vertexArray, Ref<ShaderProgram> &program, Transform transform, RendererMode mode) const {
        vertexArray->bind();
        Ref<ElementBuffer> elementBuffer = vertexArray->elementBuffer();
        elementBuffer->bind();
        /* Binding each vertex buffers */
        for(Ref<VertexBuffer> vertexBuffer : vertexArray->vertexBuffers()) {
            vertexBuffer->bind();
        }

        GLCall(glDrawElements((GLenum)mode, elementBuffer->count(), elementBuffer->type(), nullptr));
        Texture2D::UnBind();
    }

}

#ifndef OCTOPUS_RENDERER_H
#define OCTOPUS_RENDERER_H

#include "util/ICounted.h"
#include "util/INonCopyable.h"

namespace Octo {

    class VertexBuffer;
    class ElementBuffer;
    class VertexArray;
    class ShaderProgram;
    class Attribute;

    /* Renderer parameters enum bitfield */
    enum class RendererParameters : Bitfield {
        DepthTest = BIT(1),
        CullFace = BIT(2),
        BlendTexture = BIT(3)
    };

    enum RendererMode {
        Points = GL_POINTS,
        LineStrip = GL_LINE_STRIP,
        LineLoop = GL_LINE_LOOP,
        Lines = GL_LINES,
        LineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
        LinesAdjacency = GL_LINES_ADJACENCY,
        TriangleStrip = GL_TRIANGLE_STRIP,
        TriangleFan = GL_TRIANGLE_FAN,
        Triangles = GL_TRIANGLES,
        TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
        TriangleAdjacency = GL_TRIANGLES_ADJACENCY,
        Patches = GL_PATCHES
    };

    class Renderer : ICounted, INonCopyable {
    public:
        Renderer(Bitfield rendererParameters = ((Bitfield)RendererParameters::DepthTest | (Bitfield)RendererParameters::CullFace));
        ~Renderer();

        void clear() const;
        /* Low-level drawing methods */
        void drawArrays(VertexBuffer& vertexBuffer, VertexArray& vertexArray, ShaderProgram& program, GLuint vertexCount, RendererMode mode = RendererMode::Triangles);
        void drawElements(ElementBuffer& elementBuffer, VertexArray& vertexArray, ShaderProgram& program, RendererMode mode = RendererMode::Triangles);

    private:
        // which bits should be cleared
        Bitfield m_clearBitfield;
    };

}

#endif //OCTOPUS_RENDERER_H

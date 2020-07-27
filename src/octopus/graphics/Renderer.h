#ifndef OCTOPUS_RENDERER_H
#define OCTOPUS_RENDERER_H

#include "util/Counted.h"
#include "maths/Transform.h"

namespace Octo {

    class VertexBuffer;
    class ElementBuffer;
    class VertexArray;
    class ShaderProgram;
    class Attribute;

    /* Renderer parameters enum bitfield */
    enum class OCTO_API RendererParameters : Bitfield {
        DepthTest = BIT(1),
        CullFace = BIT(2),
        BlendTexture = BIT(3)
    };

    enum OCTO_API RendererMode {
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

    class OCTO_API Renderer : Counted {
    public:
        Renderer(Bitfield rendererParameters = ((Bitfield)RendererParameters::DepthTest | (Bitfield)RendererParameters::CullFace));
        ~Renderer();

        void clear() const;

        void submit(Ref<VertexArray>& vertexArray, Ref<ShaderProgram>& program, Transform transform = glm::mat4(1.0f), RendererMode mode = RendererMode::Triangles) const;

    private:
        // which bits should be cleared
        Bitfield m_clearBitfield;
    };

}

#endif //OCTOPUS_RENDERER_H

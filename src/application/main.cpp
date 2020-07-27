#include "Octopus.h"
#include "graphics/Graphics.h"
#include <string>

#include "events/WindowEvents.h"
#include "events/FrameBufferEvents.h"
#include "events/KeyboardEvents.h"
#include "events/MouseEvents.h"

class Application : public OCTO_API Octo::IApplication {
public:
    Application(const std::string& name)
        : Octo::IApplication(name, 1280, 720)
    { }

    void run() override {
        using namespace Octo;

        GLfloat data[] = {
             -0.5f, -0.5f, 0.0f,    0.0f, 1.0f,
              0.5f, -0.5f, 0.0f,    1.0f, 1.0f,
              0.5f,  0.5f, 0.0f,    1.0f, 0.0f,
             -0.5f,  0.5f, 0.0f,    0.0f, 0.0f
        };

        GLuint indices[] = {
              0, 1, 2,
              2, 3, 0
        };

        Ref<ShaderProgram> program = ShaderProgram::Create({"src/application/shaders/debug.vs", "src/application/shaders/debug.fs"});
        Ref<VertexArray> vertexArray = VertexArray::Create();
        Layout layout = { { "a_position", 3 }, {"a_uv", 2} };
        Ref<VertexBuffer>vertexBuffer = VertexBuffer::Create(data, sizeof(data), GL_FLOAT, layout);
        Ref<ElementBuffer> elementBuffer = ElementBuffer::Create(indices, sizeof(indices), GL_UNSIGNED_INT);
        vertexArray->addVertexBuffer(vertexBuffer, program);
        vertexArray->addElementBuffer(elementBuffer);
        Ref<Texture2D> texture = Texture2D::Create("assets/texture.png");

        Ref<Event> pEvent;

        bool bShouldRun = true;
        while(bShouldRun) {
            m_renderer.clear();

            while(m_eventQueue.query(pEvent)) {
                switch (pEvent->type()) {
                    case EventType::WindowClosed:
                        bShouldRun = false;
                    default: break;
                }
            }

            if(m_eventQueue.input().isKeyPressed(OCTO_KEY_ESCAPE)) {
                bShouldRun = false;
            }

            texture->bind();
            program->setInt("u_texture", 0);
            m_renderer.submit(vertexArray, program);

            update();
        }
    }
};

int main() {
    try {
        Application *pApp = new Application("Sandbox");
        pApp->run();

        delete pApp;
    }
    catch(const std::runtime_error error) {
        OCTO_LOG_CRITICAL(error.what());
    }

    return 0;
}
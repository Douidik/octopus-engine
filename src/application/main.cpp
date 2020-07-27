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

        GLfloat vertices[] = {
             -0.5f, -0.5f, 0.0f,
              0.5f, -0.5f, 0.0f,
              0.5f,  0.5f, 0.0f,
             -0.5f,  0.5f, 0.0f,
        };

        GLuint indices[] = {
              0, 1, 2,
              2, 3, 0
        };

        ShaderProgram program({"src/application/shaders/debug.vs", "src/application/shaders/debug.fs"});
        VertexArray vertexArray = VertexArray();
        Layout layout = { { "a_position", 3 } };
        VertexBuffer vertexBuffer(vertices, sizeof(vertices), GL_FLOAT, layout);
        ElementBuffer elementBuffer(indices, sizeof(indices), GL_UNSIGNED_INT);
        vertexArray.addVertexBuffer(vertexBuffer, program);

        std::shared_ptr<Event> pEvent;

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

            m_renderer.drawElements(elementBuffer, vertexArray, program);

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
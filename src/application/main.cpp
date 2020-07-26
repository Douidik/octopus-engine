#include "Octopus.h"
#include "graphics/Graphics.h"
#include <string>

class Application : public OCTO_API Octo::IApplication {
public:
    Application(const std::string& sName)
        : Octo::IApplication(sName, 1280, 720)
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

        while(m_window.shouldRun()) {
            m_renderer.clear();

            m_renderer.drawElements(elementBuffer, vertexArray, program);

            update();
        }
    }

    ~Application() = default;
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
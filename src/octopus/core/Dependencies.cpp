#include "Dependencies.h"
#include "Window.h"

namespace Octo {

    bool Dependencies::s_bGLFWActive = false, Dependencies::s_bGLEWActive = false;

    /* When GLFW throws an error, this function will log it with our native system */
    void GLFWErrorCallback(int _error, const char* description) {
        std::string error = std::to_string(_error);
        OCTO_LOG_ERROR("[GLFW Error #"s + error + "] "s + description);
    }

    bool Dependencies::InitGLFW() {
        glfwSetErrorCallback(GLFWErrorCallback);

        if(!glfwInit()) {
            s_bGLFWActive = false;
            throw std::runtime_error("[GLFW] Failed to initialize");
            return false;
        }

        s_bGLFWActive = true;
        return true;
    }

    bool Dependencies::InitGLEW() {
        // Check if a context is available for rendering
        if(!Window::IsInstancied()) {
            throw std::runtime_error("[GLEW] No context available for rendering");
            return false;
        }

        glewExperimental = true;

        if(glewInit() != GLEW_OK) {
            s_bGLEWActive = false;
            throw std::runtime_error("[GLEW] Failed to initialize");
            return false;
        }

        s_bGLEWActive = true;
        return true;
    }

    void Dependencies::ShutdownGLFW() {
        s_bGLFWActive = false;
        glfwTerminate();
    }

    void Dependencies::ShutdownGLEW() {
        s_bGLEWActive = false;
        return;
    }
}
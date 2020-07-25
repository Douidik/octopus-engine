#include "OctopusPCH.h"
#include "Window.h"
#include "Dependencies.h"

namespace Octo {

    Window::Window(const Properties &properties)
        : m_properties(properties)
    {
        if(!Dependencies::IsGLFWActive()) {
            Dependencies::InitGLFW();
        }

        m_pNativeWindow = glfwCreateWindow(properties.width, properties.height, properties.name.c_str(), nullptr, nullptr);

        if(!m_pNativeWindow) {
            OCTO_LOG_ERROR("[GLFW] Failed to create the window");
            return;
        }

        glfwMakeContextCurrent(m_pNativeWindow);
    }

    Window::~Window() {
        glfwDestroyWindow(m_pNativeWindow);

        if(InstanceCount() == 1) { // This window is the only active window, and will be deleted
            // We shutdown GLFW
            Dependencies::ShutdownGLFW();
        }
    }

    void Window::update() {
        glfwSwapBuffers(m_pNativeWindow);
        glfwPollEvents();
    }

    bool Window::shouldRun() {
        return !glfwWindowShouldClose(m_pNativeWindow);
    }

}
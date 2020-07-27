#ifndef OCTOPUS_WINDOW_H
#define OCTOPUS_WINDOW_H

#include "util/Counted.h"

namespace Octo {

    //GLFW window user pointer, this struct is linked with the glfw native window
    struct WindowProperties {
        const std::string name;
        int width, height;
        int x, y;
        //Pointer to the application event queue
        class EventQueue* pEventQueue;

        // Called in Application constructor
        WindowProperties(const std::string &_name, int _width, int _height)
                : name(_name), width(_width), height(_height)
        {}
    };

    class OCTO_API Window : public Counted {
    public:
        Window(const WindowProperties &properties);
        ~Window();

        void update();
        bool shouldRun();

        inline void bind() const {
            glfwMakeContextCurrent(m_pNativeWindow);
        }
        inline void unbind() const {
            glfwMakeContextCurrent(nullptr);
        }

        inline WindowProperties &properties() {
            return m_properties;
        }

        inline WindowProperties properties() const {
            return m_properties;
        }

        // Returns the native GLFW window pointer
        inline GLFWwindow* native() {
            return m_pNativeWindow;
        }

    private:
        GLFWwindow* m_pNativeWindow;
        WindowProperties m_properties;
    };

}

#endif //OCTOPUS_WINDOW_H

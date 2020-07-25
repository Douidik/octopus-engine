#ifndef APPLICATION_WINDOW_H
#define APPLICATION_WINDOW_H

#include "util/ICounted.h"

namespace Octo {

    class OCTO_API Window : public ICounted {
    public:
        struct Properties {
            const std::string name;
            int width, height;

            // Called in Application constructor
            Properties(const std::string &_name, int _width, int _height)
                : name(_name), width(_width), height(_height)
            {}

            // Pass in Application constructor
            Properties(int _width, int _height)
                : name("undefined"), width(_width), height(_height)
            {}

        };

        Window(const Properties &properties);
        ~Window();

        void update();
        bool shouldRun();

        inline void bind() const {
            glfwMakeContextCurrent(m_pNativeWindow);
        }
        inline void unbind() const {
            glfwMakeContextCurrent(nullptr);
        }

        inline Properties properties() const {
            return m_properties;
        }


    private:
        GLFWwindow* m_pNativeWindow;
        Properties m_properties;
    };

}

#endif //APPLICATION_WINDOW_H

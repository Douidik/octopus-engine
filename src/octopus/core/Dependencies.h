#ifndef OCTOPUS_DEPENDENCIES_H
#define OCTOPUS_DEPENDENCIES_H

namespace Octo {

    /* This static class will provides us dependencies initialization and shutdown */
    class Dependencies {
    public:
        static bool InitGLFW();
        static bool InitGLEW();

        static void ShutdownGLFW();
        static void ShutdownGLEW();

        static bool IsGLFWActive() {
            return s_bGLFWActive;
        }
        static bool IsGLEWActive() {
            return s_bGLEWActive;
        }

    private:
        static bool s_bGLFWActive, s_bGLEWActive;
    };

}

#endif //OCTOPUS_DEPENDENCIES_H

#ifndef OCTOPUS_CORE_H
#define OCTOPUS_CORE_H

using namespace std::string_literals;

/* Defining Platform specific macros, only Windows and Linux are supported for now */
#ifdef _WIN32
    #define OCTO_WINDOWS

    #ifdef OCTO_BUILD_DLL
        #define OCTO_API __declspec(dllexport)
    #else
        #define OCTO_API __declspec(dllimport)
    #endif

#elif defined(__APPLE__)
    #error "Mac OS is not supported."

#elif defined(__linux__)
    #define OCTO_LINUX

    #ifdef OCTO_BUILD_DLL
        #define OCTO_API __attribute__((visibility("default")))
    #else
        #define OCTO_API
    #endif

#endif

namespace Octo {

    class OCTO_API Core {
    public:
        static bool Initialize();
        static void Shutdown();

        inline static bool IsActive() {
            return s_bInitialized;
        }

    private:
        static bool s_bInitialized;
    };

}

#endif //OCTOPUS_CORE_H

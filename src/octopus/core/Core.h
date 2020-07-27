#ifndef OCTOPUS_CORE_H
#define OCTOPUS_CORE_H


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

using namespace std::string_literals;

namespace Octo {

    using Bitfield = uint64_t;
    #define BIT(x) 1 << x

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T, typename... Args>
    constexpr Ref<T> CreateRef(Args&&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

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

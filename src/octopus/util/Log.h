#ifndef OCTOPUS_LOG_H
#define OCTOPUS_LOG_H

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "core/Core.h"

namespace Octo {

    class OCTO_API Log {
    public:
        static void Initialize();

        static void Shutdown();

        static inline Ref<spdlog::logger> GetOctoLogger() {
            return s_octoLogger;
        }
        static inline Ref<spdlog::logger> GetAppLogger() {
            return s_appLogger;
        }

    private:
        /* We create two loggers, one for the engine and the other for the application */
        static Ref<spdlog::logger> s_octoLogger, s_appLogger;
    };
}

/* LOGGING MACROS */
#define OCTO_LOG_TRACE(...)    ::Octo::Log::GetOctoLogger()->trace(__VA_ARGS__)
#define OCTO_LOG_DEBUG(...)    ::Octo::Log::GetOctoLogger()->debug(__VA_ARGS__)
#define OCTO_LOG_INFO(...)     ::Octo::Log::GetOctoLogger()->info(__VA_ARGS__)
#define OCTO_LOG_WARN(...)     ::Octo::Log::GetOctoLogger()->warn(__VA_ARGS__)
#define OCTO_LOG_ERROR(...)    ::Octo::Log::GetOctoLogger()->error(__VA_ARGS__)
#define OCTO_LOG_CRITICAL(...) ::Octo::Log::GetOctoLogger()->critical(__VA_ARGS__)

#define APP_LOG_TRACE(...)    ::Octo::Log::GetAppLogger()->trace(__VA_ARGS__)
#define APP_LOG_DEBUG(...)    ::Octo::Log::GetAppLogger()->debug(__VA_ARGS__)
#define APP_LOG_INFO(...)     ::Octo::Log::GetAppLogger()->info(__VA_ARGS__)
#define APP_LOG_WARN(...)     ::Octo::Log::GetAppLogger()->warn(__VA_ARGS__)
#define APP_LOG_ERROR(...)    ::Octo::Log::GetAppLogger()->error(__VA_ARGS__)
#define APP_LOG_CRITICAL(...) ::Octo::Log::GetAppLogger()->critical(__VA_ARGS__)

#endif //OCTOPUS_LOG_H

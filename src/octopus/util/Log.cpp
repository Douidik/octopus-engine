#include "OctopusPCH.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Octo {

    Ref<spdlog::logger> Log::s_octoLogger, Log::s_appLogger;

    void Log::Initialize() {
        s_octoLogger = spdlog::stderr_color_mt("OCTO", spdlog::color_mode::always);
        s_appLogger  = spdlog::stderr_color_mt("APP", spdlog::color_mode::always);

        if(!s_octoLogger || !s_appLogger) {
            throw std::runtime_error("Failed to initialize the logging system");
        }

        s_octoLogger->set_level(spdlog::level::trace);
        s_appLogger->set_level(spdlog::level::trace);

        /* Setting up logging custom pattern, e.g: [OCTO: 23:55:59] Renderer Initialized  */
        s_octoLogger->set_pattern("[%n: %T] %v");
        s_appLogger->set_pattern("[%n: %T] %v");

        OCTO_LOG_INFO("Logging initialized");
    }

    void Log::Shutdown() {
        s_octoLogger.reset();
        s_appLogger.reset();
    }

}
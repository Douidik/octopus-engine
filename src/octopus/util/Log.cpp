#include "OctopusPCH.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Octo {

    std::shared_ptr<spdlog::logger> Log::s_pOctoLogger, Log::s_pAppLogger;

    void Log::Initialize() {
        s_pOctoLogger = spdlog::stderr_color_mt("OCTO", spdlog::color_mode::always);
        s_pAppLogger  = spdlog::stderr_color_mt("APP", spdlog::color_mode::always);

        if(!s_pOctoLogger || !s_pAppLogger) {
            throw std::runtime_error("Failed to initialize the logging system");
        }

        s_pOctoLogger->set_level(spdlog::level::trace);
        s_pAppLogger->set_level(spdlog::level::trace);

        /* Setting up logging custom pattern, e.g: [OCTO: 23:55:59] Renderer Initialized  */
        s_pOctoLogger->set_pattern("[%n: %T] %v");
        s_pAppLogger->set_pattern("[%n: %T] %v");

        OCTO_LOG_INFO("Logging initialized");
    }

    void Log::Shutdown() {
        s_pOctoLogger.reset();
        s_pAppLogger.reset();
    }

}
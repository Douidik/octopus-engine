#include "Core.h"
#include "util/Log.h"

namespace Octo {

    bool Core::s_bInitialized = false;

    bool Core::Initialize() {
        Core::s_bInitialized = true;

        Log::Initialize();
        OCTO_LOG_INFO("Core Initialized");

        return true;
    }

    void Core::Shutdown() {
        Core::s_bInitialized = false;

        Log::Shutdown();
    }

}
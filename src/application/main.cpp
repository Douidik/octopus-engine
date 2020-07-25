#include "Octopus.h"
#include <string>

class Application : public OCTO_API Octo::IApplication {
public:
    Application(const std::string& sName)
        : Octo::IApplication(sName, 1280, 720)
    { }

    void run() override {
        while(m_window.shouldRun()) {
            update();
        }
    }

    ~Application() = default;
};

int main() {
    try {
        Application *pApp = new Application("Sandbox");
        pApp->run();

        delete pApp;
    }
    catch(const std::runtime_error error) {
        OCTO_LOG_CRITICAL(error.what());
    }

    return 0;
}
#include "Octopus.h"
#include <string>

class Application : public OCTO_API Octo::IApplication {
public:
    Application(const std::string& sName)
    : Octo::IApplication(sName)
    { }

    virtual void update() override {
        Octo::IApplication::update();
    }

    ~Application() = default;
};

int main() {
    Application *pApp = new Application("Sandbox");

    do {
        pApp->update();
    } while(pApp->isRunning());

    delete pApp;
    return 0;
}
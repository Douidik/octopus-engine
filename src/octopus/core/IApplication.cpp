#include "OctopusPCH.h"
#include "IApplication.h"
#include "Window.h"

namespace Octo {

    IApplication::IApplication(const std::string &name, int windowWidth, int windowHeight)
        : m_name(name), m_window({name, windowWidth, windowHeight}), m_eventQueue(&m_window)
    {
        if(!Core::IsActive()){
            Core::Initialize();
        }
    }

    void IApplication::update() {
        m_window.update();
    }

    IApplication::~IApplication()
    {
        if(InstanceCount() == 1 && Core::IsActive()) { // Is the last running application and the core is running
            //The core is not longer required
            Core::Shutdown();
        }
    }

}
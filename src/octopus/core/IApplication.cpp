#include "OctopusPCH.h"
#include "IApplication.h"

namespace Octo {

    unsigned int IApplication::s_uiInstanceCount = 0;
    using namespace std::chrono_literals;

    IApplication::IApplication(const std::string &sName)
        :m_sName(sName), m_bRunning(true)
    {
        s_uiInstanceCount++;

        if(!Core::IsInitialized()){
            Core::Initialize();
        }
    }

    void IApplication::update() {

    }

    IApplication::~IApplication()
    {
        m_bRunning = false;
        s_uiInstanceCount--;

        if(s_uiInstanceCount <= 0 && Core::IsInitialized()) {
            Core::Shutdown();
        }
    }

}
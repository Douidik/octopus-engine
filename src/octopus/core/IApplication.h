#ifndef OCTOPUS_IAPPLICATION_H
#define OCTOPUS_IAPPLICATION_H

#include "util/NonCopyable.h"
#include <string>
#include <chrono>

namespace Octo {

    class OCTO_API IApplication : private NonCopyable {
    public:
        IApplication(const std::string &sName);

        virtual void update();

        inline bool isRunning() const {
            return m_bRunning;
        }

        ~IApplication();

    private:
        const std::string m_sName;
        bool m_bRunning;

    private:
        //Number of running applications
        static unsigned int s_uiInstanceCount;
    };

}
#endif //OCTOPUS_IAPPLICATION_H

#ifndef OCTOPUS_IAPPLICATION_H
#define OCTOPUS_IAPPLICATION_H

#include "util/INonCopyable.h"
#include "util/ICounted.h"
#include "Window.h"

namespace Octo {

    class OCTO_API IApplication : private INonCopyable, private ICounted {
    public:
        IApplication(const std::string &sName, int windowWidth, int windowHeight);
        ~IApplication();

        // Implement this method to run the main loop
        virtual void run() = 0;
        // Must be called in the run implemented function
        void update();


    protected:
        Window m_window;

    private:
        const std::string m_sName;
    };

}
#endif //OCTOPUS_IAPPLICATION_H

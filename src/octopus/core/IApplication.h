#ifndef OCTOPUS_IAPPLICATION_H
#define OCTOPUS_IAPPLICATION_H

#include "util/Counted.h"
#include "Window.h"
#include "graphics/Renderer.h"
#include "events/Events.h"
#include "events/EventQueue.h"

namespace Octo {

    class OCTO_API IApplication : private Counted {
    public:
        IApplication(const std::string &name, int windowWidth, int windowHeight);
        ~IApplication();

        // Implement this method to run the main loop
        virtual void run() = 0;
        // Must be called in the run implemented function
        void update();


    protected:
        Window m_window;
        Renderer m_renderer;
        EventQueue m_eventQueue;

    private:
        const std::string m_name;
    };

}
#endif //OCTOPUS_IAPPLICATION_H

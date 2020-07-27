#ifndef OCTOPUS_EVENTQUEUE_H
#define OCTOPUS_EVENTQUEUE_H

#include "Events.h"
#include "Input.h"

namespace Octo {

    class OCTO_API EventQueue {
    public:
        EventQueue() = default;
        EventQueue(class Window *pWindow);
        ~EventQueue() = default;
        //Get the front of the event queue, if there is no more event in the queue p_event will be nullptr and we return false
        bool query(std::shared_ptr<Event> &pEvent);
        inline const Input& input() const { return m_input; }

    private:
        std::queue<std::shared_ptr<Event>> m_queue;
        Input m_input;
    };


}

#endif //OCTOPUS_EVENTQUEUE_H

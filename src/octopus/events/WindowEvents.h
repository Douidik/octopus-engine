#ifndef OCTOPUS_WINDOWEVENTS_H
#define OCTOPUS_WINDOWEVENTS_H

#include "Events.h"

namespace Octo {

    class OCTO_API WindowMovedEvent : public Event {
    public:
        WindowMovedEvent(int x, int y)
            : Event(EventType::WindowMoved), m_x(x), m_y(y)
        {}

        inline int x() const { return m_x; }
        inline int y() const { return m_y; }

        std::string info() const override;

    private:
        int m_x, m_y;
    };

    class OCTO_API WindowResizedEvent : public Event {
    public:
        WindowResizedEvent(int width, int height)
                : Event(EventType::WindowResized), m_width(width), m_height(height)
        {}

        inline int width() const { return m_width; }
        inline int height() const { return m_height; }

        std::string info() const override;

    private:
        int m_width, m_height;
    };

    class OCTO_API WindowClosedEvent : public Event {
    public:
        WindowClosedEvent()
                : Event(EventType::WindowClosed)
        {}

        std::string info() const override;
    };

    class OCTO_API WindowFocusedEvent : public Event {
    public:
        WindowFocusedEvent()
                : Event(EventType::WindowFocused)
        {}

        std::string info() const override;
    };

    class OCTO_API WindowDefocusedEvent : public Event {
    public:
        WindowDefocusedEvent()
                : Event(EventType::WindowDefocused)
        {}

        std::string info() const override;
    };

}

#endif //OCTOPUS_WINDOWEVENTS_H

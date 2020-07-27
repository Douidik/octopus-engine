#ifndef OCTOPUS_MOUSEEVENTS_H
#define OCTOPUS_MOUSEEVENTS_H

#include "Events.h"
#include "ButtonCode.h"

namespace Octo {
    /* Abstract Key event for input event class */
    class OCTO_API ButtonInputEvent : public Event{
    public:
        ButtonInputEvent(EventType type, ButtonCode code)
                : Event(type), m_code(code)
        {}

        ~ButtonInputEvent() = default;

        inline ButtonCode button() const { return m_code; }

    protected:
        ButtonCode m_code;
    };

    class OCTO_API ButtonPressedEvent : public ButtonInputEvent {
    public:
        ButtonPressedEvent(ButtonCode code)
            : ButtonInputEvent(EventType::ButtonPressed, code)
        {}

        std::string info() const override;
    };

    class OCTO_API ButtonReleasedEvent : public ButtonInputEvent {
    public:
        ButtonReleasedEvent(ButtonCode code)
                : ButtonInputEvent(EventType::ButtonReleased, code)
        {}

        std::string info() const override;
    };

    using CursorPosition = std::pair<double, double>;

    class OCTO_API CursorMovedEvent : public Event {
    public:
        CursorMovedEvent(double x, double y)
            : Event(EventType::CursorMoved), m_position({x, y})
        {}

        inline double x() const { return m_position.first; }
        inline double y() const { return m_position.second; }

        std::string info() const override;

    private:
        CursorPosition m_position;
    };

    class OCTO_API CursorEnteredEvent : public Event {
    public:
        CursorEnteredEvent()
            : Event(EventType::CursorEntered)
        {}

        std::string info() const override;
    };

    class OCTO_API CursorLeftEvent : public Event {
    public:
        CursorLeftEvent()
                : Event(EventType::CursorLeft)
        {}

        std::string info() const override;
    };

    class OCTO_API MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent(int x, int y)
                : Event(EventType::MouseScrolled), m_x(x), m_y(y)
        {}

        inline int x() const { return m_x; }
        inline int y() const { return m_y; }

        std::string info() const override;

    private:
        int m_x, m_y;
    };

}

#endif //OCTOPUS_MOUSEEVENTS_H

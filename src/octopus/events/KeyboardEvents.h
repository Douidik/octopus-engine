#ifndef OCTOPUS_KEYBOARDEVENTS_H
#define OCTOPUS_KEYBOARDEVENTS_H

#include "Events.h"
#include "KeyCode.h"

namespace Octo {

    /* Abstract Key event for input event class */
    class OCTO_API KeyInputEvent : public Event{
    public:
        KeyInputEvent(EventType type, KeyCode code)
            : Event(type), m_code(code)
        {}

        ~KeyInputEvent() = default;

        inline KeyCode code() const { return m_code; }

    protected:
        KeyCode m_code;
    };

    class OCTO_API KeyPressedEvent : public KeyInputEvent {
    public:
        KeyPressedEvent(KeyCode code)
            : KeyInputEvent(EventType::KeyPressed, code)
        {}

        std::string info() const override;
    };

    class OCTO_API KeyReleasedEvent : public KeyInputEvent{
    public:
        KeyReleasedEvent(KeyCode code)
            : KeyInputEvent(EventType::KeyReleased, code)
        {}

        std::string info() const override;
    };

    class OCTO_API KeyRepeatedEvent : public KeyInputEvent {
    public:
        KeyRepeatedEvent(KeyCode code)
            : KeyInputEvent(EventType::KeyRepeated, code)
        {}

        std::string info() const override;
    };
}

#endif //OCTOPUS_KEYBOARDEVENTS_H

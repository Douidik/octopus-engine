#ifndef OCTOPUS_EVENTS_H
#define OCTOPUS_EVENTS_H

namespace Octo {

    enum OCTO_API EventType {
        None = 0,

        /* Window Event Category */
        WindowMoved    ,
        WindowResized  ,
        WindowClosed   ,
        WindowFocused  ,
        WindowDefocused,

        /* FrameBuffer Event Category */
        FrameBufferResized,

        /* MOUSE EVENT CATEGORY */

        /* - Button Event Sub-Category */

        ButtonPressed ,
        ButtonReleased,

        /* - Cursor Event Sub-Category */

        CursorMoved  ,
        CursorEntered,
        CursorLeft   ,

        /* - Mouse Scrolled Sub-Category */
        MouseScrolled,

        /* Keyboard Category */
        KeyPressed ,
        KeyReleased,
        KeyRepeated
    };

    class OCTO_API Event {
    public:
        Event()
            :m_type(EventType::None)
        {}


        Event(EventType type)
            : m_type(type)
        {}

        virtual ~Event() = default;
        inline EventType type() const { return m_type; }
        std::string name() const;
        virtual std::string info() const;

    private:
        EventType m_type;
    };

    inline std::ostream& operator<<(std::ostream &os, const Event &event) {
        return os << event.info();
    }

}

#endif //OCTOPUS_EVENTS_H

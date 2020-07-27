#include "OctopusPCH.h"
#include "MouseEvents.h"

namespace Octo {

    std::string ButtonPressedEvent::info() const {
        std::string_view buttonName = magic_enum::enum_name(m_code);
        return std::string("Mouse button "s + std::string(buttonName) + " pressed"s);
    }

    std::string ButtonReleasedEvent::info() const {
        std::string_view buttonName = magic_enum::enum_name(m_code);
        return std::string("Mouse button "s + std::string(buttonName) + " released"s);
    }

    std::string CursorMovedEvent::info() const {
        return std::string("Mouse moved: "s + std::to_string(m_position.first) + "X, " + std::to_string(m_position.second) + "Y"s);
    }

    std::string CursorEnteredEvent::info() const {
        return std::string("Mouse entered");
    }

    std::string CursorLeftEvent::info() const {
        return std::string("Mouse left");
    }

    std::string MouseScrolledEvent::info() const {
        return std::string("Mouse scrolled: "s + std::to_string(m_x) + "X, " + std::to_string(m_y) + "Y"s);
    }
}
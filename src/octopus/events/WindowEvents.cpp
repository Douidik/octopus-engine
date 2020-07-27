#include "OctopusPCH.h"
#include "WindowEvents.h"

namespace Octo {

    std::string WindowMovedEvent::info() const {
        return std::string("Window moved: "s + std::to_string(m_x) + "X, "s + std::to_string(m_y) + "Y"s);
    }

    std::string WindowResizedEvent::info() const {
        return std::string("Window resized: "s + std::to_string(m_width) + "W, "s + std::to_string(m_height) + "H"s);
    }

    std::string WindowClosedEvent::info() const {
        return std::string("Window closed");
    }

    std::string WindowFocusedEvent::info() const {
        return std::string("Window focused");
    }

    std::string WindowDefocusedEvent::info() const {
        return std::string("Window defocused");
    }

}

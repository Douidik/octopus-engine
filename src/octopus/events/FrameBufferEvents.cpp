#include "OctopusPCH.h"
#include "FrameBufferEvents.h"

namespace Octo {

    std::string FrameBufferResizedEvent::info() const {
        return std::string(
                "Framebuffer resized: "s + std::to_string(m_width) + "W, "s + std::to_string(m_height) + "H"s);
    }

}

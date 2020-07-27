#include "OctopusPCH.h"
#include "KeyboardEvents.h"

namespace Octo {

    std::string KeyPressedEvent::info() const {
        std::string_view keyName = magic_enum::enum_name(code());
        return std::string("Key "s + std::string(keyName) + " pressed"s);
    }

    std::string KeyReleasedEvent::info() const {
        std::string_view keyName = magic_enum::enum_name(code());
        return std::string("Key "s + std::string(keyName) + " released"s);
    }

    std::string KeyRepeatedEvent::info() const {
        std::string_view keyName = magic_enum::enum_name(code());
        return std::string("Key "s + std::string(keyName) + " repeated"s);
    }
}
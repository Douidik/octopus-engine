#include "OctopusPCH.h"
#include "Events.h"

namespace Octo {

    std::string Event::name() const {
        std::string_view _name = magic_enum::enum_name(m_type);
        return std::string(_name.data());
    }

    std::string Event::info() const {
        // By default we return the name
        return name();
    }

}
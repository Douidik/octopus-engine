#include "OctopusPCH.h"
#include "ConfigurationFile.h"

namespace Octo {

    ConfigurationFile::ConfigurationFile(const std::string &filepath) {
        m_file = YAML::LoadFile(filepath);
    }

}

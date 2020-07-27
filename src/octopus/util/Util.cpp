#include "OctopusPCH.h"
#include "Util.h"

std::optional<std::string> Octo::GetStringFromFile(const std::string &filepath, std::ios::openmode mode) {
    if(std::filesystem::exists(filepath)) {
        std::ifstream stream(filepath, mode);
        if(stream) {
            std::stringstream sstr;
            sstr << stream.rdbuf();
            return sstr.str();
        }

        return std::nullopt;
    }

    OCTO_LOG_ERROR("File "s + filepath + " is not found");
    return std::nullopt;
}

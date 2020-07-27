#ifndef OCTOPUS_CONFIGURATIONFILE_H
#define OCTOPUS_CONFIGURATIONFILE_H

namespace Octo {

    /* Configuration file using YAML */
    class ConfigurationFile {
    public:
        explicit ConfigurationFile(const std::string& filepath);

        template<typename T>
        T read(const std::string& key) {
            return m_file[key].as<T>();
        }

        template<typename T>
        void write(const std::string& key, T value) {
            m_file[key] = value;
        }

    private:
        YAML::Node m_file;
    };

}

#endif //OCTOPUS_CONFIGURATIONFILE_H

#ifndef OCTOPUS_SHADERPROGRAM_H
#define OCTOPUS_SHADERPROGRAM_H

namespace Octo {

    using ShadersPaths = const std::pair<std::string, std::string>&;
    using ShadersSources = std::pair<std::string, std::string>;
    using Cache = std::unordered_map<std::string, GLint>;

    class ShaderProgram {
    public:
        ShaderProgram(ShadersPaths paths, const std::string& name = "default");
        ~ShaderProgram();

        inline void bind() const {
            glUseProgram(m_uRendererID);
        }

        inline void unbind() const {
            glUseProgram(0);
        }

        inline const std::string &name() const {
            return m_sName;
        }


        //Returns and stores the attribute location by his name, returns -1 for an incorrect name
        GLint attributeLocation(const std::string& sName);

        /* Uniforms methods */

        // Returns and stores the uniform location by his name, returns -1 for an incorrect name
        GLint uniformLocation(const std::string &sName);

        void setFloat(const std::string& sName, float value);
        void setInt(const std::string& sName, int value);
        void setUnsignedInt(const std::string& sName, unsigned int value);
        void setVector2(const std::string& sName, glm::vec2 value);
        void setVector3(const std::string& sName, glm::vec3 value);
        void setVector4(const std::string& sName, glm::vec4 value);
        void setMatrix3(const std::string& sName, glm::mat3 value, bool bTranspose = false);
        void setMatrix4(const std::string& sName, glm::mat4 value, bool bTranspose = false);

    private:
        /* Shader parsing and program creation */
        const std::string parseName(const std::string& _sName, ShadersPaths paths);
        ShadersSources readShaders(ShadersSources sources);
        GLuint createProgram(ShadersSources sources);
        GLuint createShader(const std::string sSource, GLenum type);


        Cache m_attributeCache, m_uniformCache;
        std::string m_sName;
        GLuint m_uRendererID;
    };

}


#endif //OCTOPUS_SHADERPROGRAM_H

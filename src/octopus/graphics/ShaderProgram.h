#ifndef OCTOPUS_SHADERPROGRAM_H
#define OCTOPUS_SHADERPROGRAM_H

namespace Octo {

    using ShadersPaths = const std::pair<std::string, std::string>&;
    using ShadersSources = std::pair<std::string, std::string>;
    using OptShadersSources = std::pair<std::optional<std::string>, std::optional<std::string>>;
    using Cache = std::unordered_map<std::string, GLint>;

    class OCTO_API ShaderProgram {
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
            return m_name;
        }


        //Returns and stores the attribute location by his name, returns -1 for an incorrect name
        GLint attributeLocation(const std::string& name);

        /* Uniforms methods */

        // Returns and stores the uniform location by his name, returns -1 for an incorrect name
        GLint uniformLocation(const std::string &name);

        void setFloat(const std::string& name, float value);
        void setInt(const std::string& name, int value);
        void setUnsignedInt(const std::string& name, unsigned int value);
        void setVector2(const std::string& name, glm::vec2 value);
        void setVector3(const std::string& name, glm::vec3 value);
        void setVector4(const std::string& name, glm::vec4 value);
        void setMatrix3(const std::string& name, glm::mat3 value, bool bTranspose = false);
        void setMatrix4(const std::string& name, glm::mat4 value, bool bTranspose = false);

    private:
        /* Shader parsing and program creation */
        const std::string parseName(const std::string& _name, ShadersPaths paths);
        OptShadersSources readShaders(ShadersPaths paths);
        GLuint createProgram(ShadersSources sources);
        GLuint createShader(const std::string source, GLenum type);


        Cache m_attributeCache, m_uniformCache;
        std::string m_name;
        GLuint m_uRendererID;
    };

}


#endif //OCTOPUS_SHADERPROGRAM_H

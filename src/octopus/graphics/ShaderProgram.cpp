#include "OctopusPCH.h"
#include "ShaderProgram.h"
#include "util/Util.h"

namespace Octo {

    ShaderProgram::ShaderProgram(ShadersPaths paths, const std::string &name)
        : m_name(parseName(name, paths))
    {
        OptShadersSources sources = readShaders(paths);
        if(!sources.first.has_value() || !sources.second.has_value()) { // Sources are not valid ?
            return;
        }

        m_uRendererID = createProgram({sources.first.value(), sources.second.value()});
    }

    ShaderProgram::~ShaderProgram() {
        GLCall(glDeleteProgram(m_uRendererID));
    }

    const std::string ShaderProgram::parseName(const std::string &_name, ShadersPaths &paths) {
        /*
         * name is not defined, the name will be defaulted by the path of the shader without the extension
         * e.g, shaders/ < common > .glsl
         */
        if(_name == "default") {
            // We take the vertex path to create the name
            std::string vertexPath = paths.first;

            // Check if the path is using the windows style (using backslashes for the path)
            size_t lastSlash = vertexPath.find_last_of('\\'); // The last slash will be the name's previous character
            if(lastSlash == std::string::npos) { // The path is not in windows style checking for common style (using /)
                lastSlash = vertexPath.find_last_of('/');
                if(lastSlash == std::string::npos) { // The path is not in a sub-folder
                    // The first letter of the path is also the first letter of the name
                    lastSlash = vertexPath[0];
                }
            }

            // The last dot is the extension dot
            size_t lastDot = vertexPath.find_last_of('.');
            size_t length = (lastDot - lastSlash) - 1;

            std::string name = vertexPath.substr(lastSlash + 1, length);
            // Capitalizing the name
            name[0] = std::toupper(name[0]);

            return name;
        } else { // Name is defined
            return _name;
        }
    }

    OptShadersSources ShaderProgram::readShaders(ShadersPaths paths) {
        auto vertexSource   = GetStringFromFile(paths.first);
        auto fragmentSource = GetStringFromFile(paths.second);

        return { vertexSource, fragmentSource };
    }

    GLuint ShaderProgram::createProgram(ShadersSources sources) {
        GLuint uVertexID   = createShader(sources.first,  GL_VERTEX_SHADER);
        GLuint uFragmentID = createShader(sources.second, GL_FRAGMENT_SHADER);

        GLuint uProgramID = glCreateProgram();

        /* Creating the program with compiled shaders */

        GLCall(glAttachShader(uProgramID, uVertexID));
        GLCall(glAttachShader(uProgramID, uFragmentID));

        GLCall(glLinkProgram(uProgramID));

        GLint iLinkResult;
        GLCall(glGetProgramiv(uProgramID, GL_LINK_STATUS, &iLinkResult));

        if(iLinkResult != GL_TRUE) { // Program linkage failed
            GLchar* glLog[2048]; // Creating the buffer for the error, max length is 2048
            GLCall(glGetProgramInfoLog(uProgramID, 2048, nullptr, glLog[0]));

            // Converting the log for our string format
            std::string log(*glLog);
            // Appending the name of the program
            log = m_name + ": \n" + log;
            OCTO_LOG_ERROR(log);
        }
        /* Detaching and freeing shaders */

        GLCall(glDetachShader(uProgramID, uVertexID));
        GLCall(glDetachShader(uProgramID, uFragmentID));

        GLCall(glDeleteShader(uVertexID));
        GLCall(glDeleteShader(uFragmentID));

        return uProgramID;
    }

    GLuint ShaderProgram::createShader(const std::string source, GLenum type) {
        GLuint uShaderID = glCreateShader(type);
        // Converting source to OpenGL format
        const GLchar* glSource = source.data();
        GLCall(glShaderSource(uShaderID, 1, &glSource, nullptr));
        GLCall(glCompileShader(uShaderID));

        return uShaderID;
    }

    GLint ShaderProgram::attributeLocation(const std::string &name) {
        if(m_attributeCache.find(name) != m_attributeCache.end()) {
            return m_attributeCache[name];
        }

        GLint location = glGetAttribLocation(m_uRendererID, name.c_str());

        if(location == -1) { // Attribute location was not found
            OCTO_LOG_WARN("Attribute \""s + name + "\" was not found in program \""s + m_name + "\""s);
        }

        m_attributeCache[name] = location;
        return location;
    }

    GLint ShaderProgram::uniformLocation(const std::string &name) {
        if(m_uniformCache.find(name) != m_uniformCache.end()) {
            return m_uniformCache[name];
        }

        GLint location = glGetUniformLocation(m_uRendererID, name.c_str());

        if(location == -1) { // Uniform location was not found
            OCTO_LOG_WARN("Uniform \""s + name + "\" was not found in program \""s + m_name + "\""s);
        }

        m_uniformCache[name] = location;
        return location;
    }

    void ShaderProgram::setFloat(const std::string &name, float value) {
        this->bind();
        GLCall(glUniform1f(uniformLocation(name), value));
    }

    void ShaderProgram::setInt(const std::string &name, int value) {
        this->bind();
        GLCall(glUniform1i(uniformLocation(name), value));
    }

    void ShaderProgram::setUnsignedInt(const std::string &name, unsigned int value) {
        this->bind();
        GLCall(glUniform1ui(uniformLocation(name), value));
    }

    void ShaderProgram::setVector2(const std::string &name, glm::vec2 value) {
        this->bind();
        GLCall(glUniform2f(uniformLocation(name), value.x, value.y));
    }

    void ShaderProgram::setVector3(const std::string &name, glm::vec3 value) {
        this->bind();
        GLCall(glUniform3f(uniformLocation(name), value.x, value.y, value.z));
    }

    void ShaderProgram::setVector4(const std::string &name, glm::vec4 value) {
        this->bind();
        GLCall(glUniform4f(uniformLocation(name), value.x, value.y, value.z, value.w));
    }

    void ShaderProgram::setMatrix3(const std::string &name, glm::mat3 value, bool bTranspose) {
        this->bind();
        GLCall(glUniformMatrix3fv(uniformLocation(name), 1, bTranspose, glm::value_ptr(value)));
    }

    void ShaderProgram::setMatrix4(const std::string &name, glm::mat4 value, bool bTranspose) {
        this->bind();
        GLCall(glUniformMatrix4fv(uniformLocation(name), 1, bTranspose, glm::value_ptr(value)));
    }


}
#include "OctopusPCH.h"
#include "ShaderProgram.h"


namespace Octo {

    ShaderProgram::ShaderProgram(ShadersPaths paths, const std::string &name)
        : m_sName(parseName(name, paths))
    {
        ShadersSources sources = readShaders(paths);
        m_uRendererID = createProgram(sources);
    }

    ShaderProgram::~ShaderProgram() {
        GLCall(glDeleteProgram(m_uRendererID));
    }

    const std::string ShaderProgram::parseName(const std::string &_sName, ShadersPaths &paths) {
        /*
         * name is not defined, the name will be defaulted by the path of the shader without the extension
         * e.g, shaders/ < common > .glsl
         */
        if(_sName == "default") {
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

            std::string sName = vertexPath.substr(lastSlash + 1, length);
            // Capitalizing the name
            sName[0] = std::toupper(sName[0]);

            return sName;
        } else { // Name is defined
            return _sName;
        }
    }

    ShadersSources ShaderProgram::readShaders(ShadersSources sources) {
        std::ifstream vertexStream(sources.first), fragmentStream(sources.second);


        if(vertexStream && fragmentStream) {  // Both sources are valid, we read the shaders
            std::stringstream vertexSstr, fragmentSstr;

            // streaming the shaders sources to string streams
            vertexSstr   << vertexStream.rdbuf();
            fragmentSstr << fragmentStream.rdbuf();

            // returning string streams converted to string
            return { vertexSstr.str(), fragmentSstr.str() };
        }
        else { // Failed to read shaders
            //e.g, Common program, failed to read shader(s) from: common.vs common.fs
            throw std::runtime_error(m_sName + "Program, failed to read shader(s) from: "s + (!vertexStream ? sources.first + " "s : ""s) + (!fragmentStream ? sources.second : ""s));
            return { "", "" };
        }
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
            std::string sLog(*glLog);
            // Appending the name of the program
            sLog = m_sName + ": \n" + sLog;
            OCTO_LOG_ERROR(sLog);
        }

        /* Detaching and freeing shaders */

        GLCall(glDetachShader(uProgramID, uVertexID));
        GLCall(glDetachShader(uProgramID, uFragmentID));

        GLCall(glDeleteShader(uVertexID));
        GLCall(glDeleteShader(uFragmentID));

        return uProgramID;
    }

    GLuint ShaderProgram::createShader(const std::string sSource, GLenum type) {
        GLuint uShaderID = glCreateShader(type);
        // Converting source to OpenGL format
        const GLchar* glSource = sSource.data();
        GLCall(glShaderSource(uShaderID, 1, &glSource, nullptr));
        GLCall(glCompileShader(uShaderID));

        return uShaderID;
    }

    GLint ShaderProgram::attributeLocation(const std::string &sName) {
        if(m_attributeCache.find(sName) != m_attributeCache.end()) {
            return m_attributeCache[sName];
        }

        GLint location = glGetAttribLocation(m_uRendererID, sName.c_str());

        if(location == -1) { // Attribute location was not found
            OCTO_LOG_WARN("Attribute \""s + sName + "\" was not found in program \""s + m_sName + "\""s);
        }

        m_attributeCache[sName] = location;
        return location;
    }

    GLint ShaderProgram::uniformLocation(const std::string &sName) {
        if(m_uniformCache.find(sName) != m_uniformCache.end()) {
            return m_uniformCache[sName];
        }

        GLint location = glGetUniformLocation(m_uRendererID, sName.c_str());

        if(location == -1) { // Uniform location was not found
            OCTO_LOG_WARN("Uniform \""s + sName + "\" was not found in program \""s + m_sName + "\""s);
        }

        m_uniformCache[sName] = location;
        return location;
    }

    void ShaderProgram::setFloat(const std::string &sName, float value) {
        this->bind();
        GLCall(glUniform1f(uniformLocation(sName), value));
    }

    void ShaderProgram::setInt(const std::string &sName, int value) {
        this->bind();
        GLCall(glUniform1i(uniformLocation(sName), value));
    }

    void ShaderProgram::setUnsignedInt(const std::string &sName, unsigned int value) {
        this->bind();
        GLCall(glUniform1ui(uniformLocation(sName), value));
    }

    void ShaderProgram::setVector2(const std::string &sName, glm::vec2 value) {
        this->bind();
        GLCall(glUniform2f(uniformLocation(sName), value.x, value.y));
    }

    void ShaderProgram::setVector3(const std::string &sName, glm::vec3 value) {
        this->bind();
        GLCall(glUniform3f(uniformLocation(sName), value.x, value.y, value.z));
    }

    void ShaderProgram::setVector4(const std::string &sName, glm::vec4 value) {
        this->bind();
        GLCall(glUniform4f(uniformLocation(sName), value.x, value.y, value.z, value.w));
    }

    void ShaderProgram::setMatrix3(const std::string &sName, glm::mat3 value, bool bTranspose) {
        this->bind();
        GLCall(glUniformMatrix3fv(uniformLocation(sName), 1, bTranspose, glm::value_ptr(value)));
    }

    void ShaderProgram::setMatrix4(const std::string &sName, glm::mat4 value, bool bTranspose) {
        this->bind();
        GLCall(glUniformMatrix4fv(uniformLocation(sName), 1, bTranspose, glm::value_ptr(value)));
    }


}
#ifndef OCTOPUS_UTIL_H
#define OCTOPUS_UTIL_H

namespace Octo {

    static GLsizei OCTO_API SizeOfGLType(GLenum type) {
        switch(type) {
            case GL_BYTE:           return sizeof(char);
            case GL_UNSIGNED_BYTE:  return sizeof(unsigned char);
            case GL_SHORT:          return sizeof(short);
            case GL_UNSIGNED_SHORT: return sizeof(unsigned short);
            case GL_INT:            return sizeof(int);
            case GL_UNSIGNED_INT:   return sizeof(unsigned int);
            case GL_FLOAT:          return sizeof(float);
            case GL_2_BYTES:        return sizeof(char) * 2;
            case GL_3_BYTES:        return sizeof(char) * 3;
            case GL_4_BYTES:        return sizeof(char) * 4;
            case GL_DOUBLE:         return sizeof(double);
            default:
                throw std::runtime_error("Unknown OpenGL Type");
                return 0;
        }
    }

}

#endif //OCTOPUS_UTIL_H

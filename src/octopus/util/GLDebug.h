#ifndef OCTOPUS_GLDEBUG_H
#define OCTOPUS_GLDEBUG_H

#ifndef MINECRAFT_DEBUG_H
#define MINECRAFT_DEBUG_H

namespace Octo {

#define ASSERT(x) if (!(x)) assert(false)
#define INT2VOIDP(i) (void*)(uintptr_t)(i)

    inline void GLClearError()
    {
        while (glGetError() != GL_NO_ERROR);
    }

    bool GLCheckError();


#ifndef NDEBUG
#define GLCall(x) GLClearError();\
                  x;\
                  ASSERT(GLCheckError())
#else
#define GLCall(x) x
#endif
}

#endif //MINECRAFT_DEBUG_H

#endif //OCTOPUS_GLDEBUG_H

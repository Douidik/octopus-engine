#ifndef OCTOPUS_TEXTURE_H
#define OCTOPUS_TEXTURE_H

namespace Octo {

    struct Image {
        Image(const std::string& filepath);
        void free();
        ~Image();

        int iWidth, iHeight, iBpp;
        unsigned char* pData;
        GLenum internalFormat, dataFormat;
        bool bFree; // Is image free
    };

    class Texture2D {
    public:
        Texture2D(const std::string& imageFilePath, bool bFreeImage = true);

        inline void bind(GLint iSlot = 0) const {
            GLCall(glActiveTexture(GL_TEXTURE0 + iSlot));
            GLCall(glBindTexture(GL_TEXTURE_2D, m_uRendererID));
        }

        inline void unbind() const {
            GLCall(glBindTexture(GL_TEXTURE_2D, 0));
        }

        inline Image image() { return m_image; }

    private:
        GLuint m_uRendererID;
        Image m_image;
    };

}

#endif //OCTOPUS_TEXTURE_H

#include "OctopusPCH.h"
#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Octo {

    Ref <Texture2D> Texture2D::Create(const std::string &filepath, bool bFreeImage) {
        return CreateRef<Texture2D>(filepath, bFreeImage);
    }

    Texture2D::~Texture2D() {
        glDeleteTextures(1, &m_uRendererID);
    }


    Image::Image(const std::string &filepath) {
        if(!std::filesystem::exists(filepath)) {
            OCTO_LOG_ERROR("Failed to read image from: "s + filepath);
            return;
        }

        stbi_set_flip_vertically_on_load(1);
        pData = stbi_load(filepath.c_str(), &iWidth, &iHeight, &iBpp, 0);

        bFree = false;

        if(!pData) {
            OCTO_LOG_ERROR("Failed to read image from: "s + filepath);
            // TODO: load placeholder image
            bFree = true;
            return;
        }

        if(iBpp == 4) {
            internalFormat = GL_RGBA8;
            dataFormat = GL_RGBA;
        }
        else if(iBpp == 3) {
            internalFormat = GL_RGB8;
            dataFormat = GL_RGB;
        }
        else {
            OCTO_LOG_ERROR("Unrecognized image format from: "s + filepath);
        }

    }

    void Image::free() {
        if(!bFree) {
            bFree = true;
            stbi_image_free(pData);
        }
    }

    Image::~Image() {
        free();
    }

    Texture2D::Texture2D(const std::string& filepath, bool bFreeImage)
        :m_image(filepath)
    {
        GLCall(glGenTextures(1, &m_uRendererID));
        GLCall(glBindTexture(GL_TEXTURE_2D, m_uRendererID));

        GLCall(glTextureParameteri(m_uRendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        GLCall(glTextureParameteri(m_uRendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

        GLCall(glTextureParameteri(m_uRendererID, GL_TEXTURE_WRAP_S, GL_REPEAT));
        GLCall(glTextureParameteri(m_uRendererID, GL_TEXTURE_WRAP_T, GL_REPEAT));

        GLCall(glTexImage2D(GL_TEXTURE_2D,
                            0,
                            m_image.internalFormat,
                            m_image.iWidth,
                            m_image.iHeight,
                            0,
                            m_image.dataFormat,
                            GL_UNSIGNED_BYTE,
                            m_image.pData));

        if(bFreeImage) {
            m_image.free();
        }
    }
}
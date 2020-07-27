#ifndef OCTOPUS_LAYOUT_H
#define OCTOPUS_LAYOUT_H

struct OCTO_API Attribute {
    std::string name;
    GLint iIndex;
    // Number of components in the attribute, e.g: 3D space point = 3 components
    GLint iComponents;
    GLboolean bNormalized;
    //Size in bytes between the
    GLsizeiptr offset;

    Attribute(const std::string _name, GLint _iComponents, GLboolean _bNormalized = false)
            : name(_name), iIndex(-1), iComponents(_iComponents), bNormalized(_bNormalized), offset(0)
    {}
};

struct OCTO_API Layout {
    Layout(std::initializer_list<Attribute> _attributes)
            : stride(0), attributes(_attributes)
    {}

    inline void enable() const {
        for(const Attribute& attribute : attributes) {
            glEnableVertexAttribArray(attribute.iIndex);
        }
    }

    inline void disable() const {
        for(const Attribute& attribute : attributes) {
            glDisableVertexAttribArray(attribute.iIndex);
        }
    }

    GLsizeiptr stride;
    std::vector<Attribute> attributes;
};


#endif //OCTOPUS_LAYOUT_H

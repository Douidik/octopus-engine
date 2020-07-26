#ifndef OCTOPUS_LAYOUT_H
#define OCTOPUS_LAYOUT_H

struct OCTO_API Attribute {
    std::string name;
    GLint index;
    // Number of components in the attribute, e.g: 3D space point = 3 components
    GLint components;
    GLboolean normalized;
    //Size in bytes between the
    GLsizeiptr offset;

    Attribute(const std::string _name, GLint _components, GLboolean _normalized = false)
            : name(_name), index(-1), components(_components), normalized(_normalized), offset(0)
    {}
};

struct OCTO_API Layout {
    Layout(std::initializer_list<Attribute> _attributes)
            : stride(0), attributes(_attributes)
    {}

    inline void enable() const {
        for(const Attribute& attribute : attributes) {
            glEnableVertexAttribArray(attribute.index);
        }
    }

    inline void disable() const {
        for(const Attribute& attribute : attributes) {
            glDisableVertexAttribArray(attribute.index);
        }
    }

    GLsizeiptr stride;
    std::vector<Attribute> attributes;
};


#endif //OCTOPUS_LAYOUT_H

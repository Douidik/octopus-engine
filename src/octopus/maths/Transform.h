#ifndef OCTO_TRANSFORM_H
#define OCTO_TRANSFORM_H

namespace Octo {

    //TODO: add vectorized transformations for debug mode

    /*
     * The transformation is describes how a body is situated in space,
     * by his position, rotation and scale.
     * We store this transformation in a 4 by 4 matrix.
     * The Transform class is just a contiguous representation of a transformation matrix
     * with utility methods
     */
    struct Transform {
        glm::mat4 matrix;

        /* Conversion to glm::mat4 */
        explicit operator glm::mat4()& { return matrix; }
        explicit operator const glm::mat4() const & { return matrix; }

        Transform()
            : matrix(1.0f)
        {}

       Transform(const glm::mat4 &_matrix)
            : matrix(_matrix)
       {}

    };

}

#endif //OCTO_TRANSFORM_H

#ifndef OCTOPUS_BUTTONCODE_H
#define OCTOPUS_BUTTONCODE_H

namespace Octo {

#define OCTO_BUTTON_COUNT 8

    enum ButtonCode {
        /* Imported from GLFW */

        Left = 0,
        Right = 1,
        Middle = 2,

        // Additional buttons
        Three = 3,
        Four = 4,
        Five = 5,
        Six = 6,
        Seven = 7
    };

#define OCTO_BUTTON_LEFT    ::Octo::ButtonCode::Left
#define OCTO_BUTTON_RIGHT   ::Octo::ButtonCode::Right
#define OCTO_BUTTON_MIDDLE  ::Octo::ButtonCode::Left

#define OCTO_BUTTON_3       ::Octo::ButtonCode::Three
#define OCTO_BUTTON_4       ::Octo::ButtonCode::Four
#define OCTO_BUTTON_5       ::Octo::ButtonCode::Five
#define OCTO_BUTTON_6       ::Octo::ButtonCode::Six
#define OCTO_BUTTON_7       ::Octo::ButtonCode::Seven


}

#endif //OCTOPUS_BUTTONCODE_H

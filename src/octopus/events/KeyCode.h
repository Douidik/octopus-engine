#ifndef OCTOPUS_KEYCODES_H
#define OCTOPUS_KEYCODES_H

#include <string>

namespace Octo {

#define OCTO_KEY_COUNT 349

    enum class KeyCode : int {
        /* Imported from GLFW */
        Space               = 32,
        Apostrophe          = 39, /* ' */
        Comma               = 44, /* , */
        Minus               = 45, /* - */
        Period              = 46, /* . */
        Slash               = 47, /* / */

        D0                  = 48, /* 0 */
        D1                  = 49, /* 1 */
        D2                  = 50, /* 2 */
        D3                  = 51, /* 3 */
        D4                  = 52, /* 4 */
        D5                  = 53, /* 5 */
        D6                  = 54, /* 6 */
        D7                  = 55, /* 7 */
        D8                  = 56, /* 8 */
        D9                  = 57, /* 9 */

        Semicolon           = 59, /* ; */
        Equal               = 61, /* = */

        A                   = 65,
        B                   = 66,
        C                   = 67,
        D                   = 68,
        E                   = 69,
        F                   = 70,
        G                   = 71,
        H                   = 72,
        I                   = 73,
        J                   = 74,
        K                   = 75,
        L                   = 76,
        M                   = 77,
        N                   = 78,
        O                   = 79,
        P                   = 80,
        Q                   = 81,
        R                   = 82,
        S                   = 83,
        T                   = 84,
        U                   = 85,
        V                   = 86,
        W                   = 87,
        X                   = 88,
        Y                   = 89,
        Z                   = 90,

        LeftBracket         = 91,  /* [ */
        Backslash           = 92,  /* \ */
        RightBracket        = 93,  /* ] */
        GraveAccent         = 96,  /* ` */

        World1              = 161, /* non-US #1 */
        World2              = 162, /* non-US #2 */

        /* Function keys */
        Escape              = 256,
        Enter               = 257,
        Tab                 = 258,
        Backspace           = 259,
        Insert              = 260,
        Delete              = 261,
        Right               = 262,
        Left                = 263,
        Down                = 264,
        Up                  = 265,
        PageUp              = 266,
        PageDown            = 267,
        Home                = 268,
        End                 = 269,
        CapsLock            = 280,
        ScrollLock          = 281,
        NumLock             = 282,
        PrintScreen         = 283,
        Pause               = 284,
        F1                  = 290,
        F2                  = 291,
        F3                  = 292,
        F4                  = 293,
        F5                  = 294,
        F6                  = 295,
        F7                  = 296,
        F8                  = 297,
        F9                  = 298,
        F10                 = 299,
        F11                 = 300,
        F12                 = 301,
        F13                 = 302,
        F14                 = 303,
        F15                 = 304,
        F16                 = 305,
        F17                 = 306,
        F18                 = 307,
        F19                 = 308,
        F20                 = 309,
        F21                 = 310,
        F22                 = 311,
        F23                 = 312,
        F24                 = 313,
        F25                 = 314,

        /* Keypad */
        KP0                 = 320,
        KP1                 = 321,
        KP2                 = 322,
        KP3                 = 323,
        KP4                 = 324,
        KP5                 = 325,
        KP6                 = 326,
        KP7                 = 327,
        KP8                 = 328,
        KP9                 = 329,
        KPDecimal           = 330,
        KPDivide            = 331,
        KPMultiply          = 332,
        KPSubtract          = 333,
        KPAdd               = 334,
        KPEnter             = 335,
        KPEqual             = 336,

        LeftShift           = 340,
        LeftControl         = 341,
        LeftAlt             = 342,
        LeftSuper           = 343,
        RightShift          = 344,
        RightControl        = 345,
        RightAlt            = 346,
        RightSuper          = 347,
        Menu                = 348
    };

#define OCTO_KEY_SPACE           ::Octo::KeyCode::Space
#define OCTO_KEY_APOSTROPHE      ::Octo::KeyCode::Apostrophe    /* ' */
#define OCTO_KEY_COMMA           ::Octo::KeyCode::Comma         /* , */
#define OCTO_KEY_MINUS           ::Octo::KeyCode::Minus         /* - */
#define OCTO_KEY_PERIOD          ::Octo::KeyCode::Period        /* . */
#define OCTO_KEY_SLASH           ::Octo::KeyCode::Slash         /* / */
#define OCTO_KEY_0               ::Octo::KeyCode::D0
#define OCTO_KEY_1               ::Octo::KeyCode::D1
#define OCTO_KEY_2               ::Octo::KeyCode::D2
#define OCTO_KEY_3               ::Octo::KeyCode::D3
#define OCTO_KEY_4               ::Octo::KeyCode::D4
#define OCTO_KEY_5               ::Octo::KeyCode::D5
#define OCTO_KEY_6               ::Octo::KeyCode::D6
#define OCTO_KEY_7               ::Octo::KeyCode::D7
#define OCTO_KEY_8               ::Octo::KeyCode::D8
#define OCTO_KEY_9               ::Octo::KeyCode::D9
#define OCTO_KEY_SEMICOLON       ::Octo::KeyCode::Semicolon     /* ; */
#define OCTO_KEY_EQUAL           ::Octo::KeyCode::Equal         /* = */
#define OCTO_KEY_A               ::Octo::KeyCode::A
#define OCTO_KEY_B               ::Octo::KeyCode::B
#define OCTO_KEY_C               ::Octo::KeyCode::C
#define OCTO_KEY_D               ::Octo::KeyCode::D
#define OCTO_KEY_E               ::Octo::KeyCode::E
#define OCTO_KEY_F               ::Octo::KeyCode::F
#define OCTO_KEY_G               ::Octo::KeyCode::G
#define OCTO_KEY_H               ::Octo::KeyCode::H
#define OCTO_KEY_I               ::Octo::KeyCode::I
#define OCTO_KEY_J               ::Octo::KeyCode::J
#define OCTO_KEY_K               ::Octo::KeyCode::K
#define OCTO_KEY_L               ::Octo::KeyCode::L
#define OCTO_KEY_M               ::Octo::KeyCode::M
#define OCTO_KEY_N               ::Octo::KeyCode::N
#define OCTO_KEY_O               ::Octo::KeyCode::O
#define OCTO_KEY_P               ::Octo::KeyCode::P
#define OCTO_KEY_Q               ::Octo::KeyCode::Q
#define OCTO_KEY_R               ::Octo::KeyCode::R
#define OCTO_KEY_S               ::Octo::KeyCode::S
#define OCTO_KEY_T               ::Octo::KeyCode::T
#define OCTO_KEY_U               ::Octo::KeyCode::U
#define OCTO_KEY_V               ::Octo::KeyCode::V
#define OCTO_KEY_W               ::Octo::KeyCode::W
#define OCTO_KEY_X               ::Octo::KeyCode::X
#define OCTO_KEY_Y               ::Octo::KeyCode::Y
#define OCTO_KEY_Z               ::Octo::KeyCode::Z
#define OCTO_KEY_LEFT_BRACKET    ::Octo::KeyCode::LeftBracket   /* [ */
#define OCTO_KEY_BACKSLASH       ::Octo::KeyCode::Backslash     /* \ */
#define OCTO_KEY_RIGHT_BRACKET   ::Octo::KeyCode::RightBracket  /* ] */
#define OCTO_KEY_GRAVE_ACCENT    ::Octo::KeyCode::GraveAccent   /* ` */
#define OCTO_KEY_WORLD_1         ::Octo::KeyCode::World1        /* non-US #1 */
#define OCTO_KEY_WORLD_2         ::Octo::KeyCode::World2        /* non-US #2 */

/* Function keys */
#define OCTO_KEY_ESCAPE          ::Octo::KeyCode::Escape
#define OCTO_KEY_ENTER           ::Octo::KeyCode::Enter
#define OCTO_KEY_TAB             ::Octo::KeyCode::Tab
#define OCTO_KEY_BACKSPACE       ::Octo::KeyCode::Backspace
#define OCTO_KEY_INSERT          ::Octo::KeyCode::Insert
#define OCTO_KEY_DELETE          ::Octo::KeyCode::Delete
#define OCTO_KEY_RIGHT           ::Octo::KeyCode::Right
#define OCTO_KEY_LEFT            ::Octo::KeyCode::Left
#define OCTO_KEY_DOWN            ::Octo::KeyCode::Down
#define OCTO_KEY_UP              ::Octo::KeyCode::Up
#define OCTO_KEY_PAGE_UP         ::Octo::KeyCode::PageUp
#define OCTO_KEY_PAGE_DOWN       ::Octo::KeyCode::PageDown
#define OCTO_KEY_HOME            ::Octo::KeyCode::Home
#define OCTO_KEY_END             ::Octo::KeyCode::End
#define OCTO_KEY_CAPS_LOCK       ::Octo::KeyCode::CapsLock
#define OCTO_KEY_SCROLL_LOCK     ::Octo::KeyCode::ScrollLock
#define OCTO_KEY_NUM_LOCK        ::Octo::KeyCode::NumLock
#define OCTO_KEY_PRINT_SCREEN    ::Octo::KeyCode::PrintScreen
#define OCTO_KEY_PAUSE           ::Octo::KeyCode::Pause
#define OCTO_KEY_F1              ::Octo::KeyCode::F1
#define OCTO_KEY_F2              ::Octo::KeyCode::F2
#define OCTO_KEY_F3              ::Octo::KeyCode::F3
#define OCTO_KEY_F4              ::Octo::KeyCode::F4
#define OCTO_KEY_F5              ::Octo::KeyCode::F5
#define OCTO_KEY_F6              ::Octo::KeyCode::F6
#define OCTO_KEY_F7              ::Octo::KeyCode::F7
#define OCTO_KEY_F8              ::Octo::KeyCode::F8
#define OCTO_KEY_F9              ::Octo::KeyCode::F9
#define OCTO_KEY_F10             ::Octo::KeyCode::F10
#define OCTO_KEY_F11             ::Octo::KeyCode::F11
#define OCTO_KEY_F12             ::Octo::KeyCode::F12
#define OCTO_KEY_F13             ::Octo::KeyCode::F13
#define OCTO_KEY_F14             ::Octo::KeyCode::F14
#define OCTO_KEY_F15             ::Octo::KeyCode::F15
#define OCTO_KEY_F16             ::Octo::KeyCode::F16
#define OCTO_KEY_F17             ::Octo::KeyCode::F17
#define OCTO_KEY_F18             ::Octo::KeyCode::F18
#define OCTO_KEY_F19             ::Octo::KeyCode::F19
#define OCTO_KEY_F20             ::Octo::KeyCode::F20
#define OCTO_KEY_F21             ::Octo::KeyCode::F21
#define OCTO_KEY_F22             ::Octo::KeyCode::F22
#define OCTO_KEY_F23             ::Octo::KeyCode::F23
#define OCTO_KEY_F24             ::Octo::KeyCode::F24
#define OCTO_KEY_F25             ::Octo::KeyCode::F25

/* Keypad */
#define OCTO_KEY_KP_0            ::Octo::KeyCode::KP0
#define OCTO_KEY_KP_1            ::Octo::KeyCode::KP1
#define OCTO_KEY_KP_2            ::Octo::KeyCode::KP2
#define OCTO_KEY_KP_3            ::Octo::KeyCode::KP3
#define OCTO_KEY_KP_4            ::Octo::KeyCode::KP4
#define OCTO_KEY_KP_5            ::Octo::KeyCode::KP5
#define OCTO_KEY_KP_6            ::Octo::KeyCode::KP6
#define OCTO_KEY_KP_7            ::Octo::KeyCode::KP7
#define OCTO_KEY_KP_8            ::Octo::KeyCode::KP8
#define OCTO_KEY_KP_9            ::Octo::KeyCode::KP9
#define OCTO_KEY_KP_DECIMAL      ::Octo::KeyCode::KPDecimal
#define OCTO_KEY_KP_DIVIDE       ::Octo::KeyCode::KPDivide
#define OCTO_KEY_KP_MULTIPLY     ::Octo::KeyCode::KPMultiply
#define OCTO_KEY_KP_SUBTRACT     ::Octo::KeyCode::KPSubtract
#define OCTO_KEY_KP_ADD          ::Octo::KeyCode::KPAdd
#define OCTO_KEY_KP_ENTER        ::Octo::KeyCode::KPEnter
#define OCTO_KEY_KP_EQUAL        ::Octo::KeyCode::KPEqual

#define OCTO_KEY_LEFT_SHIFT      ::Octo::KeyCode::LeftShift
#define OCTO_KEY_LEFT_CONTROL    ::Octo::KeyCode::LeftControl
#define OCTO_KEY_LEFT_ALT        ::Octo::KeyCode::LeftAlt
#define OCTO_KEY_LEFT_SUPER      ::Octo::KeyCode::LeftSuper
#define OCTO_KEY_RIGHT_SHIFT     ::Octo::KeyCode::RightShift
#define OCTO_KEY_RIGHT_CONTROL   ::Octo::KeyCode::RightControl
#define OCTO_KEY_RIGHT_ALT       ::Octo::KeyCode::RightAlt
#define OCTO_KEY_RIGHT_SUPER     ::Octo::KeyCode::RightSuper
#define OCTO_KEY_MENU            ::Octo::KeyCode::Menu

}

#endif //OCTOPUS_KEYCODES_H

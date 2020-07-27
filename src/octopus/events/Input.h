#ifndef OCTOPUS_INPUT_H
#define OCTOPUS_INPUT_H

#include "KeyboardEvents.h"
#include "MouseEvents.h"

namespace Octo {

    class Window;

    class OCTO_API Input {
        friend class EventQueue;
    public:
        Input(Window* pWindow);

        bool isKeyPressed(KeyCode code) const;
        bool isKeyReleased(KeyCode code) const;
        bool isKeyRepeated(KeyCode code) const;
        // Is key pressed or repeated
        bool isKeyTriggered(KeyCode code) const;

        bool isButtonPressed(ButtonCode code) const;
        bool isButtonReleased(ButtonCode code) const;

        CursorPosition getCursorPosition() const;

        std::shared_ptr<KeyInputEvent> getKey(KeyCode code) const;
        std::shared_ptr<ButtonInputEvent> getButton(ButtonCode code) const;

    private:
        std::array<std::shared_ptr<KeyInputEvent>, OCTO_KEY_COUNT> m_keys;
        std::array<std::shared_ptr<ButtonInputEvent>, OCTO_BUTTON_COUNT> m_buttons;

        Window* m_pWindow;
    };

}

#endif //OCTOPUS_INPUT_H
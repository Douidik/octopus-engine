#include "OctopusPCH.h"
#include "Input.h"
#include "Events.h"
#include "core/Window.h"

namespace Octo {

    Input::Input(Window* pWindow)
        : m_pWindow(pWindow)
    {
        /* Keys and buttons values are defaulted by the released event */
        for(int i = 0; i < OCTO_KEY_COUNT; i++) {
            m_keys[i] = std::make_shared<KeyReleasedEvent>(static_cast<KeyCode>(i));
        }

        for(int i = 0; i < OCTO_BUTTON_COUNT; i++) {
            m_buttons[i] = std::make_shared<ButtonReleasedEvent>(static_cast<ButtonCode>(i));
        }
    }

    bool Input::isKeyPressed(KeyCode code) const {
        return m_keys[static_cast<int>(code)]->type() == EventType::KeyPressed;
    }

    bool Input::isKeyReleased(KeyCode code) const {
        return m_keys[static_cast<int>(code)]->type() == EventType::KeyReleased;
    }

    bool Input::isKeyRepeated(KeyCode code) const {
        return m_keys[static_cast<int>(code)]->type() == EventType::KeyRepeated;
    }

    bool Input::isKeyTriggered(KeyCode code) const {
        return m_keys[static_cast<int>(code)]->type() == EventType::KeyRepeated ||
               m_keys[static_cast<int>(code)]->type() == EventType::KeyPressed;
    }

    bool Input::isButtonPressed(ButtonCode code) const {
        return m_buttons[static_cast<int>(code)]->type() == EventType::ButtonPressed;
    }

    bool Input::isButtonReleased(ButtonCode code) const {
        return m_buttons[static_cast<int>(code)]->type() == EventType::ButtonReleased;
    }

    std::shared_ptr<KeyInputEvent> Input::getKey(KeyCode code) const {
        return m_keys[static_cast<int>(code)];
    }

    std::shared_ptr<ButtonInputEvent> Input::getButton(ButtonCode code) const {
        return m_buttons[static_cast<int>(code)];
    }

    CursorPosition Input::getCursorPosition() const {
        CursorPosition position;
        glfwGetCursorPos(m_pWindow->native(), &position.first, &position.second);
        return position;
    }

}
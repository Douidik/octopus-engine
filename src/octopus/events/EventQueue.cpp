#include "OctopusPCH.h"
#include "EventQueue.h"
#include "core/Window.h"

#include "WindowEvents.h"
#include "FrameBufferEvents.h"
#include "KeyboardEvents.h"
#include "MouseEvents.h"

namespace Octo {

    EventQueue::EventQueue(class Window *pWindow)
        : m_input(pWindow)
    {
        pWindow->properties().pEventQueue = this;

        /* Setting up window callbacks */

        // We can't access to this event queue directly so we pass thought the window user pointer to catch it
#define GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow) WindowProperties* p_windowProperties = (WindowProperties*)glfwGetWindowUserPointer(pGLFWwindow); \
                                                 EventQueue* pEventQueue =  p_windowProperties->pEventQueue

        glfwSetWindowPosCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int x, int y) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = std::make_shared<WindowMovedEvent>(x, y);
            pEventQueue->m_queue.push(std::static_pointer_cast<Event>(event));
            p_windowProperties->x = x;
            p_windowProperties->y = y;
        });

        glfwSetWindowSizeCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int width, int height) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = std::make_shared<WindowResizedEvent>(width, height);
            pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
            p_windowProperties->width = width;
            p_windowProperties->height = height;
        });

        glfwSetWindowCloseCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = std::make_shared<WindowClosedEvent>();
            pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
        });

        glfwSetWindowFocusCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int focused) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            if(focused == GLFW_TRUE) {
                auto event = std::make_shared<WindowFocusedEvent>();
                pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
            } else {
                auto event = std::make_shared<WindowDefocusedEvent>();
                pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
            }
        });

        glfwSetFramebufferSizeCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int width, int height) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = std::make_shared<FrameBufferResizedEvent>(width, height);
            pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
        });

        glfwSetMouseButtonCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int button, int action, int modifiers) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);

            if(action == GLFW_PRESS) {
                auto event = std::make_shared<ButtonPressedEvent>(static_cast<ButtonCode>(button));
                pEventQueue->m_input.m_buttons[static_cast<int>(event->button())] = event;
            }
            else if(action == GLFW_RELEASE) {
                auto event = std::make_shared<ButtonReleasedEvent>(static_cast<ButtonCode>(button));
                pEventQueue->m_input.m_buttons[static_cast<int>(event->button())] = event;
            }
        });

        glfwSetCursorPosCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, double x, double y) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = std::make_shared<CursorMovedEvent>(x, y);
            pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
        });

        glfwSetCursorEnterCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int entered) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);

            if(entered == GLFW_TRUE) {
                auto event = std::make_shared<CursorEnteredEvent>();
                pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
            }
            else { // Mouse left
                auto event = std::make_shared<CursorLeftEvent>();
                pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
            }
        });

        glfwSetScrollCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, double x, double y) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = std::make_shared<MouseScrolledEvent>(x, y);
            pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
        });

        glfwSetKeyCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int code, int scancode, int action, int modifiers) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);

            if(action == GLFW_PRESS) {
                auto event = std::make_shared<KeyPressedEvent>(static_cast<KeyCode>(code));
                pEventQueue->m_input.m_keys[(int)event->code()] = event;
            }
            else if(action == GLFW_RELEASE) {
                auto event = std::make_shared<KeyReleasedEvent>(static_cast<KeyCode>(code));
                pEventQueue->m_input.m_keys[(int)event->code()] = event;
            }
            else if(action == GLFW_REPEAT) {
                auto event = std::make_shared<KeyRepeatedEvent>(static_cast<KeyCode>(code));
                pEventQueue->m_input.m_keys[(int)event->code()] = event;
            }
        });

#undef GET_EVENT_QUEUE_IN_CALLBACK
    }

    bool EventQueue::query(std::shared_ptr<Event> &pEvent) {
        if(!m_queue.empty()) {
            pEvent = m_queue.front();
            m_queue.pop();
            return true;
        } else {
            pEvent = nullptr;
            return false;
        }

    }

}
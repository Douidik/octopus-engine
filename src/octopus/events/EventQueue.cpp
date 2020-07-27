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
            auto event = CreateRef<WindowMovedEvent>(x, y);
            pEventQueue->m_queue.push(std::static_pointer_cast<Event>(event));
            p_windowProperties->x = x;
            p_windowProperties->y = y;
        });

        glfwSetWindowSizeCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int width, int height) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = CreateRef<WindowResizedEvent>(width, height);
            pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
            p_windowProperties->width = width;
            p_windowProperties->height = height;
        });

        glfwSetWindowCloseCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = CreateRef<WindowClosedEvent>();
            pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
        });

        glfwSetWindowFocusCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int focused) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            if(focused == GLFW_TRUE) {
                auto event = CreateRef<WindowFocusedEvent>();
                pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
            } else {
                auto event = CreateRef<WindowDefocusedEvent>();
                pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
            }
        });

        glfwSetFramebufferSizeCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int width, int height) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = CreateRef<FrameBufferResizedEvent>(width, height);
            pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
        });

        glfwSetMouseButtonCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int button, int action, int modifiers) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);

            if(action == GLFW_PRESS) {
                auto event = CreateRef<ButtonPressedEvent>(static_cast<ButtonCode>(button));
                pEventQueue->m_input.m_buttons[static_cast<int>(event->button())] = event;
            }
            else if(action == GLFW_RELEASE) {
                auto event = CreateRef<ButtonReleasedEvent>(static_cast<ButtonCode>(button));
                pEventQueue->m_input.m_buttons[static_cast<int>(event->button())] = event;
            }
        });

        glfwSetCursorPosCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, double x, double y) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = CreateRef<CursorMovedEvent>(x, y);
            pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
        });

        glfwSetCursorEnterCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int entered) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);

            if(entered == GLFW_TRUE) {
                auto event = CreateRef<CursorEnteredEvent>();
                pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
            }
            else { // Mouse left
                auto event = CreateRef<CursorLeftEvent>();
                pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
            }
        });

        glfwSetScrollCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, double x, double y) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);
            auto event = CreateRef<MouseScrolledEvent>(x, y);
            pEventQueue->m_queue.push(std::dynamic_pointer_cast<Event>(event));
        });

        glfwSetKeyCallback(pWindow->native(), [](GLFWwindow* pGLFWwindow, int code, int scancode, int action, int modifiers) {
            GET_EVENT_QUEUE_IN_CALLBACK(pGLFWwindow);

            if(action == GLFW_PRESS) {
                auto event = CreateRef<KeyPressedEvent>(static_cast<KeyCode>(code));
                pEventQueue->m_input.m_keys[(int)event->code()] = event;
            }
            else if(action == GLFW_RELEASE) {
                auto event = CreateRef<KeyReleasedEvent>(static_cast<KeyCode>(code));
                pEventQueue->m_input.m_keys[(int)event->code()] = event;
            }
            else if(action == GLFW_REPEAT) {
                auto event = CreateRef<KeyRepeatedEvent>(static_cast<KeyCode>(code));
                pEventQueue->m_input.m_keys[(int)event->code()] = event;
            }
        });

#undef GET_EVENT_QUEUE_IN_CALLBACK
    }

    bool EventQueue::query(Ref<Event> &event) {
        if(!m_queue.empty()) {
            event = m_queue.front();
            m_queue.pop();
            return true;
        } else {
            event = nullptr;
            return false;
        }

    }

}
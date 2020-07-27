#ifndef OCTOPUS_FRAMEBUFFEREVENTS_H
#define OCTOPUS_FRAMEBUFFEREVENTS_H

#include "Events.h"

namespace Octo {

        class OCTO_API FrameBufferResizedEvent : public Event {
        public:
            FrameBufferResizedEvent(int width, int height)
                    : Event(EventType::FrameBufferResized), m_width(width), m_height(height) {}

            std::string info() const override;

            inline int width() const { return m_width; }

            inline int height() const { return m_height; }

        private:
            int m_width, m_height;

        };

    }


#endif //OCTOPUS_FRAMEBUFFEREVENTS_H

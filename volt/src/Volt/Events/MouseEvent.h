#pragma once

#include "Event.h"
#include <Volt/Core/MouseCodes.h>

namespace Volt
{

    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(const float x, const float y)
            : mouseX_(x), mouseY_(y) {}

        float GetX() const { return mouseX_; }
        float GetY() const { return mouseY_; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << mouseX_ << ", " << mouseY_;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float mouseX_, mouseY_;
    };

    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(const float xOffset, const float yOffset)
            : offsetX_(xOffset), offsetY_(yOffset) {}

        float GetXOffset() const { return offsetX_; }
        float GetYOffset() const { return offsetY_; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float offsetX_, offsetY_;
    };

    class MouseButtonEvent : public Event
    {
    public:
        MouseCode GetMouseButton() const { return button_; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
    protected:
        MouseButtonEvent(const MouseCode button)
            : button_(button) {}

        MouseCode button_;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(const MouseCode button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << button_;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(const MouseCode button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << button_;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

}
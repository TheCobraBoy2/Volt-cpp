#pragma once

#include "Event.h"
#include <Volt/Core/KeyCodes.h>
#include <Volt/Core/Base.h>

namespace Volt
{
    class KeyEvent : public Event
    {
    public:
        KeyCode GetKeyCode() const { return keyCode_; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(const KeyCode keycode) : keyCode_(keycode) {}
        KeyCode keyCode_;
    };

    class VOLT_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(const KeyCode keycode, bool isRepeat = false)
            : KeyEvent(keycode), m_IsRepeat(isRepeat) {}

        bool IsRepeat() const { return m_IsRepeat; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << keyCode_ << " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        bool m_IsRepeat;
    };

    class VOLT_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(const KeyCode keycode)
            : KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << keyCode_;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class VOLT_API KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(const KeyCode keycode)
            : KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << keyCode_;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };
}
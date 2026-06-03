#pragma once

#include "Base.h"
#include <Volt/Util/Types.h>

namespace Volt
{
    class VOLT_API Input
    {
    public:
        inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

        inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
        inline static Volt::Vector2f GetMousePosition() { return Volt::Vector2f(s_Instance->GetMouseXImpl(), s_Instance->GetMouseYImpl()); }
        inline static float GetMouseX()
        {
            return s_Instance->GetMouseXImpl();
        }
        inline static float GetMouseY()
        {
            return s_Instance->GetMouseYImpl();
        }

    protected:
        virtual bool
        IsKeyPressedImpl(int keycode) = 0;
        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;

    private:
        static Input *s_Instance;
    };
}
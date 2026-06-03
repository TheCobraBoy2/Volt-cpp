#pragma once

#include <Volt/Core/Layer.h>
#include <Volt/Core/Base.h>
#include <Volt/Events/ApplicationEvent.h>
#include <Volt/Events/KeyEvent.h>
#include <Volt/Events/MouseEvent.h>

namespace Volt
{
    class VOLT_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event &event);

        void BlockEvents(bool block) { blockEvents_ = block; }

    private:
        float time_ = 0.0F;
        bool blockEvents_ = true;
    };
}
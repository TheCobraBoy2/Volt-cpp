#pragma once

#include <Volt/Core/Layer.h>
#include <Volt/Core/Base.h>
#include <Volt/Events/ApplicationEvent.h>
#include <Volt/Events/KeyEvent.h>
#include <Volt/Events/MouseEvent.h>

namespace Volt
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnEvent(Event &event) override;

        void Begin();
        void End();

        void SetDarkThemeColors();

        void BlockEvents(bool block) { blockEvents_ = block; }

    private:
        float time_ = 0.0F;
        bool blockEvents_ = true;
    };
}
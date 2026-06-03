#pragma once

#include "Volt/Window.h"
#include <GLFW/glfw3.h>

namespace Volt
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProps &props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return data_.Width; }
        inline unsigned int GetHeight() const override { return data_.Height; }
        inline void *GetNativeWindow() const override { return window_; }

        inline void SetEventCallback(const EventCallbackFn &callback) override { data_.EventCallback = callback; }
        void SetVSync(bool enabled);
        bool IsVSync() const;

    private:
        virtual void Init(const WindowProps &props);
        virtual void Shutdown();

    private:
        GLFWwindow *window_;
        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData data_;
    };
}
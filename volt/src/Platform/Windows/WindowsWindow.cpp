#include "vtpch.h"
#include "WindowsWindow.h"
#include <Volt/Core/Log.h>
#include <Volt/Core/Exit.h>
#include <Volt/Core/ExitCodes.h>
#include <Volt/Events/ApplicationEvent.h>
#include <Volt/Events/KeyEvent.h>
#include <Volt/Events/MouseEvent.h>

#include <glad/glad.h>

namespace Volt
{
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char *description)
    {
        VT_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window *Window::Create(const WindowProps &props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps &props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
    }

    void WindowsWindow::Init(const WindowProps &props)
    {
        data_.Title = props.Title;
        data_.Width = props.Width;
        data_.Height = props.Height;

        VT_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            if (success != GLFW_TRUE)
            {
                glfwTerminate();
                Volt::Backend::close(VOLT::FAILURE_TO_INITIALIZE, "GLFW Failed to Initialize");
            }

            glfwSetErrorCallback(GLFWErrorCallback);

            s_GLFWInitialized = true;
        }

        window_ = glfwCreateWindow((int)props.Width, (int)props.Height, data_.Title.c_str(), nullptr, nullptr);
        if (!window_)
        {
            glfwDestroyWindow(window_);
            glfwTerminate();
            Volt::Backend::close(VOLT::FAILURE_TO_CREATE_WINDOW, "Failed to create Window");
        }
        glfwMakeContextCurrent(window_);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            glfwDestroyWindow(window_);
            Volt::Backend::close(VOLT::FAILURE_TO_INITIALIZE, "GLAD Failed to Initialize");
        }
        glfwSetWindowUserPointer(window_, &data_);
        SetVSync(true);

        glfwSetWindowSizeCallback(window_, [](GLFWwindow *window, int width, int height)
                                  {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            data.Width = width;
            data.Height = height;

            WindowResizeEvent e(width, height);
            data.EventCallback(e); });

        glfwSetWindowCloseCallback(window_, [](GLFWwindow *window)
                                   {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            WindowCloseEvent e;
            data.EventCallback(e); });

        glfwSetKeyCallback(window_, [](GLFWwindow *window, int key, int scancode, int action, int mods)
                           {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            } });

        glfwSetMouseButtonCallback(window_, [](GLFWwindow *window, int button, int action, int mods)
                                   {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action){
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            } });

        glfwSetScrollCallback(window_, [](GLFWwindow *window, double xOffset, double yOffset)
                              { 
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event); });

        glfwSetCursorPosCallback(window_, [](GLFWwindow *window, double xPos, double yPos)
                                 {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)xPos, (float)yPos);
            data.EventCallback(event); });
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(window_);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(window_);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        data_.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return data_.VSync;
    }
}
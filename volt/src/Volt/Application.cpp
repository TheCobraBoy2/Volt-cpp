#include "Application.h"
#include <iostream>
#include <vtpch.h>
#include "Core/Log.h"
#include "Events/ApplicationEvent.h"
#include <glad/glad.h>

#include "Core/Input.h"
#include "Core/MouseCodes.h"
#include "Core/KeyCodes.h"

namespace Volt
{
	Application *Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;

		window_ = std::unique_ptr<Window>(Window::Create());
		window_->SetEventCallback(VT_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer *layer)
	{
		layerStack_.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer *overlay)
	{
		layerStack_.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event &e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(VT_BIND_EVENT_FN(OnWindowClose));

		for (auto it = layerStack_.end(); it != layerStack_.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run()
	{

		while (running_)
		{
			glClearColor(0.2, 0.2, 0.2, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer *layer : layerStack_)
				layer->OnUpdate();

			window_->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent &e)
	{
		running_ = false;
		return true;
	}
}
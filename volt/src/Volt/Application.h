#pragma once

#include "Core/Base.h"
#include "Core/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Volt
{
	class VOLT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event &e);

		void PushLayer(Layer *layer);
		void PushOverlay(Layer *layer);

		inline static Application &Get() { return *s_Instance; }
		inline Window &GetWindow() { return *window_; }

	private:
		bool OnWindowClose(WindowCloseEvent &e);

		std::unique_ptr<Window> window_;
		bool running_ = true;
		LayerStack layerStack_;

	private:
		static Application *s_Instance;
	};

	// To be defined in client
	Application *CreateApplication();
}
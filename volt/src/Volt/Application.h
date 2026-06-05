#pragma once

#include "Core/Base.h"
#include "Core/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "ImGui/ImGuiLayer.h"
#include "Util/Types.h"

namespace Volt
{
	struct ApplicationSpecification
	{
		std::string Name = "Volt Application";
		Vector2u_i WindowSize = {1280, 720};
		bool DockingEnabled = true;
		bool ViewportsEnabled = true;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification &spec = ApplicationSpecification());
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
		ImGuiLayer *imguiLayer_;
		bool running_ = true;
		LayerStack layerStack_;

	private:
		static Application *s_Instance;
		ApplicationSpecification spec_;
	};

	// To be defined in client
	Application *CreateApplication();
}
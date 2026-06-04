#define VOLT_GIVEMEITALL

#include <Volt.h>
#include <imgui.h>

class ExampleLayer : public Volt::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
	}

	void OnEvent(Volt::Event &event) override
	{
	}

	void OnImGuiRender() override
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}
};

class Installer : public Volt::Application
{
public:
	Installer()
	{
		PushLayer(new ExampleLayer());
		// PushOverlay(new Volt::ImGuiLayer());
	}

	~Installer()
	{
	}
};

Volt::Application *Volt::CreateApplication()
{
	return new Installer();
}
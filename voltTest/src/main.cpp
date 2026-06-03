#include <Volt.h>

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
};

class Installer : public Volt::Application
{
public:
	Installer()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Volt::ImGuiLayer());
	}

	~Installer()
	{
	}
};

Volt::Application *Volt::CreateApplication()
{
	return new Installer();
}
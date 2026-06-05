#define VOLT_GIVEMEITALL

#include <Volt.h>
#include <imgui.h>
class ExampleLayer : public Volt::Layer
{
private:
	bool show = true;

public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
	}

	void OnEvent(Volt::Event &event) override
	{
		Volt::EventDispatcher dispatcher(event);
		dispatcher.Dispatch<Volt::KeyPressedEvent>([this](Volt::KeyPressedEvent &e)
												   {
			if (e.GetKeyCode() == Volt::Key::F2) {
				VT_TRACE("Toggling ImGui Demo Window");
				show = !show;
				return true;
			} 
			return false; });
	}

	void OnImGuiRender() override
	{
		if (show)
			ImGui::ShowDemoWindow(&show);
	}
};

class Installer : public Volt::Application
{
public:
	Installer(const Volt::ApplicationSpecification &specification)
		: Volt::Application(specification)
	{
		PushLayer(new ExampleLayer());
	}

	~Installer()
	{
	}
};

Volt::Application *Volt::CreateApplication()
{
	Volt::ApplicationSpecification spec;
	spec.Name = "My Volt App";

	return new Installer(spec);
}
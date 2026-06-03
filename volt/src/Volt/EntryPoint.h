#pragma once
#include <Volt/Core/Log.h>
#include <Volt/Core/Exit.h>
#include <Volt/Core/ExitCodes.h>

#ifdef VOLT_PLATFORM_WINDOWS
extern Volt::Application *Volt::CreateApplication();
int main(int argc, char **argv)
{
	Volt::Backend::INT::Log::Init();

	auto app = Volt::CreateApplication();
	app->Run();
	delete app;
	Volt::Backend::closeSuccess;
}
#endif
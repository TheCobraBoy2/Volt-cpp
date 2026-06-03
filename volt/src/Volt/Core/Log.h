#pragma once

#include <Volt/Core/Base.h>
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)
#include <spdlog/sinks/stdout_color_sinks.h>
#include <vtpch.h>

namespace Volt::Backend::INT
{
    class VOLT_API Log
    {
    public:
        static void Init();

        static Volt::Ref<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        static Volt::Ref<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static Volt::Ref<spdlog::logger> s_CoreLogger;
        static Volt::Ref<spdlog::logger> s_ClientLogger;
    };
}

#define VT_CORE_TRACE(...) ::Volt::Backend::INT::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VT_CORE_INFO(...) ::Volt::Backend::INT::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VT_CORE_WARN(...) ::Volt::Backend::INT::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VT_CORE_ERROR(...) ::Volt::Backend::INT::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VT_CORE_CRITICAL(...) ::Volt::Backend::INT::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define VT_CORE_FLUSH() ::Volt::Backend::INT::Log::GetCoreLogger()->flush()

#define VT_TRACE(...) ::Volt::Backend::INT::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VT_INFO(...) ::Volt::Backend::INT::Log::GetClientLogger()->info(__VA_ARGS__)
#define VT_WARN(...) ::Volt::Backend::INT::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VT_ERROR(...) ::Volt::Backend::INT::Log::GetClientLogger()->error(__VA_ARGS__)
#define VT_CRITICAL(...) ::Volt::Backend::INT::Log::GetClientLogger()->critical(__VA_ARGS__)
#define VT_FLUSH() ::Volt::Backend::INT::Log::GetClientLogger()->flush()
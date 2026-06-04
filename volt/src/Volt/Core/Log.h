#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include "Base.h"
#include <Volt/Events/Event.h>

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#pragma warning(pop)

#include <glm/gtx/string_cast.hpp>

namespace Volt::Backend::INT
{
    class Log
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

template <>
struct fmt::formatter<Volt::Event>
{
    constexpr auto parse(format_parse_context &ctx)
    {
        return ctx.end();
    }

    template <typename FormatContext>
    auto format(const Volt::Event &e, FormatContext &ctx) const
    {
        return fmt::format_to(ctx.out(), "{}", e.ToString());
    }
};

template <glm::length_t L, typename T, glm::qualifier Q>
struct fmt::formatter<glm::vec<L, T, Q>>
{
    constexpr auto parse(format_parse_context &ctx)
    {
        return ctx.end();
    }

    template <typename FormatContext>
    auto format(const glm::vec<L, T, Q> &v, FormatContext &ctx) const
    {
        return fmt::format_to(ctx.out(), "{}", glm::to_string(v));
    }
};

template <glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
struct fmt::formatter<glm::mat<C, R, T, Q>>
{
    constexpr auto parse(format_parse_context &ctx)
    {
        return ctx.end();
    }

    template <typename FormatContext>
    auto format(const glm::mat<C, R, T, Q> &m, FormatContext &ctx) const
    {
        return fmt::format_to(ctx.out(), "{}", glm::to_string(m));
    }
};

template <typename T, glm::qualifier Q>
struct fmt::formatter<glm::qua<T, Q>>
{
    constexpr auto parse(format_parse_context &ctx)
    {
        return ctx.end();
    }

    template <typename FormatContext>
    auto format(const glm::qua<T, Q> &q, FormatContext &ctx) const
    {
        return fmt::format_to(ctx.out(), "{}", glm::to_string(q));
    }
};

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
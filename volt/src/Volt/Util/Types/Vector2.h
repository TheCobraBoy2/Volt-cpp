#pragma once

#include <type_traits>
#include <utility>

#include <Volt/Core/Base.h>

namespace Volt
{
    template <typename T>
    class Vector2
    {
    public:
        using ValueType = T;

        T x{};
        T y{};

        constexpr Vector2() = default;
        constexpr Vector2(T x, T y) : x(x), y(y) {}

        template <typename U,
                  typename = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr Vector2(const Vector2<U> &other)
            : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)) {}

        constexpr std::pair<T, T> ToPair() const
        {
            return {x, y};
        }

        constexpr static Vector2 FromPair(const std::pair<T, T> &p)
        {
            return {p.first, p.second};
        }

        constexpr Vector2 operator+(const Vector2 &rhs) const
        {
            return {x + rhs.x, y + rhs.y};
        }

        constexpr Vector2 operator-(const Vector2 &rhs) const
        {
            return {x - rhs.x, y - rhs.y};
        }

        constexpr Vector2 operator*(T scalar) const
        {
            return {x * scalar, y * scalar};
        }

        constexpr Vector2 operator/(T scalar) const
        {
            return {x / scalar, y / scalar};
        }

        Vector2 &operator+=(const Vector2 &rhs)
        {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        Vector2 &operator-=(const Vector2 &rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        Vector2 &operator*=(T scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        Vector2 &operator/=(T scalar)
        {
            x /= scalar;
            y /= scalar;
            return *this;
        }

        constexpr bool operator==(const Vector2 &rhs) const
        {
            return x == rhs.x && y == rhs.y;
        }

        constexpr bool operator!=(const Vector2 &rhs) const
        {
            return !(*this == rhs);
        }
    };

    using Vector2f = Vector2<float>;
    using Vector2i = Vector2<int>;
    using Vector2d = Vector2<double>;
    using Vector2u_i = Vector2<unsigned int>;
}
#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <expected>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>
#include <vector>

#define fn auto
#define let auto

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = ptrdiff_t;

using f32 = float;
using f64 = double;

using sv = const std::string_view&;
using str = std::string_view;
using String = std::string;

template<typename T>
using Vec = std::vector<T>;

template<typename T>
using Option = std::optional<T>;

template<typename T>
using Box = std::unique_ptr<T>;

template<typename T>
using Rc = std::shared_ptr<T>;

template<typename T, std::size_t N>
using Arr = std::array<T, N>;

template<typename T, typename E>
using Result = std::expected<T, E>;

inline constexpr std::nullopt_t None = std::nullopt;

template<typename T>
[[nodiscard]] constexpr auto Some(T&& v) noexcept(std::is_nothrow_constructible_v<Option<std::decay_t<T>>, T>)
    -> Option<std::decay_t<T>> {
    return Option<std::decay_t<T>>{std::forward<T>(v)};
}

template<typename T>
struct Ok {
    T v;
    explicit constexpr Ok(T x) noexcept(std::is_nothrow_move_constructible_v<T>) : v(std::move(x)) {}

    template<typename E>
    [[nodiscard]] constexpr operator std::expected<T, E>() const& {
        return v;
    }

    template<typename E>
    [[nodiscard]] constexpr operator std::expected<T, E>() && {
        return std::move(v);
    }
};

template<typename T>
Ok(T) -> Ok<T>;

template<typename E>
struct Err {
    E e;
    explicit constexpr Err(E x) noexcept(std::is_nothrow_move_constructible_v<E>) : e(std::move(x)) {}

    template<typename T>
    [[nodiscard]] constexpr operator std::expected<T, E>() const& {
        return std::unexpected(e);
    }

    template<typename T>
    [[nodiscard]] constexpr operator std::expected<T, E>() && {
        return std::unexpected(std::move(e));
    }
};

template<typename E>
Err(E) -> Err<E>;

template<typename T>
[[nodiscard]] auto Box_new(T&& v) -> Box<std::decay_t<T>> {
    return std::make_unique<std::decay_t<T>>(std::forward<T>(v));
}

template<typename T, typename... Args>
[[nodiscard]] auto Box_new(Args&&... args) -> Box<T> {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
[[nodiscard]] auto Rc_new(T&& v) -> Rc<std::decay_t<T>> {
    return std::make_shared<std::decay_t<T>>(std::forward<T>(v));
}

template<typename T, typename... Args>
[[nodiscard]] auto Rc_new(Args&&... args) -> Rc<T> {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

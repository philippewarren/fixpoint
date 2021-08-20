#pragma once

#include <limits.h>
#include <stdint.h>

namespace
{
    template <typename T>
    constexpr size_t bitsizeof()
    {
        return sizeof(T) * CHAR_BIT;
    };
}

class Fix
{
public:
    Fix() noexcept = default;
    constexpr Fix(float value) noexcept : val(value * MULTIPLY_VALUE) {}
    constexpr Fix(double value) noexcept : val(value * MULTIPLY_VALUE) {}
    constexpr Fix(long double value) noexcept : val(value * MULTIPLY_VALUE) {}
    constexpr Fix(int8_t value) noexcept : val(value << BITSHIFT_VALUE) {}
    constexpr Fix(uint8_t value) noexcept : val(value << BITSHIFT_VALUE) {}
    constexpr Fix(int16_t value) noexcept : val(value << BITSHIFT_VALUE) {}
    constexpr Fix(uint16_t value) noexcept : val(value << BITSHIFT_VALUE) {}
    constexpr Fix(int32_t value) noexcept : val(value << BITSHIFT_VALUE) {}
    constexpr Fix(uint32_t value) noexcept : val(value << BITSHIFT_VALUE) {}
    constexpr Fix(int64_t value) noexcept : val(value << BITSHIFT_VALUE) {}
    constexpr Fix(uint64_t value) noexcept : val(value << BITSHIFT_VALUE) {}

    constexpr Fix(const Fix& other) noexcept = default;
    constexpr Fix(Fix&& other) noexcept = default;
    constexpr Fix& operator=(const Fix& rhs) noexcept = default;
    constexpr Fix& operator=(Fix&& rhs) noexcept = default;

    constexpr Fix operator+(const Fix& rhs) const noexcept
    {
        return Fix::withValue(this->val + rhs.val);
    }
    constexpr Fix& operator+=(const Fix& rhs) noexcept
    {
        this->val += rhs.val;
        return *this;
    }

    constexpr Fix operator-(const Fix& rhs) const noexcept
    {
        return Fix::withValue(this->val - rhs.val);
    }
    constexpr Fix& operator-=(const Fix& rhs) noexcept
    {
        this->val -= rhs.val;
        return *this;
    }

    constexpr Fix operator*(const Fix& rhs) const noexcept
    {
        return Fix::withValue((this->val * rhs.val) >> BITSHIFT_VALUE);
    }
    constexpr Fix& operator*=(const Fix& rhs) noexcept
    {
        this->val = (this->val * rhs.val) >> BITSHIFT_VALUE;
        return *this;
    }

    constexpr Fix operator/(const Fix& rhs) const noexcept
    {
        return Fix::withValue(((this->val << BITSHIFT_VALUE) / rhs.val));
    }
    constexpr Fix& operator/=(const Fix& rhs) noexcept
    {
        this->val = ((this->val << BITSHIFT_VALUE) / rhs.val);
        return *this;
    }

    constexpr explicit operator float() noexcept
    {
        return static_cast<float>(val) / MULTIPLY_VALUE;
    }
    constexpr explicit operator double() noexcept
    {
        return static_cast<double>(val) / MULTIPLY_VALUE;
    }
    constexpr explicit operator long double() noexcept
    {
        return static_cast<long double>(val) / MULTIPLY_VALUE;
    }
    constexpr explicit operator int8_t() noexcept { return val >> BITSHIFT_VALUE; }
    constexpr explicit operator uint8_t() noexcept { return val >> BITSHIFT_VALUE; }
    constexpr explicit operator int16_t() noexcept { return val >> BITSHIFT_VALUE; }
    constexpr explicit operator uint16_t() noexcept { return val >> BITSHIFT_VALUE; }
    constexpr explicit operator int32_t() noexcept { return val >> BITSHIFT_VALUE; }
    constexpr explicit operator uint32_t() noexcept { return val >> BITSHIFT_VALUE; }
    constexpr explicit operator int64_t() noexcept { return val >> BITSHIFT_VALUE; }
    constexpr explicit operator uint64_t() noexcept { return val >> BITSHIFT_VALUE; }

private:
    int64_t val;

    constexpr static uint64_t MULTIPLY_VALUE = UINT16_MAX;
    constexpr static uint64_t BITSHIFT_VALUE = bitsizeof<uint16_t>();

    constexpr static Fix withValue(int64_t value) noexcept
    {
        Fix fix(0);
        fix.val = value;
        return fix;
    }
};

constexpr Fix operator""_fx(long double value) noexcept
{
    return Fix(value);
}

constexpr Fix operator""_fx(uint64_t value) noexcept
{
    return Fix(value);
}

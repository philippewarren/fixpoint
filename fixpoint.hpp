#pragma once

#include <stdint.h>

class Fix
{
public:
    Fix() noexcept = default;
    constexpr Fix(float value) noexcept : val(MULTIPLY_VALUE * value) {}
    constexpr Fix(double value) noexcept : val(MULTIPLY_VALUE * value) {}
    constexpr Fix(long double value) noexcept : val(MULTIPLY_VALUE * value) {}
    constexpr Fix(int8_t value) noexcept : val(MULTIPLY_VALUE * value) {}
    constexpr Fix(uint8_t value) noexcept : val(MULTIPLY_VALUE * value) {}
    constexpr Fix(int16_t value) noexcept : val(MULTIPLY_VALUE * value) {}
    constexpr Fix(uint16_t value) noexcept : val(MULTIPLY_VALUE * value) {}
    constexpr Fix(int32_t value) noexcept : val(MULTIPLY_VALUE * value) {}
    constexpr Fix(uint32_t value) noexcept : val(MULTIPLY_VALUE * value) {}
    constexpr Fix(int64_t value) noexcept : val(MULTIPLY_VALUE * value) {}
    constexpr Fix(uint64_t value) noexcept : val(MULTIPLY_VALUE * value) {}

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
        return Fix::withValue((this->val * rhs.val) >> (sizeof(uint16_t) * 8));
    }
    constexpr Fix& operator*=(const Fix& rhs) noexcept
    {
        this->val = (this->val * rhs.val) >> (sizeof(uint16_t) * 8);
        return *this;
    }

    constexpr Fix operator/(const Fix& rhs) const noexcept
    {
        return Fix::withValue(((this->val << (sizeof(uint16_t) * 8)) / rhs.val));
    }
    constexpr Fix& operator/=(const Fix& rhs) noexcept
    {
        this->val = ((this->val << (sizeof(uint16_t) * 8)) / rhs.val);
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
    constexpr explicit operator int8_t() noexcept { return val / MULTIPLY_VALUE; }
    constexpr explicit operator uint8_t() noexcept { return val / MULTIPLY_VALUE; }
    constexpr explicit operator int16_t() noexcept { return val / MULTIPLY_VALUE; }
    constexpr explicit operator uint16_t() noexcept { return val / MULTIPLY_VALUE; }
    constexpr explicit operator int32_t() noexcept { return val / MULTIPLY_VALUE; }
    constexpr explicit operator uint32_t() noexcept { return val / MULTIPLY_VALUE; }
    constexpr explicit operator int64_t() noexcept { return val / MULTIPLY_VALUE; }
    constexpr explicit operator uint64_t() noexcept { return val / MULTIPLY_VALUE; }

private:
    int64_t val;

    constexpr static uint64_t MULTIPLY_VALUE = UINT16_MAX;

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

#ifndef UTILITY_H
#define UTILITY_H

#include <stdint.h>

constexpr uint32_t val_32_const = 0x811c9dc5;
constexpr uint32_t prime_32_const = 0x1000193;
constexpr uint64_t prime_64_const = 0x100000001b3;

// compile time hash value calculation
inline constexpr uint32_t hash_function(const char* const str, const uint32_t value = val_32_const) noexcept {
    return (str[0] == '\0') ? value : hash_function(&str[1], (value ^ uint32_t(str[0])) * prime_32_const);
}


#endif // UTILITY_H

// 8.3 Division Method for Large Keys
#ifndef HASH_FUNCTION_HPP
#define HASH_FUNCTION_HPP

#include <string>
#include <cstdint>

uint32_t hash(const std::string& str, const uint32_t m)
{
    uint32_t hash = 0;
    uint32_t hash_term;
    uint32_t factor = 1;  // 256^0

    for (int i = 0; i < str.size(); ++i) {
        uint32_t c = static_cast<uint32_t>(str[i]);
        hash_term = (c % m * factor % m) % m;
        hash = (hash_term % m + hash % m) % m;
        // 256^i % m = (256^(i-1) % m * 256 % m) % m, recursively
        // then using mod property this reduces to (factor * 256) % m
        factor = (factor * 256) % m;
    }

    return hash;
}

#endif /* HASH_FUNCTION_HPP */
#pragma once

#include <VelyraUtils/Types/Types.hpp>
#include <random>

namespace Velyra::Utils {

    class Random {
    public:
        static void setSeed(U64 seed);

        static U64 getSeed();

        template<typename TYPE>
        static TYPE get_random(const TYPE min = std::numeric_limits<TYPE>::min(), const TYPE max = std::numeric_limits<TYPE>::max()) {
            static_assert(std::is_floating_point_v<TYPE> || std::is_integral_v<TYPE> || std::is_same_v<TYPE, bool>, "Unsupported type for random number generation.");

            if constexpr (std::is_same_v<TYPE, bool>) {
                std::bernoulli_distribution dis(0.5); // 50% chance for true
                return dis(m_Generator);                    // Returns true or false with equal probability
            } else if constexpr (std::is_floating_point_v<TYPE>) {
                std::uniform_real_distribution<TYPE> dis(min, max);
                return dis(m_Generator);
            } else if constexpr (std::is_integral_v<TYPE>) {
                std::uniform_int_distribution<TYPE> dis(min, max);
                return dis(m_Generator);
            }
        }

    private:
        static U64 m_Seed;
        static std::mt19937_64 m_Generator;
    };

}
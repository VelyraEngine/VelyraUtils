#include <VelyraUtils/Random.hpp>

namespace Velyra::Utils {

    U64 Random::m_Seed = 0;
    std::mt19937_64 Random::m_Generator(m_Seed);

    void Random::setSeed(const U64 seed) {
        m_Seed = seed;
        m_Generator.seed(m_Seed);
    }

    U64 Random::getSeed() {
        return m_Seed;
    }

}

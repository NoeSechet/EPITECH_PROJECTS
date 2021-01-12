/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** RNGenerator
*/

#ifndef RNGENERATOR_HPP_
#define RNGENERATOR_HPP_

#include <random>
#include <ctime>

class RNGenerator {
    private:
        uint32_t _seedValue = 0;
        std::mt19937 _RNGen;
    public:
        RNGenerator() {
            _seedValue = (unsigned)time(nullptr);
            srand(_seedValue);
            _RNGen.seed(_seedValue);
        }
        ~RNGenerator() = default;

        std::mt19937& getRNGine() { return _RNGen; }
        uint32_t getIntRange(int min, int max)
        {
            if (min < 0)
                return -1;
            std::uniform_int_distribution<uint32_t> rand_range(min, max);
            uint32_t res = rand_range(_RNGen);
            return res;
        }
};

#endif /* !RNGENERATOR_HPP_ */

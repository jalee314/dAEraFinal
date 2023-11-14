#include <random>

int rng() {
        std::mt19937 gen(std::random_device rd());
        std::uniform_int_distribution<int> distribution(1, 100);
        return distribution(gen);    
    }
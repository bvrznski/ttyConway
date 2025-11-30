#include "patterns.h"
#include <vector>

// Get pattern definitions
std::vector<std::vector<bool>> Patterns::getGliderPattern() {
    return {
        {false, true, false},
        {false, false, true},
        {true, true, true}
    };
}

std::vector<std::vector<bool>> Patterns::getSpaceshipPattern() {
    return {
        {false, true, false, false, true},
        {true, false, false, false, false},
        {true, false, false, false, false},
        {false, true, true, true, true}
    };
}

std::vector<std::vector<bool>> Patterns::getRakePattern() {
    return {
        {false, false, true, false, false, false, false, false, false, false, false},
        {false, false, false, true, false, false, false, false, false, false, false},
        {true, true, false, false, true, true, false, false, false, false, false},
        {true, true, false, false, true, true, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false},
        {false, false, true, false, false, false, false, false, false, false, false},
        {false, false, false, true, false, false, false, false, false, false, false}
    };
}

std::vector<std::vector<bool>> Patterns::getReflectorPattern() {
    return {
        {false, false, false, false, false, false, false, false},
        {false, true, true, false, false, true, true, false},
        {false, true, true, false, false, true, true, false},
        {false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false}
    };
}

std::vector<std::vector<bool>> Patterns::getReplicatorPattern() {
    return {
        {false, true, false, true, false},
        {true, false, false, false, true},
        {false, false, false, false, false},
        {true, false, false, false, true},
        {false, true, false, true, false}
    };
}

std::vector<std::vector<bool>> Patterns::getBreederPattern() {
    return {
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}
    };
}

std::vector<std::vector<bool>> Patterns::getTrainPattern() {
    return {
        {false, false, false, false, false, false, false, false},
        {false, true, true, true, false, false, false, false},
        {false, false, false, false, true, true, true, false},
        {false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false}
    };
}

std::vector<std::vector<bool>> Patterns::getGunPattern() {
    return {
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, true, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, true, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}
    };
}

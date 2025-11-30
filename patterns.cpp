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
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false},
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

std::vector<std::vector<bool>> Patterns::getPulsarPattern() {
    // Pulsar pattern (17x17), period 3
    return {
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, true, true, true, false, false, true, true, true, false, false, false, false, false},
        {false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false},
        {false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false},
        {false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false},
        {false, false, false, false, true, true, true, false, false, true, true, true, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}
    };
}

std::vector<std::vector<bool>> Patterns::getClockPattern() {
    // Simple clock pattern (period 4)
    return {
        {false, false, false, false, false},
        {false, true, false, true, false},
        {false, false, false, false, false},
        {false, true, false, true, false},
        {false, false, false, false, false}
    };
}

std::vector<std::vector<bool>> Patterns::getBeaconPattern() {
    // Beacon pattern (period 2)
    return {
        {false, false, false, false, false, false},
        {false, true, true, false, false, false},
        {false, true, true, false, false, false},
        {false, false, false, true, true, false},
        {false, false, false, true, true, false},
        {false, false, false, false, false, false}
    };
}

std::vector<std::vector<bool>> Patterns::getToadPattern() {
    // Toad pattern (period 2)
    return {
        {false, false, false, false},
        {false, false, true, true},
        {false, true, true, false},
        {false, false, false, false}
    };
}

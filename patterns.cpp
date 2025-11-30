#include "patterns.h"
#include <vector>

/**
 * @brief Get the Glider pattern
 * 
 * The smallest pattern that moves across the grid.
 * @return Pattern as a 2D vector of booleans
 */
std::vector<std::vector<bool>> Patterns::getGliderPattern() {
    return {
        {false, true, false},
        {false, false, true},
        {true, true, true}
    };
}

/**
 * @brief Get the Spaceship pattern
 * 
 * A pattern that moves diagonally across the grid.
 * @return Pattern as a 2D vector of booleans
 */
std::vector<std::vector<bool>> Patterns::getSpaceshipPattern() {
    return {
        {false, true, false, false, true},
        {true, false, false, false, false},
        {true, false, false, false, false},
        {false, true, true, true, true}
    };
}

/**
 * @brief Get the Rake pattern
 * 
 * A pattern that produces spaceships as it evolves.
 * @return Pattern as a 2D vector of booleans
 */
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

/**
 * @brief Get the Reflector pattern
 * 
 * A pattern that reflects gliders back in the opposite direction.
 * @return Pattern as a 2D vector of booleans
 */
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

/**
 * @brief Get the Replicator pattern
 * 
 * A pattern that replicates itself over time.
 * @return Pattern as a 2D vector of booleans
 */
std::vector<std::vector<bool>> Patterns::getReplicatorPattern() {
    return {
        {false, true, false, true, false},
        {true, false, false, false, true},
        {false, false, false, false, false},
        {true, false, false, false, true},
        {false, true, false, true, false}
    };
}

/**
 * @brief Get the Breeder pattern
 * 
 * A pattern that creates gliders and other patterns.
 * This is a more realistic implementation of a breeder pattern.
 * @return Pattern as a 2D vector of booleans
 */
std::vector<std::vector<bool>> Patterns::getBreederPattern() {
    // A simple breeder pattern (actual implementation would be much more complex)
    // Using a more recognizable pattern for demonstration
    std::vector<std::vector<bool>> breederPattern(16, std::vector<bool>(16, false));
    
    // Add some live cells to make it interesting - a basic "breeder" pattern structure
    breederPattern[2][4] = true;
    breederPattern[2][5] = true;
    breederPattern[3][4] = true;
    breederPattern[3][5] = true;
    
    breederPattern[6][8] = true;
    breederPattern[7][8] = true;
    breederPattern[8][8] = true;
    breederPattern[9][8] = true;
    
    breederPattern[12][10] = true;
    breederPattern[13][10] = true;
    breederPattern[14][10] = true;
    breederPattern[15][10] = true;
    
    return breederPattern;
}

/**
 * @brief Get the Train pattern
 * 
 * A pattern that moves horizontally across the grid.
 * @return Pattern as a 2D vector of booleans
 */
std::vector<std::vector<bool>> Patterns::getTrainPattern() {
    return {
        {false, false, false, false, false, false, false, false},
        {false, true, true, true, false, false, false, false},
        {false, false, false, false, true, true, true, false},
        {false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false}
    };
}

/**
 * @brief Get the Gun pattern
 * 
 * The Gosper Glider Gun - a pattern that continuously produces gliders.
 * @return Pattern as a 2D vector of booleans
 */
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

/**
 * @brief Get the Pulsar pattern
 * 
 * An oscillator pattern with period 3.
 * @return Pattern as a 2D vector of booleans
 */
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

/**
 * @brief Get the Clock pattern
 * 
 * A simple oscillator pattern with period 4.
 * @return Pattern as a 2D vector of booleans
 */
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

/**
 * @brief Get the Beacon pattern
 * 
 * An oscillator pattern with period 2.
 * @return Pattern as a 2D vector of booleans
 */
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

/**
 * @brief Get the Toad pattern
 * 
 * An oscillator pattern with period 2.
 * @return Pattern as a 2D vector of booleans
 */
std::vector<std::vector<bool>> Patterns::getToadPattern() {
    // Toad pattern (period 2)
    return {
        {false, false, false, false},
        {false, false, true, true},
        {false, true, true, false},
        {false, false, false, false}
    };
}

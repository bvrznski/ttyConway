#ifndef PATTERNS_H
#define PATTERNS_H

#include <vector>
#include <utility>

/**
 * @brief Collection of predefined Game of Life patterns
 * 
 * This class provides static methods to retrieve various classic Game of Life patterns
 * including gliders, spaceships, guns, oscillators, and other well-known patterns.
 */
class Patterns {
public:
    /**
     * @brief Get the Glider pattern
     * 
     * The smallest pattern that moves across the grid.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getGliderPattern();
    
    /**
     * @brief Get the Spaceship pattern
     * 
     * A pattern that moves diagonally across the grid.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getSpaceshipPattern();
    
    /**
     * @brief Get the Rake pattern
     * 
     * A pattern that produces spaceships as it evolves.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getRakePattern();
    
    /**
     * @brief Get the Reflector pattern
     * 
     * A pattern that reflects gliders back in the opposite direction.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getReflectorPattern();
    
    /**
     * @brief Get the Replicator pattern
     * 
     * A pattern that replicates itself over time.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getReplicatorPattern();
    
    /**
     * @brief Get the Breeder pattern
     * 
     * A pattern that creates gliders and other patterns.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getBreederPattern();
    
    /**
     * @brief Get the Train pattern
     * 
     * A pattern that moves horizontally across the grid.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getTrainPattern();
    
    /**
     * @brief Get the Gun pattern
     * 
     * The Gosper Glider Gun - a pattern that continuously produces gliders.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getGunPattern();
    
    /**
     * @brief Get the Pulsar pattern
     * 
     * An oscillator pattern with period 3.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getPulsarPattern();
    
    /**
     * @brief Get the Clock pattern
     * 
     * A simple oscillator pattern with period 4.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getClockPattern();
    
    /**
     * @brief Get the Beacon pattern
     * 
     * An oscillator pattern with period 2.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getBeaconPattern();
    
    /**
     * @brief Get the Toad pattern
     * 
     * An oscillator pattern with period 2.
     * @return Pattern as a 2D vector of booleans
     */
    static std::vector<std::vector<bool>> getToadPattern();
};

#endif // PATTERNS_H

#ifndef PATTERNS_H
#define PATTERNS_H

#include <vector>
#include <utility>

class Patterns {
public:
    // Get pattern definitions
    static std::vector<std::vector<bool>> getGliderPattern();
    static std::vector<std::vector<bool>> getSpaceshipPattern();
    static std::vector<std::vector<bool>> getRakePattern();
    static std::vector<std::vector<bool>> getReflectorPattern();
    static std::vector<std::vector<bool>> getReplicatorPattern();
    static std::vector<std::vector<bool>> getBreederPattern();
    static std::vector<std::vector<bool>> getTrainPattern();
    static std::vector<std::vector<bool>> getGunPattern();
};

#endif // PATTERNS_H

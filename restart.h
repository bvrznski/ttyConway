#ifndef RESTART_H
#define RESTART_H

#include <vector>

// Function to check if current grid matches any of the previous 10 frames
bool arrayduplication(const std::vector<std::vector<bool>>& current, const std::vector<std::vector<std::vector<bool>>>& frames);

// Function to add current frame to the collection
void addFrame(const std::vector<std::vector<bool>>& current, std::vector<std::vector<std::vector<bool>>>& frames);

// Function to restart the simulation
void restartSimulation(std::vector<std::vector<bool>>& grid, int width, int height);

#endif // RESTART_H

#include "restart.h"
#include <vector>

bool arrayduplication(const std::vector<std::vector<bool>>& current, const std::vector<std::vector<std::vector<bool>>>& frames) {
    // Check if current grid matches any of the previous 10 frames
    for (int i = 0; i < 10 && i < static_cast<int>(frames.size()); i++) {
        if (current == frames[i]) {
            return true;
        }
    }
    return false;
}

void addFrame(const std::vector<std::vector<bool>>& current, std::vector<std::vector<std::vector<bool>>>& frames) {
    // Add current frame to the collection
    frames.push_back(current);
    
    // Keep only the last 10 frames
    if (frames.size() > 10) {
        frames.erase(frames.begin());
    }
}

void restartSimulation(std::vector<std::vector<bool>>& grid, int width, int height) {
    // Clear the grid
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = false;
        }
    }
    
    // Reinitialize with random pattern
    // This is a simple restart - you could implement more sophisticated restarting logic here
}

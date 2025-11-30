#include "restart.h"
bool arrayduplication(const std::vector<std::vector<bool>>& currentGrid, const std::vector<std::vector<std::vector<bool>>>& frames) {
    if (frames.size() < 10) return false;
    
    // Check if the current grid matches any of the previous 10 frames
    for (const auto& frame : frames) {
        if (frame == currentGrid) {
            return true;
        }
    }
    
    return false;
}

void addFrame(const std::vector<std::vector<bool>>& currentGrid, std::vector<std::vector<std::vector<bool>>>& frames) {
    if (frames.size() >= 10) {
        frames.erase(frames.begin());
    }
    frames.push_back(currentGrid);
}

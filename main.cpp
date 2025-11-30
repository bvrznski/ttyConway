#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include "patterns.h"
#include "restart.h"

// Game of Life implementation with pattern support

class GameOfLife {
private:
    std::vector<std::vector<bool>> grid;
    std::vector<std::vector<bool>> nextGrid;
    int width, height;
    std::mt19937 rng;

public:
    GameOfLife(int w, int h) : width(w), height(h), rng(std::random_device{}()) {
        grid.resize(height, std::vector<bool>(width, false));
        nextGrid.resize(height, std::vector<bool>(width, false));
    }

    // Clear the grid
    void clear() {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                grid[y][x] = false;
            }
        }
    }

    // Randomly initialize the grid
    void randomize(double density = 0.2) {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                grid[y][x] = (dist(rng) < density);
            }
        }
    }

    // Add a pattern to the grid at given position
    void addPattern(const std::vector<std::vector<bool>>& pattern, int startX, int startY) {
        for (size_t y = 0; y < pattern.size(); ++y) {
            for (size_t x = 0; x < pattern[y].size(); ++x) {
                if (startX + static_cast<int>(x) >= 0 && 
                    startX + static_cast<int>(x) < width &&
                    startY + static_cast<int>(y) >= 0 && 
                    startY + static_cast<int>(y) < height) {
                    grid[startY + y][startX + x] = pattern[y][x];
                }
            }
        }
    }

    // Get a random rotation of a pattern (0-3 rotations)
    std::vector<std::vector<bool>> getRandomRotation(const std::vector<std::vector<bool>>& pattern) {
        int rotations = std::uniform_int_distribution<int>(0, 3)(rng);
        auto rotated = pattern;
        
        for (int i = 0; i < rotations; ++i) {
            rotated = rotatePattern(rotated);
        }
        return rotated;
    }

    // Rotate a pattern 90 degrees clockwise
    std::vector<std::vector<bool>> rotatePattern(const std::vector<std::vector<bool>>& pattern) {
        int rows = pattern.size();
        if (rows == 0) return pattern;
        int cols = pattern[0].size();
        
        std::vector<std::vector<bool>> rotated(cols, std::vector<bool>(rows, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                rotated[j][rows - 1 - i] = pattern[i][j];
            }
        }
        return rotated;
    }

    // Get random position within grid bounds
    std::pair<int, int> getRandomPosition(int patternWidth, int patternHeight) {
        std::uniform_int_distribution<int> xDist(0, width - patternWidth);
        std::uniform_int_distribution<int> yDist(0, height - patternHeight);
        return {xDist(rng), yDist(rng)};
    }

    // Get the number of live neighbors for a cell
    int countNeighbors(int x, int y) {
        int count = 0;
        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                    if (grid[ny][nx]) count++;
                }
            }
        }
        return count;
    }

    // Compute next generation
    void computeNextGeneration() {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int neighbors = countNeighbors(x, y);
                if (grid[y][x]) {
                    // Cell is alive
                    nextGrid[y][x] = (neighbors == 2 || neighbors == 3);
                } else {
                    // Cell is dead
                    nextGrid[y][x] = (neighbors == 3);
                }
            }
        }
        grid = nextGrid;
    }

    // Display the grid
    void display() {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                std::cout << (grid[y][x] ? '*' : ' ');
            }
            std::cout << '\n';
        }
    }

    // Get grid reference for pattern checking
    const std::vector<std::vector<bool>>& getGrid() const {
        return grid;
    }

    // Initialize with a specific pattern at random location
    void initializeWithPattern(const std::vector<std::vector<bool>>& pattern) {
        clear();
        auto rotatedPattern = getRandomRotation(pattern);
        auto [x, y] = getRandomPosition(rotatedPattern[0].size(), rotatedPattern.size());
        addPattern(rotatedPattern, x, y);
    }
};

void printUsage() {
    std::cout << "Usage: ./conway [--glider|--spaceship|--rake|--reflector|--replicator|--breeder|--train|--gun]\n";
    std::cout << "If no arguments are provided, runs normal Game of Life with random initialization.\n";
}

int main(int argc, char* argv[]) {
    const int WIDTH = 40;
    const int HEIGHT = 20;
    
    GameOfLife game(WIDTH, HEIGHT);
    
    // Check if any pattern flag is provided
    if (argc == 1) {
        // No arguments - run normal Game of Life with random initialization
        std::cout << "Running standard Game of Life with random initialization.\n";
        game.randomize(0.2);
    } else if (argc == 2) {
        // One argument - initialize with specific pattern
        std::string arg = argv[1];
        
        if (arg == "--glider") {
            std::cout << "Initializing with Glider pattern.\n";
            game.initializeWithPattern(Patterns::getGliderPattern());
        } else if (arg == "--spaceship") {
            std::cout << "Initializing with Spaceship pattern.\n";
            game.initializeWithPattern(Patterns::getSpaceshipPattern());
        } else if (arg == "--rake") {
            std::cout << "Initializing with Rake pattern.\n";
            game.initializeWithPattern(Patterns::getRakePattern());
        } else if (arg == "--reflector") {
            std::cout << "Initializing with Reflector pattern.\n";
            game.initializeWithPattern(Patterns::getReflectorPattern());
        } else if (arg == "--replicator") {
            std::cout << "Initializing with Replicator pattern.\n";
            game.initializeWithPattern(Patterns::getReplicatorPattern());
        } else if (arg == "--breeder") {
            std::cout << "Initializing with Breeder pattern.\n";
            game.initializeWithPattern(Patterns::getBreederPattern());
        } else if (arg == "--train") {
            std::cout << "Initializing with Train pattern.\n";
            game.initializeWithPattern(Patterns::getTrainPattern());
        } else if (arg == "--gun") {
            std::cout << "Initializing with Gun pattern.\n";
            game.initializeWithPattern(Patterns::getGunPattern());
        } else {
            std::cerr << "Unknown pattern: " << arg << "\n";
            printUsage();
            return 1;
        }
    } else {
        // Multiple arguments or invalid usage
        std::cerr << "Invalid number of arguments.\n";
        printUsage();
        return 1;
    }

    // Main game loop - with pattern checking and restart functionality
    std::cout << "Press Enter to start the simulation (or Ctrl+C to exit).\n";
    std::cin.get();
    
    // Keep track of last 10 frames for pattern detection
    std::vector<std::vector<std::vector<bool>>> frames;
    
    int generation = 0;
    while (generation < 1000) {  // Prevent infinite loop, run up to 1000 generations
        std::cout << "\nGeneration " << generation << ":\n";
        game.display();
        
        // Check for repeating patterns
        if (arrayduplication(game.getGrid(), frames)) {
            // Pattern repeated - restart simulation
            std::cout << "Pattern repeated - restarting simulation.\n";
            game.randomize(0.2);  // Reinitialize with random pattern
            frames.clear();      // Clear the frame history
        } else {
            addFrame(game.getGrid(), frames);
        }
        
        game.computeNextGeneration();
        
        // Small delay
        for (volatile int i = 0; i < 10000000; ++i);
        generation++;
    }
    
    return 0;
}

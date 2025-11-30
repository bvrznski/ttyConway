#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include "patterns.h"
#include "interactive.h"

/**
 * @brief Conway's Game of Life implementation
 * 
 * This class implements the cellular automaton known as Conway's Game of Life.
 * It supports pattern initialization, random initialization, and various simulation features.
 */
class GameOfLife {
private:
    std::vector<std::vector<bool>> grid;
    std::vector<std::vector<bool>> nextGrid;
    int width, height;
    std::mt19937 rng;
    int generationCount;  // Track the current generation
    int liveCellCount;    // Track number of live cells

public:
    // Constructor that gets terminal dimensions
    GameOfLife() {
        // Get terminal dimensions
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        height = w.ws_row - 1;  // Leave one line for prompt
        width = w.ws_col;
        
        // Ensure minimum size
        if (height < 10) height = 10;
        if (width < 10) width = 10;
        
        grid.resize(height, std::vector<bool>(width, false));
        nextGrid.resize(height, std::vector<bool>(width, false));
        generationCount = 0;
        liveCellCount = 0;
    }
    
    GameOfLife(int w, int h) : width(w), height(h), rng(std::random_device{}()), generationCount(0), liveCellCount(0) {
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

    // Display the grid with optional color support
    void display(bool useColor = false) {
        if (useColor) {
            // ANSI color codes for colored output
            const char* liveCell = "\033[32m*\033[0m";  // Green color for live cells
            const char* deadCell = " ";                 // No color for dead cells
            
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    if (grid[y][x]) {
                        std::cout << liveCell;
                    } else {
                        std::cout << deadCell;
                    }
                }
                std::cout << '\n';
            }
        } else {
            // Default monochrome display
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    std::cout << (grid[y][x] ? '*' : ' ');
                }
                std::cout << '\n';
            }
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
    
    // Get reference to grid for interactive mode
    std::vector<std::vector<bool>>& getGridRef() {
        return grid;
    }
    
    // Get current generation count
    int getGeneration() const {
        return generationCount;
    }
    
    // Count live cells in the grid
    int countLiveCells() const {
        int count = 0;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (grid[y][x]) {
                    count++;
                }
            }
        }
        return count;
    }
    
    // Get live cell count
    int getLiveCellCount() const {
        return liveCellCount;
    }
    
    // Update generation count and live cell count
    void updateStatistics() {
        generationCount++;
        liveCellCount = countLiveCells();
    }
};

void printUsage() {
    std::cout << "Usage: ./conway [--width N] [--height N] [--speed N] [--save FILENAME|--load FILENAME] [--pattern-file FILENAME] [--color|--mono] [--glider|--spaceship|--rake|--reflector|--replicator|--breeder|--train|--gun|--pulsar|--clock|--beacon|--toad|--interactive]\n";
    std::cout << "If no arguments are provided, runs normal Game of Life with random initialization.\n";
    std::cout << "--interactive - Run in interactive mode where you can place cells manually\n";
    std::cout << "--width N - Set grid width (default: 40)\n";
    std::cout << "--height N - Set grid height (default: 20)\n";
    std::cout << "--speed N - Set simulation speed (1-10, default: 5)\n";
    std::cout << "--save FILENAME - Save current grid state to file\n";
    std::cout << "--load FILENAME - Load grid state from file\n";
    std::cout << "--pattern-file FILENAME - Load pattern definition from file\n";
    std::cout << "--color - Enable colored display (live cells in color)\n";
    std::cout << "--mono - Use monochrome display (default)\n";
}

// Save grid state to file
bool saveGrid(const std::vector<std::vector<bool>>& grid, int width, int height, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << " for writing\n";
        return false;
    }
    
    // Write dimensions
    file << width << " " << height << "\n";
    
    // Write grid data
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file << (grid[y][x] ? '1' : '0');
        }
        file << "\n";
    }
    
    file.close();
    return true;
}

// Load grid state from file
bool loadGrid(std::vector<std::vector<bool>>& grid, int& width, int& height, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << " for reading\n";
        return false;
    }
    
    // Read dimensions
    if (!(file >> width >> height)) {
        std::cerr << "Error: Invalid file format - cannot read dimensions\n";
        file.close();
        return false;
    }
    
    // Resize grid
    grid.resize(height, std::vector<bool>(width, false));
    
    // Read grid data
    std::string line;
    for (int y = 0; y < height; ++y) {
        if (!std::getline(file, line)) {
            std::cerr << "Error: Invalid file format - unexpected end of file\n";
            file.close();
            return false;
        }
        
        // Trim trailing whitespace
        line.erase(std::find_if(line.rbegin(), line.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), line.end());
        
        if (line.length() != static_cast<size_t>(width)) {
            std::cerr << "Error: Invalid file format - incorrect row length\n";
            file.close();
            return false;
        }
        
        for (int x = 0; x < width; ++x) {
            if (line[x] == '1') {
                grid[y][x] = true;
            } else if (line[x] == '0') {
                grid[y][x] = false;
            } else {
                std::cerr << "Error: Invalid file format - unexpected character '" << line[x] << "'\n";
                file.close();
                return false;
            }
        }
    }
    
    file.close();
    return true;
}

/**
 * @brief Main function for Conway's Game of Life implementation
 * 
 * This is the entry point of the program that handles command line arguments,
 * initializes the game based on provided parameters, and runs the simulation loop.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * @return Exit status of the program
 */
int main(int argc, char* argv[]) {
    int width = 40;
    int height = 20;
    int speed = 5; // Default speed (1-10)
    std::string saveFile = "";
    std::string loadFile = "";
    bool useColor = false; // Default to monochrome display
    
    // Parse command line arguments for grid dimensions and speed
    std::string patternFile = "";
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--width" && i + 1 < argc) {
            try {
                width = std::stoi(argv[i + 1]);
                if (width <= 0) {
                    std::cerr << "Error: Width must be positive\n";
                    return 1;
                }
                ++i; // Skip next argument
            } catch (const std::exception&) {
                std::cerr << "Error: Invalid width value\n";
                return 1;
            }
        } else if (arg == "--height" && i + 1 < argc) {
            try {
                height = std::stoi(argv[i + 1]);
                if (height <= 0) {
                    std::cerr << "Error: Height must be positive\n";
                    return 1;
                }
                ++i; // Skip next argument
            } catch (const std::exception&) {
                std::cerr << "Error: Invalid height value\n";
                return 1;
            }
        } else if (arg == "--speed" && i + 1 < argc) {
            try {
                speed = std::stoi(argv[i + 1]);
                if (speed < 1 || speed > 10) {
                    std::cerr << "Error: Speed must be between 1 and 10\n";
                    return 1;
                }
                ++i; // Skip next argument
            } catch (const std::exception&) {
                std::cerr << "Error: Invalid speed value\n";
                return 1;
            }
        } else if (arg == "--save" && i + 1 < argc) {
            saveFile = argv[i + 1];
            ++i; // Skip next argument
        } else if (arg == "--load" && i + 1 < argc) {
            loadFile = argv[i + 1];
            ++i; // Skip next argument
        } else if (arg == "--pattern-file" && i + 1 < argc) {
            patternFile = argv[i + 1];
            ++i; // Skip next argument
        } else if (arg == "--color") {
            useColor = true;
        } else if (arg == "--mono") {
            useColor = false;
        }
    }
    
    GameOfLife game;
    
    // Handle load operation first, if specified
    if (!loadFile.empty()) {
        std::vector<std::vector<bool>> loadedGrid;
        if (loadGrid(loadedGrid, width, height, loadFile)) {
            game = GameOfLife(width, height);
            game.getGridRef() = loadedGrid;
            std::cout << "Loaded grid state from " << loadFile << "\n";
        } else {
            return 1;
        }
    }
    
    // Check what arguments are provided
    if (argc == 1) {
        // No arguments - run normal Game of Life with random initialization
        // Use the terminal-sized constructor
        game = GameOfLife();
        std::cout << "Running standard Game of Life with random initialization.\n";
        game.randomize(0.2);
    } else {
        // Check for pattern or interactive mode flag in the remaining arguments
        bool foundPattern = false;
        std::string patternArg = "";
        bool isPatternFile = false;
        
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if (arg == "--pattern-file" && i + 1 < argc) {
                // If we have a pattern file, we'll handle it specially
                isPatternFile = true;
                break;
            } else if (arg == "--glider" || arg == "--spaceship" || arg == "--rake" || 
                arg == "--reflector" || arg == "--replicator" || arg == "--breeder" ||
                arg == "--train" || arg == "--gun" || arg == "--pulsar" || arg == "--clock" ||
                arg == "--beacon" || arg == "--toad" || arg == "--interactive") {
                patternArg = arg;
                foundPattern = true;
                break;
            }
        }
        
        if (!foundPattern && !isPatternFile) {
            // No valid pattern or interactive flag - invalid usage
            std::cerr << "Invalid arguments. Please provide a valid pattern flag.\n";
            printUsage();
            return 1;
        }
        
        // Handle the pattern file option first, if specified
        if (isPatternFile && !patternFile.empty()) {
            // Load pattern from file
            std::ifstream file(patternFile);
            if (!file.is_open()) {
                std::cerr << "Error: Cannot open pattern file " << patternFile << "\n";
                return 1;
            }
            
            // Read dimensions
            int patternWidth, patternHeight;
            if (!(file >> patternWidth >> patternHeight)) {
                std::cerr << "Error: Invalid pattern file format - cannot read dimensions\n";
                file.close();
                return 1;
            }
            
            // Skip the newline after dimensions
            std::string temp;
            std::getline(file, temp);
            
            // Read pattern data
            std::vector<std::vector<bool>> pattern(patternHeight, std::vector<bool>(patternWidth, false));
            std::string line;
            for (int y = 0; y < patternHeight; ++y) {
                if (!std::getline(file, line)) {
                    std::cerr << "Error: Invalid pattern file format - unexpected end of file\n";
                    file.close();
                    return 1;
                }
                
                // Remove any trailing whitespace or newline characters
                size_t end = line.find_last_not_of(" \r\n\t");
                if (end != std::string::npos) {
                    line = line.substr(0, end + 1);
                }
                
                if (line.length() != static_cast<size_t>(patternWidth)) {
                    std::cerr << "Error: Invalid pattern file format - incorrect row length. Expected " << patternWidth << ", got " << line.length() << "\n";
                    file.close();
                    return 1;
                }
                
                for (int x = 0; x < patternWidth; ++x) {
                    if (line[x] == '1' || line[x] == '*') {
                        pattern[y][x] = true;
                    } else if (line[x] == '0' || line[x] == ' ') {
                        pattern[y][x] = false;
                    } else {
                        std::cerr << "Error: Invalid pattern file format - unexpected character '" << line[x] << "'\n";
                        file.close();
                        return 1;
                    }
                }
            }
            
            file.close();
            
            // Initialize game with the loaded pattern
            std::cout << "Initializing with pattern from file " << patternFile << "\n";
            game.initializeWithPattern(pattern);
        } else if (patternArg == "--interactive") {
            // Interactive mode
            std::cout << "Starting interactive mode. Place cells and then start simulation.\n";
            std::cout << "Press Enter to continue...\n";
            std::cin.get();
            
            // Initialize with empty grid
            game.clear();
            
            // Interactive loop
            InteractiveMode interactive(game.getGridRef(), width, height);
            interactive.showInstructions();
            interactive.displayGrid();
            
            std::string command;
            while (true) {
                std::cout << "Enter command: ";
                std::getline(std::cin, command);
                
                if (command == "q" || command == "Q") {
                    break;
                } else if (command == "p" || command == "P") {
                    interactive.placeCells();
                } else if (command == "c" || command == "C") {
                    interactive.clearGrid();
                    interactive.displayGrid();
                } else if (command == "s" || command == "S") {
                    // Start simulation
                    break;
                } else if (command == "h" || command == "H") {
                    interactive.showInstructions();
                } else {
                    std::cout << "Unknown command. Type 'h' for help.\n";
                }
            }
            
            // Continue with simulation after interactive mode
        } else {
            // Pattern initialization
            if (patternArg == "--glider") {
                std::cout << "Initializing with Glider pattern.\n";
                game.initializeWithPattern(Patterns::getGliderPattern());
            } else if (patternArg == "--spaceship") {
                std::cout << "Initializing with Spaceship pattern.\n";
                game.initializeWithPattern(Patterns::getSpaceshipPattern());
            } else if (patternArg == "--rake") {
                std::cout << "Initializing with Rake pattern.\n";
                game.initializeWithPattern(Patterns::getRakePattern());
            } else if (patternArg == "--reflector") {
                std::cout << "Initializing with Reflector pattern.\n";
                game.initializeWithPattern(Patterns::getReflectorPattern());
            } else if (patternArg == "--replicator") {
                std::cout << "Initializing with Replicator pattern.\n";
                game.initializeWithPattern(Patterns::getReplicatorPattern());
            } else if (patternArg == "--breeder") {
                std::cout << "Initializing with Breeder pattern.\n";
                game.initializeWithPattern(Patterns::getBreederPattern());
            } else if (patternArg == "--train") {
                std::cout << "Initializing with Train pattern.\n";
                game.initializeWithPattern(Patterns::getTrainPattern());
            } else if (patternArg == "--gun") {
                // Check for valid pattern size to prevent segmentation fault
                auto gun = Patterns::getGunPattern();
                if (gun.empty() || gun[0].empty()) {
                    std::cerr << "Error: Gun pattern is invalid\n";
                    return 1;
                }
                std::cout << "Initializing with Gun pattern.\n";
                game.initializeWithPattern(gun);
            } else if (patternArg == "--pulsar") {
                // Check for valid pattern size to prevent segmentation fault
                auto pulsar = Patterns::getPulsarPattern();
                if (pulsar.empty() || pulsar[0].empty()) {
                    std::cerr << "Error: Pulsar pattern is invalid\n";
                    return 1;
                }
                std::cout << "Initializing with Pulsar pattern.\n";
                game.initializeWithPattern(pulsar);
            } else if (patternArg == "--clock") {
                std::cout << "Initializing with Clock pattern.\n";
                game.initializeWithPattern(Patterns::getClockPattern());
            } else if (patternArg == "--beacon") {
                std::cout << "Initializing with Beacon pattern.\n";
                game.initializeWithPattern(Patterns::getBeaconPattern());
            } else if (patternArg == "--toad") {
                std::cout << "Initializing with Toad pattern.\n";
                game.initializeWithPattern(Patterns::getToadPattern());
            }
        }
    }

    // Main game loop
    if (argc != 2 || std::string(argv[1]) != "--interactive") {
        std::cout << "Press Enter to start the simulation (or Ctrl+C to exit).\n";
        std::cin.get();
        
        int generation = 0;
        const int maxGenerations = 1000; // Prevent infinite loop
        
        while (generation < maxGenerations) {
            // Update statistics before displaying
            game.updateStatistics();
            
            std::cout << "\nGeneration " << game.getGeneration() << " | Live Cells: " << game.getLiveCellCount() << "\n";
            game.display(useColor);
            
            game.computeNextGeneration();
            
            // Small delay - scaled by speed (speed 1 is slowest, speed 10 is fastest)
            int delay = 10000000 / speed;
            for (volatile int i = 0; i < delay; ++i);
            generation++;
        }
    }
    
    // Save grid state if requested
    if (!saveFile.empty()) {
        if (saveGrid(game.getGrid(), width, height, saveFile)) {
            std::cout << "Saved grid state to " << saveFile << "\n";
        } else {
            return 1;
        }
    }

    return 0;
}

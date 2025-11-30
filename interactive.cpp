#include "interactive.h"
#include <iostream>
#include <limits>

void InteractiveMode::displayGrid() {
    // Print column numbers
    std::cout << "   ";
    for (int x = 0; x < width; ++x) {
        if (x < 10) {
            std::cout << x;
        } else {
            std::cout << x % 10;
        }
    }
    std::cout << "\n";
    
    // Print grid with row numbers
    for (int y = 0; y < height; ++y) {
        if (y < 10) {
            std::cout << y << " ";
        } else {
            std::cout << y % 10 << " ";
        }
        
        for (int x = 0; x < width; ++x) {
            std::cout << (grid[y][x] ? '*' : ' ');
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void InteractiveMode::showInstructions() {
    std::cout << "Interactive Mode Instructions:\n";
    std::cout << "Commands:\n";
    std::cout << "  'p' or 'P' - Place cells interactively\n";
    std::cout << "  'c' or 'C' - Clear the grid\n";
    std::cout << "  's' or 'S' - Start simulation\n";
    std::cout << "  'q' or 'Q' - Quit interactive mode\n";
    std::cout << "  'h' or 'H' - Show this help\n";
    std::cout << "\n";
    std::cout << "To place cells, type coordinates like: 5,10\n";
    std::cout << "Enter multiple coordinates separated by spaces.\n";
    std::cout << "Example: 5,10 12,8 3,15\n";
    std::cout << "\n";
}

void InteractiveMode::toggleCell(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = !grid[y][x];
    }
}

void InteractiveMode::clearGrid() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = false;
        }
    }
}

void InteractiveMode::placeCells() {
    std::cout << "Enter coordinates to place cells (e.g., '5,10 12,8'):\n";
    std::cout << "Type 'done' when finished.\n";
    
    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        if (input == "done" || input == "DONE") {
            break;
        }
        
        // Parse the input
        size_t pos = 0;
        while (pos < input.length()) {
            // Find comma
            size_t commaPos = input.find(',', pos);
            if (commaPos == std::string::npos) {
                break;
            }
            
            // Extract x coordinate
            int x = std::stoi(input.substr(pos, commaPos - pos));
            
            // Find end of number for y coordinate
            size_t nextSpace = input.find(' ', commaPos);
            if (nextSpace == std::string::npos) {
                nextSpace = input.length();
            }
            
            // Extract y coordinate
            int y = std::stoi(input.substr(commaPos + 1, nextSpace - commaPos - 1));
            
            toggleCell(x, y);
            
            pos = nextSpace;
            if (pos < input.length()) {
                pos++; // Skip the space
            }
        }
        
        displayGrid();
    }
}

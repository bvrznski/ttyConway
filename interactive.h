#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <vector>
#include <iostream>

class InteractiveMode {
private:
    std::vector<std::vector<bool>>& grid;
    int width, height;
    
public:
    InteractiveMode(std::vector<std::vector<bool>>& g, int w, int h) 
        : grid(g), width(w), height(h) {}
    
    // Display the grid with coordinates
    void displayGrid();
    
    // Get user input for placing cells
    void placeCells();
    
    // Toggle cell state at position
    void toggleCell(int x, int y);
    
    // Clear the grid
    void clearGrid();
    
    // Show interactive mode instructions
    void showInstructions();
};

#endif // INTERACTIVE_H

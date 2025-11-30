#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <vector>
#include <iostream>

/**
 * @brief Interactive mode for placing cells manually
 * 
 * This class provides functionality for users to manually place cells on the grid
 * before starting the simulation. It allows for placing, clearing, and viewing cells.
 */
class InteractiveMode {
private:
    std::vector<std::vector<bool>>& grid;
    int width, height;
    
public:
    /**
     * @brief Constructor for InteractiveMode
     * 
     * @param g Reference to the game grid
     * @param w Width of the grid
     * @param h Height of the grid
     */
    InteractiveMode(std::vector<std::vector<bool>>& g, int w, int h) 
        : grid(g), width(w), height(h) {}
    
    /**
     * @brief Display the current grid with coordinates
     * 
     * Shows the grid with row and column numbers for easier cell placement.
     */
    void displayGrid();
    
    /**
     * @brief Get user input for placing cells
     * 
     * Allows users to specify coordinates to place live cells on the grid.
     * Coordinates are entered in format like "5,10 12,8".
     */
    void placeCells();
    
    /**
     * @brief Toggle cell state at specified position
     * 
     * Changes the state of a cell from alive to dead or vice versa.
     * 
     * @param x X coordinate of the cell
     * @param y Y coordinate of the cell
     */
    void toggleCell(int x, int y);
    
    /**
     * @brief Clear the entire grid
     * 
     * Sets all cells to dead state.
     */
    void clearGrid();
    
    /**
     * @brief Show interactive mode instructions
     * 
     * Displays help information about how to use interactive mode commands.
     */
    void showInstructions();
};

#endif // INTERACTIVE_H

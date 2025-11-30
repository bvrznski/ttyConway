#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <sys/ioctl.h>

using namespace std;

class GameOfLife {
private:
    vector<vector<char>> grid;
    vector<vector<char>> nextGrid;
    vector<vector<vector<char>>> history;
    int rows, cols;
    int historyIndex;
    int duplicateCount;
    
public:
    GameOfLife() {
        // Get terminal dimensions
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        rows = w.ws_row - 1;  // Leave one line for prompt
        cols = w.ws_col;
        
        // Ensure minimum size
        if (rows < 10) rows = 10;
        if (cols < 10) cols = 10;
        
        grid.resize(rows, vector<char>(cols, ' '));
        nextGrid.resize(rows, vector<char>(cols, ' '));
        history.resize(10, vector<vector<char>>(rows, vector<char>(cols, ' ')));
        historyIndex = 0;
        duplicateCount = 0;
    }
    
    void setCell(int row, int col, bool alive) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            if (alive) grid[row][col] = '#';
            else grid[row][col] = ' ';
        }
    }
    
    void randomize() {
        // Fill with higher density - about 40% alive cells
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                setCell(i, j, rand() % 100 < 40);  // 40% chance of being alive
            }
        }
    }
    
    // Add some interesting patterns
    void addInterestingPatterns() {
        // Add a glider pattern
        setCell(5, 5, true);
        setCell(6, 6, true);
        setCell(7, 4, true);
        setCell(7, 5, true);
        setCell(7, 6, true);
        
        // Add a small oscillator
        setCell(10, 10, true);
        setCell(10, 11, true);
        setCell(10, 12, true);
        
        // Add some random cells to make it more interesting
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rand() % 100 < 15) {  // 15% chance
                    setCell(i, j, true);
                }
            }
        }
    }
    
    int countNeighbors(int row, int col) {
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int r = row + i;
                int c = col + j;
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    if (grid[r][c] == '#') count++;
                }
            }
        }
        return count;
    }
    
    bool isGridEqual(const vector<vector<char>>& g1, const vector<vector<char>>& g2) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (g1[i][j] != g2[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void update() {
        // Save current grid to history
        history[historyIndex] = grid;
        historyIndex = (historyIndex + 1) % 10;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = countNeighbors(i, j);
                if (grid[i][j] == '#') {
                    if (neighbors < 2 || neighbors > 3) {
                        nextGrid[i][j] = ' ';
                    } else {
                        nextGrid[i][j] = '#';
                    }
                } else {
                    if (neighbors == 3) {
                        nextGrid[i][j] = '#';
                    } else {
                        nextGrid[i][j] = ' ';
                    }
                }
            }
        }
        grid = nextGrid;
    }
    
    bool arrayduplication(const vector<vector<char>>& current) {
        // Check if current grid is exactly the same as any of the last 10 previous grids
        for (int i = 0; i < 10; i++) {
            if (isGridEqual(current, history[i])) {
                return true;
            }
        }
        return false;
    }
    
    void display() {
        // Clear screen using ANSI escape codes
        cout << "\033[2J\033[H";
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '#') {
                    // Current cell is alive - determine what happens next
                    int neighbors = countNeighbors(i, j);
                    if (neighbors == 2 || neighbors == 3) {
                        // Cell will survive - GREEN (stays on screen)
                        cout << "\033[32m#\033[0m";  // Green
                    } else {
                        // Cell will die - RED (disappears from screen)
                        cout << "\033[31m#\033[0m";  // Red
                    }
                } else {
                    // Current cell is dead - check if it would be born next
                    int neighbors = countNeighbors(i, j);
                    if (neighbors == 3) {
                        // Cell will be born - WHITE (appears on screen)
                        cout << "\033[37m#\033[0m";  // White
                    } else {
                        cout << " ";  // Dead cell that remains dead
                    }
                }
            }
            cout << endl;
        }
    }
    
    void reset() {
        // Clear the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = ' ';
            }
        }
        // Reinitialize with new random pattern (denser)
        addInterestingPatterns();
        // Clear history
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < cols; k++) {
                    history[i][j][k] = ' ';
                }
            }
        }
        historyIndex = 0;
        duplicateCount = 0;
    }
    
    void checkAndResetIfDuplicate() {
        // Check if current grid matches any of the last 10 grids
        if (arrayduplication(grid)) {
            duplicateCount++;
            cout << "Duplicate pattern detected! Duplicate count: " << duplicateCount << "/2" << endl;
            
            // Restart after 2 occurrences of the same pattern
            if (duplicateCount >= 2) {
                cout << "\033[2J\033[H";
                cout << "2 duplicate patterns detected! Restarting simulation..." << endl;
                usleep(1000000); // Wait 1 second
                reset();
                duplicateCount = 0;
            }
        } else {
            // Reset counter if no duplicate found
            duplicateCount = 0;
        }
    }
    
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

int main() {
    GameOfLife game;
    
    // Add interesting patterns
    game.addInterestingPatterns();
    
    cout << "Conway's Game of Life - Duplicate Pattern Detection" << endl;
    cout << "Colors: White = Appears on screen, Green = Stays on screen, Red = Disappears from screen" << endl;
    cout << "Features: 2-duplicate-pattern detection + automatic restart" << endl;
    cout << "Press Ctrl+C to exit" << endl;
    usleep(1000000); // Wait 1 second before starting
    
    while (true) {
        game.display();
        game.update();
        
        // Check for duplicate patterns in history
        game.checkAndResetIfDuplicate();
        
        usleep(200000); // 0.2 seconds delay
    }
    
    return 0;
}

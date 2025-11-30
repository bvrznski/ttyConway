# Conway's Game of Life

Conway's Game of Life is a cellular automaton devised by mathematician John Conway. This implementation includes classic patterns that can be initialized via command line arguments.

## The Science Behind the Game of Life

Conway's Game of Life is a zero-player game, meaning its evolution is determined by its initial state, requiring no further input. It consists of a grid of cells, each of which can be either alive or dead, and follows four simple rules:

1. Any live cell with fewer than two live neighbors dies (underpopulation)
2. Any live cell with two or three live neighbors lives on
3. Any live cell with more than three live neighbors dies (overpopulation)
4. Any dead cell with exactly three live neighbors becomes alive (reproduction)

Despite its simplicity, the Game of Life can produce incredibly complex patterns and behaviors. It's a classic example of emergent behavior in cellular automata - simple rules leading to complex, unpredictable outcomes.

The Game of Life is Turing complete, meaning it can theoretically simulate any computer algorithm given enough time and space. This makes it a fascinating model for studying computation, complexity, and the emergence of order from randomness.

## Features

- Standard Game of Life simulation with random initialization
- Support for 8 classic patterns:
  - Glider
  - Spaceship
  - Rake
  - Reflector
  - Replicator
  - Breeder
  - Train
  - Gun
- Each pattern is randomly placed and rotated when initialized
- Clean terminal-based visualization
- Automatic restart detection when patterns repeat

## Usage

### Running Standard Game of Life
```bash
./conway
```
This will run the standard Game of Life with random initialization.

### Running with a Specific Pattern
```bash
./conway --glider
./conway --spaceship
./conway --rake
./conway --reflector
./conway --replicator
./conway --breeder
./conway --train
./conway --gun
./conway --pulsar
./conway --clock
./conway --beacon
./conway --toad
```

When a pattern flag is provided, the program will initialize with that specific pattern in a random location and orientation.

### Loading Patterns from Files
```bash
./conway --pattern-file my_pattern.txt
```
Load a pattern definition from a file. The pattern file should be in the format specified in [pattern_format.md](pattern_format.md).

Pattern files are text files with the following structure:
1. First line: Width and Height (two integers separated by space)
2. Subsequent lines: Grid representation where each character represents a cell
   - `1` or `*` = live cell
   - `0` or ` ` (space) = dead cell

Example pattern file:
```
10 5
0000000000
0000110000
0000110000
0000000000
0000000000
```

### Controlling Simulation Speed
```bash
./conway --speed 1
./conway --speed 10
```
The speed parameter controls how fast the simulation runs, with values from 1 (slowest) to 10 (fastest). Default speed is 5.

### Saving and Loading Grid States
```bash
./conway --save my_pattern.txt
./conway --load my_pattern.txt
```
Save the current grid state to a file or load a grid state from a file. The saved files contain the grid dimensions and cell states in a simple text format.

### Visualization Improvements
```bash
./conway --color
./conway --mono
```
Enable colored display where live cells appear in green, or use monochrome display (default). The color option makes it easier to distinguish live cells from dead ones during simulation.

## Building

To compile the program:
```bash
g++ -std=c++17 -o conway main.cpp patterns.cpp restart.cpp
```

## Patterns

### Glider
The smallest pattern that moves across the grid.

### Spaceship
A pattern that moves diagonally across the grid.

### Rake
A pattern that produces spaceships as it evolves.

### Reflector
A pattern that reflects gliders back in the opposite direction.

### Replicator
A pattern that replicates itself over time.

### Breeder
A pattern that creates gliders and other patterns.

### Train
A pattern that moves horizontally across the grid.

### Gun
The Gosper Glider Gun - a pattern that continuously produces gliders.

## Implementation Details

The program uses a 40x20 grid for visualization. Patterns are randomly placed within the grid boundaries and can be rotated in 0, 90, 180, or 270 degrees.

## Requirements

- C++17 compatible compiler
- Standard C++ libraries

## License

This project is created for educational purposes.

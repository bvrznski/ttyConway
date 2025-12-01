# ttyConway

Conway's Game of Life implemented in C++ with terminal visualization and duplicate pattern detection.

## Overview

This is a terminal-based implementation of Conway's Game of Life, a cellular automaton devised by mathematician John Horton Conway. The program simulates the evolution of a grid of cells based on simple rules, with visual feedback using ANSI color codes to indicate cell states.

## Features

- **Terminal-based visualization**: Runs entirely in the terminal with colorful output
- **ANSI color coding**:
  - Green: Cells that will survive (stay alive)
  - Red: Cells that will die (disappear)
  - White: Cells that will be born (appear)
- **Duplicate pattern detection**: Automatically detects when patterns repeat and restarts the simulation
- **Automatic restart**: After detecting 2 duplicate patterns, the simulation resets with a new random pattern
- **Responsive terminal sizing**: Adapts to terminal window dimensions

## How It Works

The Game of Life follows these rules:
1. Any live cell with fewer than two live neighbors dies (underpopulation)
2. Any live cell with two or three live neighbors lives on
3. Any live cell with more than three live neighbors dies (overpopulation)
4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction)

## Implementation Details

- Uses `ioctl` to determine terminal dimensions
- Implements history tracking of the last 10 grid states for duplicate detection
- Provides visual feedback through ANSI escape codes
- Includes interesting initial patterns like gliders and oscillators
- Randomizes starting patterns with ~40% cell density

## Controls

- **Ctrl+C**: Exit the program

## Requirements

- C++ compiler (g++, clang++, etc.)
- Terminal that supports ANSI color codes

## Building and Running

You can build the project using either of the following methods:

### Using Make (recommended)
```bash
make
./conway
```

### Using g++
```bash
g++ -o conway main.cpp
./conway
```

## Makefile

This project includes a Makefile that provides convenient build targets:

- `make` - Compiles the program with optimization flags
- `make clean` - Removes the compiled binary
- `make install` - Installs the binary to `/usr/local/bin/`

## License

This project is open source and available under the MIT License.

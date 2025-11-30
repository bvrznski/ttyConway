# Pattern File Format Specification

This document describes the format for pattern definition files that can be loaded into the Conway's Game of Life implementation.

## File Structure

Pattern files are text files with the following structure:
1. First line: Width and Height (two integers separated by space)
2. Subsequent lines: Grid representation where each character represents a cell
   - `1` or `*` = live cell
   - `0` or ` ` (space) = dead cell

## Example Format

```
10 5
0000000000
0000110000
0000110000
0000000000
0000000000
```

This represents a 10x5 grid with a 2x2 block of live cells in the center.

## Usage

Pattern files can be loaded using the command line argument:
```
./conway --pattern-file my_pattern.txt
```

The pattern will be randomly placed and rotated within the simulation grid, just like built-in patterns.

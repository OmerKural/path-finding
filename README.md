# Pathfinding Visualizer

An interactive, step-by-step visualizer for classic graph search algorithms, built in **C++** with **SFML 2**. A maze is auto-generated on launch — then watch DFS, BFS, or A* find their way through it in real time. You can also draw your own walls.

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?logo=c%2B%2B&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-2.6-green)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Screenshots

| Maze | Mid-search (A\*) | Path found |
|:---:|:---:|:---:|
| ![Maze](screenshots/maze.png) | ![Search](screenshots/search.png) | ![Path](screenshots/path.png) |

---

## Algorithms

| Algorithm | Strategy | Finds Shortest Path? |
|---|---|---|
| **BFS** | Layer-by-layer exploration via queue | ✅ Yes (unweighted grid) |
| **DFS** | Depth-first exploration via stack | ❌ Not guaranteed |
| **A\*** | Heuristic-guided via priority queue | ✅ Yes (octile distance heuristic) |

Each algorithm runs one step per frame so you can watch the search frontier expand in real time. A* uses the octile distance heuristic for accurate cost estimates with 8-directional movement.

---

## Controls

| Action | Input |
|---|---|
| Draw wall | Left-click + drag |
| Erase wall | Right-click + drag |
| Run DFS / BFS / A* | Click the corresponding button |
| Pause | Click **Pause** |
| Reset search | Click any algorithm button again |
| Quit | `Escape` or close window |

---

## Building & Running

### Prerequisites

- GCC / Clang / MSVC with C++17 support
- [SFML 2.6.1](https://www.sfml-dev.org/download/sfml/2.6.1/) — use **SFML 2.x**, not SFML 3 (breaking API changes)
- [CMake 3.16+](https://cmake.org/download/)

---

### Windows (VS Code + MinGW)

**1. Install SFML 2.6.1**

Download the **GCC SEH 64-bit** package from https://www.sfml-dev.org/download/sfml/2.6.1/ and extract it to `C:\SFML-2.6.1`.

**2. Clone and configure**

```bash
git clone https://github.com/your-username/path-finding.git
cd path-finding
cmake -B build -G "MinGW Makefiles" -DSFML_DIR="C:/SFML-2.6.1/lib/cmake/SFML"
```

**3. Build**

```bash
cmake --build build
```

**4. Copy SFML DLLs**

```bash
copy "C:\SFML-2.6.1\bin\sfml-graphics-2.dll" build\
copy "C:\SFML-2.6.1\bin\sfml-window-2.dll" build\
copy "C:\SFML-2.6.1\bin\sfml-system-2.dll" build\
copy "C:\SFML-2.6.1\bin\sfml-graphics-d-2.dll" build\
copy "C:\SFML-2.6.1\bin\sfml-window-d-2.dll" build\
copy "C:\SFML-2.6.1\bin\sfml-system-d-2.dll" build\
```

**5. Run**

```bash
.\build\PathFinding.exe
```

---

### macOS

```bash
brew install sfml@2 cmake
git clone https://github.com/your-username/path-finding.git
cd path-finding
cmake -B build
cmake --build build
./build/PathFinding
```

---

### Linux (Ubuntu/Debian)

```bash
sudo apt install libsfml-dev cmake build-essential
git clone https://github.com/your-username/path-finding.git
cd path-finding
cmake -B build
cmake --build build
./build/PathFinding
```

---

## Project Structure

```
src/
├── main.cpp             # Entry point
├── Engine.{h,cpp}       # Window, game loop, input, maze generation
├── Grid.{h,cpp}         # Grid state, wall painting, search reset
├── Map.{h,cpp}          # Grid dimensions and position constants
├── MapSquare.{h,cpp}    # Base class for all cell types
│   ├── Road             # Passable empty cell
│   ├── Wall             # Impassable barrier
│   ├── Start            # Source node
│   ├── Finish           # Target node
│   ├── SearchBlock      # Cell visited during search
│   └── Path             # Cell on the final found path
├── Algorithm.{h,cpp}    # Abstract algorithm base
│   ├── AStar.{h,cpp}    # A* with octile distance heuristic
│   ├── BFS.{h,cpp}      # Breadth-first search
│   └── DFS.{h,cpp}      # Depth-first search
├── Panel.{h,cpp}        # Button layout manager
├── Button.{h,cpp}       # Clickable UI button with label
└── Mode.{h,cpp}         # App state machine (pause / draw / play)
```

---

## License

[MIT](LICENSE.txt)

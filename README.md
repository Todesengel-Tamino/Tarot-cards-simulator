# Tarot Cards Simulator

A simple C++ program that draws 3 random Tarot cards with their orientations (upright or reversed).

## Overview

This program simulates a Tarot card draw by randomly selecting 3 cards from the full 78-card Tarot deck. Each card is displayed with its orientation:
- **Richtig rum** (Upright)
- **Auf dem Kopf** (Reversed)

### Card Distribution

The deck includes all 78 traditional Tarot cards:
- **22 Major Arcana** (Der Narr through Die Welt)
- **56 Minor Arcana**:
  - Wands/Staves (14 cards)
  - Cups (14 cards)
  - Swords (14 cards)
  - Coins/Pentacles (14 cards)

Each suit contains cards numbered Ace through Ten, plus four court cards (Page, Knight, Queen, King).

## Prerequisites

- **C++11 or later**
- A C++ compiler (GCC, Clang, or MSVC)
- CMake (optional, for easier building)

### Linux/macOS
```bash
# Install compiler (if not already installed)
# Ubuntu/Debian
sudo apt-get install g++

# macOS (using Homebrew)
brew install gcc
```

### Windows
- [Microsoft Visual C++ Build Tools](https://visualstudio.microsoft.com/downloads/)
- or [MinGW](https://www.mingw-w64.org/)
- or [GCC for Windows](https://gcc.gnu.org/install/windows.html)

## Compilation

### Method 1: Direct Compilation with g++

```bash
g++ -std=c++11 -o tarot tarot.cpp
```

Or with more optimization:
```bash
g++ -std=c++11 -O2 -o tarot tarot.cpp
```

### Method 2: Compilation with Clang

```bash
clang++ -std=c++11 -o tarot tarot.cpp
```

### Method 3: Using CMake (Optional)

Create a `CMakeLists.txt` file in your project directory:

```cmake
cmake_minimum_required(VERSION 3.10)
project(TarotSimulator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tarot tarot.cpp)
```

Then compile:
```bash
mkdir build
cd build
cmake ..
make
```

### Method 4: Windows with MSVC

```cmd
cl /EHsc /std:c++latest tarot.cpp
```

## Usage

After compilation, run the program:

### Linux/macOS
```bash
./tarot
```

### Windows
```cmd
tarot.exe
```

### Example Output
```
("Der Magier" Richtig rum) ("Fuenf der Schwerter" Auf dem Kopf) ("Koenigin der Kelche" Richtig rum)
```

## How It Works

1. **Deck Initialization**: All 78 cards are loaded into a vector and shuffled
2. **Card Selection**: The first 3 shuffled cards are selected (without replacement)
3. **Orientation**: Each card is randomly assigned an orientation (upright or reversed)
4. **Output**: The 3 cards are displayed with their names and orientations

## Code Structure

- **`kartenNamen`**: Array containing all 78 Tarot card names in German
- **`kartenName()`**: Function to retrieve a card name by its number (1-78)
- **`zustandText()`**: Function to convert orientation state to readable text
- **`main()`**: Program entry point that handles shuffling and output

## Language

The program uses German for card names and descriptions:
- Major Arcana: Der Narr, Der Magier, etc.
- Suits: Stäbe (Wands), Kelche (Cups), Schwerter (Swords), Münzen (Coins)
- Orientations: Richtig rum (Upright), Auf dem Kopf (Reversed)

## License

This project is provided as-is for educational purposes.

## Author

Todesengel-Tamino

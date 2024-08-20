# Tic-Tac-Toe Game

This is a simple command-line Tic-Tac-Toe game implemented in C++. The game features a basic AI opponent and a user-friendly interface with a retro terminal game look.

## Features

- **Two-player mode**: Play against a friend or the computer.
- **AI opponent**: The AI uses basic strategy to play, making the game challenging.
- **Random starting player**: The game randomly selects whether the player or the AI goes first.
- **Clear and colorful terminal interface**: The game is displayed in an easy-to-read format with ASCII art and clear game status updates.

## Getting Started

### Prerequisites

You need a C++ compiler to build and run the game. This can be installed on various platforms:

- **Windows**: Use MinGW or Visual Studio.
- **macOS**: Use Xcode Command Line Tools (`g++`).
- **Linux**: Use `g++` (install via your package manager).

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/mazzara/tic-tac-toe.git
   ```

2. **Navegate to project folder**:
   ```bash
   cd tic-tac-toe/src
   ```
3. **Compile the game**:
   ```bash
    g++ -std=c++11 -o tictactoe main.cpp
   ```

4. **Run the game**:
   ```bash
   ./tictactoe
   ```

## How to Play
1. The game will display the board, and you will be prompted to make a move by entering a number corresponding to a cell.
2. The AI will "think" before making its move, displaying dots to indicate it is processing.
3. The game alternates between player and AI turns until there is a winner or the board is full.

## Project Structure
1. src/: Contains the C++ source code for the game (main.cpp).
2. README.md: This file, containing information about the project.
3. .gitignore: Specifies which files and directories Git should ignore.

## License
This project is licensed under the MIT License.

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request.

## Acknowledgments
ASCII art generated using various online tools.
Inspired by classic Tic-Tac-Toe games.

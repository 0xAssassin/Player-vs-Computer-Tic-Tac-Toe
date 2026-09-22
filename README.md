# Tic-Tac-Toe Game in C

A simple **Player vs Computer Tic-Tac-Toe game** written in C.

This project is an extension of a basic two-player Tic-Tac-Toe game and introduces **random computer moves** using the C standard library.

## 🎮 How the Game Works

The game uses a 3×3 board with positions numbered from **1 to 9**:

```text
 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9
```

* **Player** uses `O`
* **Computer** uses `X`
* The player enters a position from **1 to 9**
* The computer selects a position randomly
* An occupied position cannot be selected
* The game checks for a winner after every move
* If all positions are filled without a winner, the game ends in a draw

## 🧠 Concepts Used

* Arrays
* Pointers
* Functions
* `if-else` conditions
* `while` loop
* `scanf()` and `getchar()`
* `rand()` and `srand()`
* `time()`
* Array indexing
* Input validation
* Win detection
* Draw detection

## 🎲 Random Computer Moves

The computer generates a random number between **1 and 9**:

```c
comp = (rand() % 9) + 1;
```

The random number is seeded using:

```c
srand(time(0));
```

This allows the computer to choose different positions across different game runs.

## 📂 Main Functions

### `gameManual()`

Displays the position guide used for selecting board positions.

### `printBoard(char *arr[])`

Displays the current Tic-Tac-Toe board.

### `playerChance(char *arr[], int *player)`

Validates the player's selected position and places `O` on the board.

### `compChance(char *arr[], int *comp)`

Checks whether the computer's randomly selected position is available and places `X` on the board.

### `printOutput(char *arr[])`

Clears the console and displays the updated game board.

### `win(char *arr[])`

Checks all possible winning combinations and determines whether the game has been won or drawn.

## ▶️ How to Run

Compile the program using GCC:

```bash
gcc tic_tac_toe.c -o tic_tac_toe
```

Run the program:

```bash
tic_tac_toe
```

On Windows:

```bash
tic_tac_toe.exe
```

## 📌 Example

```text
Player turn: 5

Computer turn...

  X |   |  
---|---|---
    | O |  
---|---|---
    |   | X
```

The computer automatically selects an available position after the player's turn.

## 🚀 Future Improvements

* Smarter computer opponent
* Easy, Medium, and Hard difficulty levels
* Score tracking
* Replay option
* Better input validation
* Cross-platform screen clearing
* Colored terminal interface

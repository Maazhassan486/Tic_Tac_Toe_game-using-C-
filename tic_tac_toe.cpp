#include <iostream>
#include <string>
using namespace std;

// Class representing a game participant
class Participant {
private:
    char token;
    string label;
public:
    // Constructor with default values
    Participant(char t = 'X', string l = "Player 1") : token(t), label(l) {}

    // Accessors
    char getToken() const { return token; }
    string getLabel() const { return label; }
};

// Class representing the game grid
class Grid {
private:
    char board[3][3];
    int occupiedCount; // Number of cells occupied
public:
    // Default constructor: initialize board with empty spaces
    Grid() : occupiedCount(0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    // Render the board to the console
    void render() const {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }

    // Check if a move is valid (cell in bounds and empty)
    bool moveIsValid(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    // Place a token at the specified position
    void placeToken(int row, int col, char token) {
        if (moveIsValid(row, col)) {
            board[row][col] = token;
            occupiedCount++;
        }
    }

    // Check if the given token has a winning configuration
    bool hasWon(char token) const {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == token && board[i][1] == token && board[i][2] == token)
                return true;
        }
        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == token && board[1][j] == token && board[2][j] == token)
                return true;
        }
        // Check diagonals
        if (board[0][0] == token && board[1][1] == token && board[2][2] == token)
            return true;
        if (board[0][2] == token && board[1][1] == token && board[2][0] == token)
            return true;
        return false;
    }

    // Check if all cells are occupied
    bool isFull() const {
        return occupiedCount == 9;
    }
};

// Class managing the overall game logic
class GameBoard {
private:
    Grid grid;
    Participant players[2];
    int currentPlayerIndex;
public:
    // Constructor initializing two players and starting with the first player
    GameBoard() : currentPlayerIndex(0) {
        players[0] = Participant('X', "Player 1");
        players[1] = Participant('O', "Player 2");
    }

    // Return a reference to the active player
    Participant & activePlayer() {
        return players[currentPlayerIndex];
    }

    // Toggle to the next player's turn
    void changeTurn() {
        currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    }

    // Main game loop
    void startGame() {
        int row, col;
        cout << "Welcome to Tic Tac Toe!" << endl;
        while (!grid.isFull()) {
            grid.render();
            Participant & current = activePlayer();
            
            // Input loop until a valid move is entered
            while (true) {
                cout << current.getLabel() << " (" << current.getToken() << "), enter row (1-3) and column (1-3): ";
                cin >> row >> col;
                row--; col--; // Convert to 0-based index
                if (grid.moveIsValid(row, col)) {
                    break;
                } else {
                    cout << "Invalid move. Please try again." << endl;
                }
            }
            
            // Place the token and check for a win
            grid.placeToken(row, col, current.getToken());
            if (grid.hasWon(current.getToken())) {
                grid.render();
                cout << current.getLabel() << " wins the game!" << endl;
                return;
            }
            changeTurn();
        }
        // If the board is full and no winner, it's a draw
        grid.render();
        cout << "The game ends in a draw!" << endl;
    }
};

int main() {
    GameBoard game;
    game.startGame();
    return 0;
}

#include <iostream>
using namespace std;

char board[3][3];   // 2D Array
char currentPlayer;

// Function to initialize board
void initializeBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++) {          // Nested loop
        for (int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

// Function to display board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check win
bool checkWin() {
    // Rows & Columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to check draw
bool checkDraw(int moves) {
    return (moves == 9);
}

// Function to make move
bool makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

// Game logic
void playGame() {
    int choice, moves = 0;
    bool win = false;

    initializeBoard();
    currentPlayer = 'X';

    while (!win && !checkDraw(moves)) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter position (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9 || !makeMove(choice)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        moves++;

        if (checkWin()) {
            win = true;
            displayBoard();
            cout << "?? Player " << currentPlayer << " Wins!\n";
            return;
        }

        switchPlayer();
    }

    displayBoard();
    cout << "?? It's a Draw!\n";
}

// Main Menu
void menu() {
    int choice;

    do {
        cout << "\n===== TIC TAC TOE MENU =====\n";
        cout << "1. Play Game\n";
        cout << "2. Instructions\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                playGame();
                break;

            case 2:
                cout << "\n--- Instructions ---\n";
                cout << "Players take turns entering numbers (1-9).\n";
                cout << "First to align 3 marks wins.\n";
                break;

            case 3:
                cout << "Exiting game...\n";
                break;

            default:
                cout << "Invalid option!\n";
        }

    } while (choice != 3);
}

// Main function
int main() {
    menu();
    return 0;
}

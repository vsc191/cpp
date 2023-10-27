#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void TicTacToe::play() {
    int row, col;

    while (true) {
        printBoard();
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;

            if (isGameWon(currentPlayer)) {
                printBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            } else if (isBoardFull()) {
                printBoard();
                std::cout << "It's a draw!" << std::endl;
                break;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }
}

bool TicTacToe::isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

bool TicTacToe::isGameWon(char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool TicTacToe::isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void TicTacToe::printBoard() {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
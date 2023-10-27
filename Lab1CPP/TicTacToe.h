#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
public:
    TicTacToe();
    void play();
    bool isBoardFull();
    bool isGameWon(char player);
    void printBoard();

private:
    char board[3][3];
    char currentPlayer;

    bool isValidMove(int row, int col);
};

#endif

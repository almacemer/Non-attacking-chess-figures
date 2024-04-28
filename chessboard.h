#ifndef CHESSBOARD_H_INCLUDED
#define CHESSBOARD_H_INCLUDED

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

enum Figure {
    NO_FIGURE,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    KING
};

class Chessboard {
public:
    int N;
    int figures_num;
    vector<vector<Figure>> board;
    vector<Figure> figures;

    Chessboard(int board_size = 8, int figures_num = 0): N(board_size), figures_num(figures_num) {
        board = vector<vector<Figure>>(N, vector<Figure>(N, NO_FIGURE));
    }

    Chessboard(int board_size, int figures_num, vector<Figure> figures): N(board_size), figures_num(figures_num), figures(figures.begin(), figures.end()) {
        board = vector<vector<Figure>>(N, vector<Figure>(N, NO_FIGURE));
    }

    void printBoard();

    bool attackByQueen(int row, int col);
    bool attackByKing(int row, int col);
    bool attackByKnight(int row, int col);
    bool attackByRook(int row, int col);
    bool attackByBishop(int row, int col);

    bool isSafe(int row, int col, Figure figure);

    bool solve(int next_figure = 0);
    bool solveWithOptimization(int next_figure = 0, int row = 0);
};

#endif // CHESSBOARD_H_INCLUDED

#include "chessboard.h"

void Chessboard::printBoard(){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

bool Chessboard::attackByQueen(int row, int col) {
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == QUEEN || board[i][col] == QUEEN)
            return true;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == QUEEN)
            return true;
    }
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j] == QUEEN)
            return true;
    }
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == QUEEN)
            return true;
    }
    for (int i = row, j = col; i < N && j < N; ++i, ++j) {
        if (board[i][j] == QUEEN)
            return true;
    }
    return false;
}

bool Chessboard::attackByKing(int row, int col) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int new_row = row + i;
            int new_col = col + j;
            if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N) {
                if (board[new_row][new_col] == KING)
                    return true;
            }
        }
    }
    return false;
}

bool Chessboard::attackByKnight(int row, int col) {
    vector<int> dx {2, 2, 1, -1, -2, -2, -1, 1};
    vector<int> dy {1, -1, -2, -2, -1, 1, 2, 2};

    for (int i = 0; i < 8; i++) {
        int new_x = row + dx[i];
        int new_y = col + dy[i];

        if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {
            if (board[new_x][new_y] == KNIGHT)
                return true;
        }
    }
    return false;
}

bool Chessboard::attackByRook(int row, int col) {
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == ROOK || board[i][col] == ROOK)
            return true;
    }
    return false;
}

bool Chessboard::attackByBishop(int row, int col) {
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == BISHOP)
            return true;
    }
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j] == BISHOP)
            return true;
    }
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == BISHOP)
            return true;
    }
    for (int i = row, j = col; i < N && j < N; ++i, ++j) {
        if (board[i][j] == BISHOP)
            return true;
    }
    return false;
}


bool Chessboard::isSafe(int row, int col, Figure figure) {
    switch (figure) {
        case QUEEN: {
            for (int i = 0; i < N; ++i) {
                if (board[row][i] != NO_FIGURE || board[i][col] != NO_FIGURE)
                    return false;
            }
            for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
                if (board[i][j] != NO_FIGURE)
                    return false;
            }
            for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
                if (board[i][j] != NO_FIGURE)
                    return false;
            }
            for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
                if (board[i][j] != NO_FIGURE)
                    return false;
            }
            for (int i = row, j = col; i < N && j < N; ++i, ++j) {
                if (board[i][j] != NO_FIGURE)
                    return false;
            }
        } break;
        case ROOK: {
            if (attackByQueen(row, col))
                return false;
            for (int i = 0; i < N; ++i) {
                if (board[row][i] != NO_FIGURE || board[i][col] != NO_FIGURE)
                return false;
            }
        }
        case BISHOP: {
            if (attackByQueen(row, col) || attackByRook(row, col))
                return false;
            for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
                if (board[i][j] != NO_FIGURE)
                    return false;
            }
            for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
                if (board[i][j] != NO_FIGURE)
                    return false;
            }
            for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
                if (board[i][j] != NO_FIGURE)
                    return false;
            }
            for (int i = row, j = col; i < N && j < N; ++i, ++j) {
                if (board[i][j] != NO_FIGURE)
                    return false;
            }
        } break;
        case KNIGHT: {
            if (attackByQueen(row, col) || attackByRook(row, col) || attackByBishop(row, col))
                return false;
            vector<int> dx {2, 2, 1, -1, -2, -2, -1, 1};
            vector<int> dy {1, -1, -2, -2, -1, 1, 2, 2};
            for (int i = 0; i < 8; i++) {
                int new_x = row + dx[i];
                int new_y = col + dy[i];
                if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {
                    if (board[new_x][new_y] != NO_FIGURE)
                        return false;
                }
            }
        } break;
        case KING: {
            if (attackByQueen(row, col) || attackByRook(row, col) || attackByBishop(row, col) || attackByKnight(row, col))
                return false;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int new_row = row + i;
                    int new_col = col + j;
                    if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N) {
                        if (board[new_row][new_col] != NO_FIGURE)
                            return false;
                    }
                }
            }
        } break;
    }
    return true;
}

bool Chessboard::solve(int next_figure) {
    if (next_figure >= figures_num)
        return true;

    Figure figure = figures[next_figure];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == NO_FIGURE && isSafe(i, j, figure)) {
                board[i][j] = figure;
                if (solve(next_figure + 1))
                     return true;
                board[i][j] = NO_FIGURE;
             }
        }
    }

    return false;
}

bool Chessboard::solveWithOptimization(int next_figure, int row) {
    if (next_figure >= figures_num)
        return true;

    Figure figure = figures[next_figure];
    for (int i = row; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == NO_FIGURE && isSafe(i, j, figure)) {
                board[i][j] = figure;
                int next_row = i;
                if(next_figure + 1 < figures_num && figure != figures[next_figure + 1]){
                    next_row = 0;
                }

                if (solveWithOptimization(next_figure + 1, next_row))
                    return true;
                board[i][j] = NO_FIGURE;
            }
        }
    }

    return false;
}

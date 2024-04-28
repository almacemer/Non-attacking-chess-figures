#include <chrono>
#include "chessboard.h"

int main() {
    int n, queens, rooks, bishops, knights, kings;
    cout<<"Enter size of board: ";
    cin>>n;
    cout<<"Enter the number of each figure (queen - 1, rook - 2, bishop - 3, knight - 4, king - 5): ";
    cin>>queens>>rooks>>bishops>>knights>>kings;

    int figures_num = queens + rooks + bishops + knights + kings;

    Chessboard cb(n, figures_num);
    Chessboard cb2(n, figures_num);

    for (int i = 0; i < queens; ++i) {
        cb.figures.push_back(QUEEN);
        cb2.figures.push_back(QUEEN);
    }
    for (int i = 0; i<rooks; ++i) {
        cb.figures.push_back(ROOK);
        cb2.figures.push_back(ROOK);
    }
    for (int i = 0; i<bishops; ++i) {
        cb.figures.push_back(BISHOP);
        cb2.figures.push_back(BISHOP);
    }
    for (int i = 0; i<knights; ++i) {
        cb.figures.push_back(KNIGHT);
        cb2.figures.push_back(KNIGHT);
    }
    for (int i = 0; i<kings; ++i) {
        cb.figures.push_back(KING);
        cb2.figures.push_back(KING);
    }

    chrono::steady_clock::time_point t_begin, t_end;

    t_begin = chrono::steady_clock::now();
    if (cb.solveWithOptimization()) {
        t_end = chrono::steady_clock::now();
        cout<<"Solution found (solver with optimization):"<<endl;
        cb.printBoard();
        cout<<"Time: "<<chrono::duration_cast<chrono::milliseconds>(t_end-t_begin).count()/1000.<<"s"<<endl;
    } else {
        t_end = chrono::steady_clock::now();
        cout<<"No solution found (solver with optimization)."<<endl;
        cout<<"Time: "<<chrono::duration_cast<chrono::milliseconds>(t_end-t_begin).count()/1000.<<"s"<<endl;
    }

    t_begin = chrono::steady_clock::now();
    if (cb2.solve()) {
        t_end = chrono::steady_clock::now();
        cout<<"Solution found:"<<endl;
        cb2.printBoard();
        cout<<"Time: "<<chrono::duration_cast<chrono::milliseconds>(t_end-t_begin).count()/1000.<<"s"<<endl;
    } else {
        t_end = chrono::steady_clock::now();
        cout<<"No solution found."<<endl;
        cout<<"Time: "<<chrono::duration_cast<chrono::milliseconds>(t_end-t_begin).count()/1000.<<"s"<<endl;
    }

    return 0;
}

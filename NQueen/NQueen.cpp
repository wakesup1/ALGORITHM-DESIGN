#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> board;
int ans = 0;

bool check(int row, int col) {
    for (int i = 0; i < board.size();i++){
        if (board[i][col] == 1) return false;
        if (board[row][i] == 1) return false;
    }

    for (int i = 0, j = 0; row - i >= 0 && col - j >= 0; i++, j++) {
        if (board[row - i][col - i] == 1) return false;
    }

    for (int i = 0, j = 0; row - i >= 0 && col + j < board.size(); i++, j++) {
        if (board[row - i][col + i] == 1) return false;
    }
    return true;
}

void solve(int row, int queen) {
    if (row < board.size()) {
        for (int k = 0; k < board.size(); k ++) {
            if(check(row,k)) {
                board[row][k] = 1;
                solve(row+1,queen+1);
                board[row][k] = 0;
            }
        }
    } else if (queen == board.size()) { ans+=1;}
}

int main () {
    int n;
    cin >> n;
    board.resize(n);
    for (auto&x:board) x.resize(n);
    solve(0,0);
    for (auto&x:board) {
        for (auto&y:x ) {
            cout << y << ' ';
        }
        cout <<endl;
    }
    cout << ans;
}

/*
    Q...
    ..Q..



*/
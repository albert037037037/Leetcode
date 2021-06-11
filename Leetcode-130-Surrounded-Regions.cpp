/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/surrounded-regions/
 * runtime: 12ms
 */

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        pair<int, int> tmp;
        int r = board.size();
        int c = board[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if((i == 0 || j == 0 || i == r-1 || j == c-1) && board[i][j] == 'O' ){
                    board[i][j] = 'M';
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            tmp = q.front(); q.pop();
            find(tmp.first, tmp.second, r, c, board);
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'M') board[i][j] = 'O';
            }
        }
    }
    void find(int i, int j, int r, int c, vector<vector<char>>& board){
        if(i+1 < r && board[i+1][j] == 'O'){
            board[i+1][j] = 'M';
            find(i+1, j, r, c, board);
        }
        if(i-1 >= 0 && board[i-1][j] == 'O'){
            board[i-1][j] = 'M';
            find(i-1, j, r, c, board);
        }
        if(j+1 < c && board[i][j+1] == 'O'){
            board[i][j+1] = 'M';
            find(i, j+1, r, c, board);
        }
        if(j-1 >= 0 && board[i][j-1] == 'O'){
            board[i][j-1] = 'M';
            find(i, j-1, r, c, board);
        }
    }
};
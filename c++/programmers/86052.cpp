#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char board[500][500];
int moves[500][500];
int row, column;
int mx[4] = {-1,0,1,0};
int my[4] = {0,1,0,-1};

int find(int start_x, int start_y, int start_d){
    int x = start_x;
    int y = start_y;
    int d = start_d;
    int count = 0;
    while((moves[x][y] &(1<<d)) != (1<<d)){
        count ++;
        moves[x][y] = (moves[x][y] | (1<<d));
        if(board[x][y]=='L')
            d = (d+3)%4;
        else if(board[x][y]=='R')
            d = (d+1)%4;
        x = x+mx[d];
        y = y+my[d];
        if(x<0)
            x = row-1;
        else if(x>=row)
            x = 0;
        if(y<0)
            y = column-1;
        else if(y>=column)
            y = 0;
    }
    if(x==start_x && y==start_y && d== start_d)
        return count;
    else
        return -1;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    row = grid.size();
    column = grid[0].size();
    
    for(int i=0; i<row; i++)
        for(int j=0; j<column; j++)
            board[i][j] = grid[i][j];
    int res = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if((moves[i][j] & 1) != 1){
                res = find(i,j,0);
                if(res != -1){
                    answer.push_back(res);
                }
            }
            if((moves[i][j] & 2) != 2){
                res = find(i,j,1);
                if(res != -1){
                    answer.push_back(res);
                }
            }
            if((moves[i][j] & 4) != 4){
                res = find(i,j,2);
                if(res != -1){
                    answer.push_back(res);
                }
            }
            if((moves[i][j] & 8) != 8){
                res = find(i,j,3);
                if(res != -1){
                    answer.push_back(res);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
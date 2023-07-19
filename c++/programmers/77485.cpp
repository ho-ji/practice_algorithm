#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int board[rows+1][columns+1];
    int a = 1;
    for(int i=1; i<=rows; i++){
        for(int j=1; j<= columns; j++){
            board[i][j] = a++;
        }
    }
    
    for(int i=0; i< queries.size(); i++){
        int res = a;
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        
        int move = board[x1][y1];
        res = min(res,move);
        int tmp;
        for(int y=y1+1; y<=y2; y++){
            tmp = board[x1][y];
            board[x1][y] = move;
            move = tmp;
            res = min(res,move);
        }
        for(int x=x1+1; x<=x2; x++){
            tmp = board[x][y2];
            board[x][y2] = move;
            move = tmp;
            res = min(res,move);
        }
        for(int y=y2-1; y>=y1; y--){
            tmp = board[x2][y];
            board[x2][y] = move;
            move = tmp;
            res = min(res,move);
        }
        for(int x=x2-1; x>=x1; x--){
            tmp = board[x][y1];
            board[x][y1] = move;
            move = tmp;
            res = min(res,move);
        }
        
        answer.push_back(res);
    }
    return answer;
}
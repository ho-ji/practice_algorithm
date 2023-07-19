#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    pair<int, int> pos_robot;
    
    int rowN = board.size();
    int colN = board[0].size();
    
    for(int i=0; i<rowN; i++){
        for(int j=0; j<colN; j++){
            if(board[i][j] == 'R'){
                pos_robot = make_pair(i, j);
                board[i][j] = 'c';
                break;
            }
        }
    }
    
    queue <pair<int,int>> list;
    queue <int> count;
    
    list.push(pos_robot);
    count.push(0);
    
    int moves[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    while(!list.empty()){
        int x = list.front().first;
        int y = list.front().second;
        int n = count.front();
        
        for(int i=0; i<4; i++){
            while(x+moves[i][0] >= 0 && x+ moves[i][0] < rowN && y+moves[i][1] >= 0 && y+moves[i][1]<colN && board[x+moves[i][0]][y+moves[i][1]] !='D'){
                x += moves[i][0];
                y += moves[i][1];
            }
        
        if(x != list.front().first || y != list.front().second){
            if(board[x][y] == 'G'){
                answer = n + 1;
                return answer;
            }
            if(board[x][y] != 'C'){
                list.push(make_pair(x,y));
                count.push(n+1);
                board[x][y] = 'C';
            }
            x = list.front().first;
            y = list.front().second;
        }
        }
        list.pop();
        count.pop();
    }
    return answer;
}
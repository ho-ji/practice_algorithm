#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size();
    vector<int> pos(size+1,-1);
    stack<int> s;
    int cnt = 0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(pos[j] == -1&&board[i][j] !=0){
                pos[j] = i;
                ++cnt;
            }
        }
        if(cnt == size)
            break;
    }
    for(int i=0; i<moves.size(); i++){
        int m = moves[i] -1;
        if(pos[m] != -1){
            if(s.empty())
                s.push(board[pos[m]][m]);
            else{
                if(s.top() == board[pos[m]][m]){
                    s.pop();
                    answer +=2;
                }
                else
                    s.push(board[pos[m]][m]);
            }
            pos[m]++;
            if(pos[m]==size)
                pos[m] = -1;
        }
    }
    return answer;
}
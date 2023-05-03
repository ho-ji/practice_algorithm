#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    int cntO = 0, cntX = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == 'O')
                cntO++;
            else if(board[i][j] == 'X')
                cntX++;
        }
    }
    if(cntO != cntX && cntO != cntX + 1)
        return 0;
    
    int winO = 0, winX = 0;
      
    for(int i=0; i<3; i++){
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
        if(board[i][0] == 'O')
          winO++;
        else if(board[i][0] == 'X')
          winX++;
      }
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
        if(board[0][i] == 'O')
          winO++;
        else if(board[0][i] == 'X')
          winX++;
      }
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
      if(board[0][0] == 'O')
        winO++;
      else if(board[0][0] == 'X')
        winX++;
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
      if(board[0][2] == 'O')
        winO++;
      else if(board[0][2] == 'X')
        winX++;
    }
    
    if(winX !=0 && winO != 0)
        return 0;
    if(winO != 0 && cntO == cntX)
        return 0;
    if(winX != 0 && cntO == cntX + 1)
        return 0;
    
    return 1;
}
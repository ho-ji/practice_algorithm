#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<vector<string>> board(100,vector<string>(51, "EMPTY"));
vector<vector<pair<int,int>>> parent(51,vector<pair<int,int>>(51));

void updatePosition(int x, int y, string v){
  board[parent[x][y].first][parent[x][y].second] = v;
}
void updateValue(string prevV, string nextV){
  for(int i=1; i<51; i++){
    for(int j=1; j<51; j++){
      if(board[i][j] == prevV){
        board[i][j] = nextV;
      }
    }
  }
}

void mergeCell(int x1, int y1, int x2, int y2){
  pair<int, int> r1 = parent[x1][y1];
  pair<int, int> r2 = parent[x2][y2];
  if(r1 == r2){
    return;
  }
  if(board[r1.first][r1.second] == "EMPTY" ){
    for(int i=1; i<51; i++){
      for(int j=1; j<51; j++){
        if(parent[i][j] == r1){
          parent[i][j] = r2;
        }
      }
    }
  }//앞의 값이 비어있을때
  else{
    for(int i=1; i<51; i++){
      for(int j=1; j<51; j++){
        if(parent[i][j] == r2){
          parent[i][j] = r1;
        }
      }
    }
  }
}
void unmergeCell(int x, int y){
  string v = board[parent[x][y].first][parent[x][y].second];
  pair<int,int> p = parent[x][y];
  for(int i=1; i<51; i++){
    for(int j=1; j<51; j++){
      if(parent[i][j] == p){
        board[i][j] = "EMPTY";
        parent[i][j] = make_pair(i,j);
      }
    }
  }
  board[x][y] = v;
}
string printCell(int x, int y){
  return board[parent[x][y].first][parent[x][y].second];
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(int i=1; i<51; i++){
      for(int j=1; j<51; j++){
        parent[i][j] = make_pair(i,j);
      }
    }
    for(auto command : commands){
      vector<string> cmd;
      string cmdBuffer = ""; 
      istringstream ss(command);
      while(getline(ss, cmdBuffer,' ')){
        cmd.push_back(cmdBuffer);
      }
      if(cmd[0] == "UPDATE"){
        if(cmd.size() == 4)
          updatePosition(stoi(cmd[1]),stoi(cmd[2]), cmd[3]);
        else
          updateValue(cmd[1], cmd[2]);
      }
      else if(cmd[0] == "MERGE"){
        mergeCell(stoi(cmd[1]),stoi(cmd[2]),stoi(cmd[3]),stoi(cmd[4]));
      }
      else if(cmd[0] == "UNMERGE"){
        unmergeCell(stoi(cmd[1]),stoi(cmd[2]));
      }
      else if(cmd[0] == "PRINT"){
        answer.push_back(printCell(stoi(cmd[1]),stoi(cmd[2])));
      }
    }
    return answer;
}
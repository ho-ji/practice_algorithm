#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<vector<string>> board(51,vector<string>(51, "EMPTY"));

void updatePosition(int x, int y, string v){
  if(board[x][y] == "EMPTY"){
    board[x][y] = v;
    return;
  }
  if(board[x][y][0] == 'M'){
    int n1 = stoi(board[x][y].substr(1,2));
    int n2 = stoi(board[x][y].substr(3));
    board[n1][n2] = "R" + v;
  }
  if(board[x][y][0] == 'R'){
    board[x][y] = "R" + v;
    return;
  }
}
void updateValue(string prevV, string nextV){
  for(int i=1; i<51; i++){
    for(int j=1; j<51; j++){
      if(board[i][j] == prevV){
        board[i][j] = nextV;
      }
      else if(board[i][j] == "R"+ prevV){
        board[i][j] = "R" + nextV;
      }
    }
  }
}

void mergeCell(int x1, int y1, int x2, int y2){
  if(x1 == x2 && y1 == y2){
    return ;
  }
  if(board[x1][y1] == "EMPTY"){
    if(board[x2][y2][0] == 'M'){
      board[x1][y1] = board[x2][y2];
    }
    else if(board[x2][y2] == "EMPTY"){
      board[x2][y2] = "M";
      board[x2][y2] += x1<10? "0" + to_string(x1) : to_string(x1);
      board[x2][y2] += y1<10? "0" + to_string(y1) : to_string(y1); 
      board[x1][y1] = "REMPTY";
    }
    else{
      board[x1][y1] = "M";
      board[x1][y1] += x2<10? "0" + to_string(x2) : to_string(x2);
      board[x1][y1] += y2<10? "0" + to_string(y2) : to_string(y2);
      if(board[x2][y2][0] != 'R'){
        board[x2][y2] = 'R' + board[x2][y2];
      }
    }
  }
  else{
    string toChange = "", toFind ="";
    if(board[x1][y1][0] == 'M'){
      int n1 = stoi(board[x1][y1].substr(1,2));
      int n2 = stoi(board[x1][y1].substr(3));
      if(board[x2][y2][0] == 'M'){
        if(board[n1][n2] == "REMPTY"){
          toChange = board[x2][y2];
          toFind = board[x1][y1];
          updateValue(toFind, toChange);
          board[n1][n2] = toChange;
        }
        else{
          int m1 = stoi(board[x2][y2].substr(1,2));
          int m2 = stoi(board[x2][y2].substr(3));
          board[m1][m2] = board[x1][y1];
          toFind = board[x2][y2];
          updateValue(toFind, board[x1][y1]);
        }
      }
      else{
        if(board[n1][n2] == "REMPTY"){
          toChange = "M";
          toChange += x2<10? "0" + to_string(x2) : to_string(x2);
          toChange += y2<10? "0" + to_string(y2) : to_string(y2);
          toFind = board[x1][y1];
          updateValue(toFind, toChange);
          board[n1][n2] = toChange;
        }
        else{
          toFind = "M";
          toFind += x2<10? "0" + to_string(x2) : to_string(x2);
          toFind += y2<10? "0" + to_string(y2) : to_string(y2);
          updateValue(toFind, board[x1][y1]);
          board[x2][y2] = board[x1][y1];
        }
      }
    }
    else{
      if(board[x1][y1] == "REMPTY"){
        toFind = "M";
        toFind += x1<10? "0" + to_string(x1) : to_string(x1);
        toFind += y1<10? "0" + to_string(y1) : to_string(y1);
        if(board[x2][y2][0] == 'M'){
          toChange = board[x2][y2];
        }
        else{
          toChange = "M";
          toChange += x2<10? "0" + to_string(x2) : to_string(x2);
          toChange += y2<10? "0" + to_string(y2) : to_string(y2);
          if(board[x2][y2][0] != 'R'){
            board[x2][y2] = "R"+ board[x2][y2];
          }
        }
        updateValue(toFind, toChange);
        board[x1][y1] = toChange;
      }
      else{
        toChange = "M";
        toChange += x1<10? "0" + to_string(x1) : to_string(x1);
        toChange += y1<10? "0" + to_string(y1) : to_string(y1);
        if(board[x2][y2][0] == 'M'){
          toFind = board[x2][y2];
          int m1 = stoi(board[x2][y2].substr(1,2));
          int m2 = stoi(board[x2][y2].substr(3));
          board[m1][m2] = toChange;
          updateValue(toFind,toChange);
        }
        else if(board[x2][y2][0] == 'R'){
          toFind = "M";
          toFind += x2<10? "0" + to_string(x2) : to_string(x2);
          toFind += y2<10? "0" + to_string(y2) : to_string(y2);
          board[x2][y2] = toChange;
          updateValue(toFind,toChange);
        }
        else{
          board[x2][y2] = toChange;
        }
        if(board[x1][y1][0] != 'R'){
          board[x1][y1] = "R" +board[x1][y1];
        } 
      }
    }
  }
}
void unmergeCell(int x, int y){
  string toFind ="";
  if(board[x][y][0] == 'R'){
    toFind = "M";
    toFind += x<10? "0" + to_string(x) : to_string(x);
    toFind += y<10? "0" + to_string(y) : to_string(y);
    updateValue(toFind,"EMPTY");
    board[x][y] = board[x][y];
  }
  else if(board[x][y][0] == 'M'){
    toFind = board[x][y];
    int n1 = stoi(board[x][y].substr(1,2));
    int n2 = stoi(board[x][y].substr(3));
    board[x][y] = board[n1][n2];
    board[x][y] = board[x][y];
    board[n1][n2] = "EMPTY";
    updateValue(toFind, "EMPTY");
  }
}
string printCell(int x, int y){
  string result ="";
  if(board[x][y][0] == 'M'){
    int n1 = stoi(board[x][y].substr(1,2));
    int n2 = stoi(board[x][y].substr(3));
    result = board[n1][n2];
    result = result.substr(1);
  }
  else if(board[x][y][0] == 'R'){
    result = board[x][y].substr(1);
  }
  else{
    result = board[x][y];
  }
  return result;
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
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
      for(int i=1; i<5; i++){
        for(int j=1; j<5; j++)
          cout<< board[i][j] <<"|";
        cout << endl;
      }
      cout << endl << endl;
    }

    return answer;
}

int main(){
  vector<string> answer;
  answer = solution({"UPDATE 1 1 menu", "MERGE 1 1 1 2", "MERGE 1 1 1 3", "MERGE 1 1 1 4", "MERGE 1 2 1 3", "UPDATE 1 1 hansik", "PRINT 1 1", "PRINT 1 2", "PRINT 1 3", "PRINT 1 4"});

  for(auto a: answer){
     cout<< a << endl;
  }
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    vector <string> answerList;
    queue <string> dir;
    queue <pair<int,int>> pos;

    dir.push("");
    pos.push({x-1,y-1});

    int moves[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    char movesChar[4][1] = {{'d'},{'r'},{'u'},{'l'}};
    while(!pos.empty()){
      string s = dir.front();
      int nx = pos.front().first;
      int ny = pos.front().second;
      if(s.length() == k){
        if(nx == r-1 && ny == c-1){
          answerList.push_back(s);
        }
      }
      else{
        for(int i=0; i<4; i++){
          int mx = nx + moves[i][0];
          int my = ny + moves[i][1];
          string ns = s + movesChar[i][0];

          if(mx >=0 && mx < n && my >=0 && my < m){
            pos.push({mx,my});
            dir.push(ns);
          }
        }
      }
      pos.pop();
      dir.pop();
    }
    if(answerList.size() == 0){
      answer = "impossible";
    }
    else{
      sort(answerList.begin(), answerList.end());
      answer = answerList[0];
    }
    return answer;
}

int main(){
  string answer = solution(3,4,2,3,3,1,5);
  cout << answer << endl;
  return 0;
}
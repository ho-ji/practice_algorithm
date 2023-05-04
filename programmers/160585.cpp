#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Pos{
  int x;
  int y;
  int cnt;
  Pos(int a, int b, int c){
    x = a; y = b; cnt = c;
  }
};

int solution(vector<string> maps) {
    int answer = 0;
    Pos start(0,0,0), end(0,0,0);

    for(int i=0; i<maps.size(); i++){
      for(int j=0; j<maps[0].size(); j++){
        if(maps[i][j] == 'S'){
          start.x = i; start.y = j;
        }
        else if(maps[i][j] == 'E'){
          end.x = i; end.y = j;
        }
      }
    }

    queue<Pos> q;
    q.push(start);

    int moves[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    char ck = 'V';
    while(!q.empty()){
      int x = q.front().x;
      int y = q.front().y;
      int cnt = q.front().cnt;
      cout << x << " " << y << endl;

      for(int i=0; i<4; i++){
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        int ncnt = cnt + 1;
        if(nx>=0 && nx<maps.size() && ny>=0 && ny<maps[i].size() && maps[nx][ny] != 'X' && maps[nx][ny] != ck){
          if(maps[nx][ny] == 'L'){
            while(!q.empty()) q.pop();
            q.push(Pos(x,y,cnt));
            q.push(Pos(nx,ny,ncnt));
            ck = 'W';
          }
          else if(nx == end.x && ny == end.y && ck =='W'){
            return ncnt;
          }
          else{
            q.push(Pos(nx,ny,ncnt));
          }
          maps[nx][ny] = ck;
        }
      }
      q.pop();
    }    
    return -1;
}

int main() {
  vector<string> maps = 	{"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"};
  cout << solution(maps)<< endl;
  return 0;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
  string answer = "";
  int curX = x, curY = y;
  int leftDistance = abs(x-r) + abs(y-c);
  if(leftDistance > k || (k-leftDistance)%2 == 1){
    return "impossible";
  }

  int moves[2][2] = {{1,0}, {0,-1}}; // d l
  char moveChar[2] = {'d', 'l'};

  for(int i=0; i<2; i++){
    while(leftDistance < k){
      int nx = curX + moves[i][0];      
      int ny = curY + moves[i][1];
      if(nx > 0 && nx <= n && ny > 0 && ny<= m){
        curX = nx;
        curY = ny;
        leftDistance = abs(curX-r) + abs(curY-c);
        answer += moveChar[i];
        k--;
      }
      else{
        break;
      }    
    }
  }
  while(leftDistance < k){
    k-=2;
    answer += "rl";
  }
  while(curX < r){
    answer += 'd';
    curX++;
  }
  while(curY > c){
    answer += 'l';
    curY--;
  }
  while(curY < c){
    answer += 'r';
    curY++;
  }
  while(curX > r){
    answer += 'u';
    curX--;
  }
  return answer;
}
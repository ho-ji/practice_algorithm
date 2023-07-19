#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int main(){
	int n;
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};

	queue<pair<int,int>> q;

	int board[101][101];

	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> board[i][j];
		}
	}
	int tom_x, tom_y, jerry_x, jerry_y;

	cin >> tom_x >> tom_y;

	cin >> jerry_x >> jerry_y;

	board[tom_x][tom_y] = 2;

	q.push(make_pair(tom_x,tom_y));
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			int cnt =1;
			while(1){
				int nx = x + dx[i]*cnt;
				int ny = y + dy[i]*cnt;
				
				if(nx <=0 || nx > n || ny <=0 || ny > n || board[nx][ny] == 1) 
					break;
				else if(nx == jerry_x && ny == jerry_y){
					cout << board[x][y] - 2 << endl;
					return 0;
				}
				else{
					if(board[nx][ny] == 0){
						q.push(make_pair(nx,ny));
						board[nx][ny] = board[x][y] +1;
					}
				}
				cnt++;
			}
		}
	}

	cout << "-1" <<endl;
	return 0;
}

#include <iostream>

using namespace std;

int r, c, res;
char board[20][20];
bool ck[26];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void DFS(int x, int y, int cnt){
	res = max(cnt, res);
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=0 && nx<r && ny>=0 && ny<c && !ck[board[nx][ny]-'A']){
			ck[board[nx][ny]-'A'] = true;
			DFS(nx,ny,cnt+1);
			ck[board[nx][ny]-'A'] = false;
		}
	}
}

int main(){
	cin >> r >> c;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> board[i][j];
		}
	}

	ck[board[0][0] - 'A'] = true;
	DFS(0,0,1);

	cout << res;
	return 0;
}

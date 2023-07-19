#include <iostream>
#include <vector>

using namespace std;

int n, m, k, res = -1, cnt=0;
vector<vector <int>> board(102, vector<int>(102,0));

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void DFS(int x, int y){
	cnt++;
	board[x][y] = 0;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >0 && nx <= n && ny >0 && ny<=m && board[nx][ny] != 0)
			DFS(nx, ny);
	}
}

int main(){
	
	cin >> n >> m >> k;
	for(int i=0; i<k; i++){
		int a,b;
		cin >> a >> b;
		board[a][b] = 1;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(board[i][j] ==1){
				DFS(i,j);
				if(cnt > res)
					res = cnt;
				cnt = 0;
			}
		}
	}
	cout << res << endl;
}

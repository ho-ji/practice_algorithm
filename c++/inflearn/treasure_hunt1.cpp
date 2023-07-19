#include <iostream>
#include <queue>

using namespace std;

struct loc{
	int x;
	int y;
	int z;
	loc(int a, int b, int c){
		x =a;
		y =b;
		z =c;
	}
};

int main(){
	int n;

	cin >> n;

	int board[101][101], dis[101][101][3];
	queue<loc> q;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> board[i][j];
			dis[i][j][0] = -1;
			dis[i][j][1] = -1;
			dis[i][j][2] = -1;
		}
	}


	for(int i=0; i<3; i++){
		int a, b;
		cin >> a >> b;
		dis[a][b][i] = 0;
		q.push(loc(a,b,i));
	}
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	while(!q.empty()){
		int x= q.front().x;
		int y= q.front().y;
		int z= q.front().z;

		q.pop();
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>0 && nx<=n && ny>0 && ny<=n && board[nx][ny] != 1 && dis[nx][ny][z] == -1){
				dis[nx][ny][z] = dis[x][y][z] + 1;
				q.push(loc(nx,ny,z));
			}
		}
	}	
	int tmp = 10000;
	int cnt =0;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int a= dis[i][j][0];
			int b= dis[i][j][1];
			int c= dis[i][j][2];
			
			int k= max(a,max(b,c));
			
			if(a != -1 && b != -1 && c != -1){
				if(k < tmp){
					tmp = k;
					cnt = 1;
				}
				else if(k==tmp)
					cnt++;
			}
		}
	}
	if(cnt ==0)
		cout << -1 << endl;
	else
		cout << cnt << endl;

	return 0;
}

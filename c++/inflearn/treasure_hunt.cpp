#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos{
	int flag;
	int x;
	int y;
	pos(int a, int b, int c){
		flag = a;
		x = b;
		y = c;
	}
};

int main(){
	int n;
	cin >> n;
	
	queue<pos> q;
	vector<vector<int>> tmap(n+1, vector<int>(n+1));

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> tmap[i][j];
		}
	}

	int tmp =2;
	for(int i=0; i<3; i++){
		int a, b;
		cin >> a >> b;
		q.push(pos(tmp, a, b));
		tmap[a][b] = tmp;
		tmp = tmp*2;
	}
	int res = 0;

	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};

	while(!q.empty()){
		int s = q.size();
		for(int i=0; i<s; i++){
			int f = q.front().flag;
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for(int j=0; j<4; j++){
				int nx= x+dx[j];
				int ny= y+dy[j];
				if(nx>0 && nx<=n && ny>0 && ny<=n && tmap[nx][ny] != 1){ 
					if((tmap[nx][ny] & f) != f){
						tmap[nx][ny] = tmap[nx][ny] + f;
						q.push(pos(f,nx,ny));
				
						if(tmap[nx][ny] == 14)
							res ++;
					}
				}
			}
		}
		if(res != 0)
			break;
	}

	if(res == 0)
		cout << "-1" << endl;
	else
		cout << res << endl;
	return 0;
}

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int board[1001][1001], dis[2][1001][1001];


queue<pair<int, int>> Q;

int w, h;

void BFS(int index){
	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >=0 && nx < h && ny >=0 && ny < w && dis[index][nx][ny]==0){
				if(board[nx][ny] != 1){
					dis[index][nx][ny] = dis[index][x][y] +1;
					Q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int main(){
	
	pair<int,int> yh, knight;
	vector<pair<int,int>> sb;
	cin >> w >> h;

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> board[i][j];
			if(board[i][j] == 2)
				yh = make_pair(i,j);
			else if(board[i][j] == 3)
				knight = make_pair(i,j);
			else if(board[i][j] == 4)
				sb.push_back(make_pair(i,j));
		}
	}

	Q.push(yh);
	BFS(0);

	Q.push(knight);
	BFS(1);
	
	int min = INT_MAX;

	for(int i=0 ; i< sb.size(); i++){
		int a= sb[i].first;
		int b= sb[i].second;
		if(dis[0][a][b] != 0 && dis[1][a][b] != 0){
			if(min > dis[0][a][b] + dis[1][a][b])
				min = dis[0][a][b] + dis[1][a][b];
		}
	}

	cout << min << endl;

	return 0;
}


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct grass{
	int x;
	int y;
	int day;
	grass(int a, int b, int c){
		x = a;
		y = b;
		day = c;
	}
};

int main(){
	int n;
	cin >> n;

	vector<vector <int>> garden(n, vector<int>(n));
	queue<grass> list;
	int land_cnt = 0; 
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> garden[i][j];
			if(garden[i][j] == 2){
				list.push(grass(i,j,0));
			}
			else if(garden[i][j] == 0)
				land_cnt ++;
		}	
	}

	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int day = 0;
	while(!list.empty()){
		int x = list.front().x;
		int y = list.front().y;
		day = list.front().day;
		list.pop();
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx >=0 && nx < n && ny >=0 && ny < n && garden[nx][ny] == 0){
				garden[nx][ny] = 2;
				list.push(grass(nx,ny, day+1));
			}
		}
	}

	cout << day << endl;
	return 0;
}

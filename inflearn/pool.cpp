#include <iostream>
#include <vector>

using namespace std;

int main(){
	int r, c;

	cin >> r >> c;
	
	vector<vector <char>> stadium(r, vector<char>(c));
	vector<pair<int, int>> pool;

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> stadium[i][j];
			pool.push_back(make_pair(i,j));
		}
	}

	int cnt =0;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};

	for(int i=0; i<pool.size(); i++){
		int x= pool[i].first;
		int y= pool[i].second;
		if(stadium[x][y] == '#'){
			cnt++;
			stadium[x][y] = '.';
			for(int j=0; j<4; j++){
				if(x+dx[j] >=0 && x+dx[j]<r && y+dy[j] >=0 && y+dy[j]<c && stadium[x+dx[j]][y+dy[j]] == '#')
					stadium[x+dx[j]][y+dy[j]] = '.';
			}
		}
	}

	cout << cnt << endl;
	return 0;
}

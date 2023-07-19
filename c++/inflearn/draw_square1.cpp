#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	vector<vector <char>> board(n, vector<char>(m));
	vector<vector <int>> dy(n+1, vector<int>(m+1));
	vector<int> cnt(min(n,m) + 2);

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}


	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(board[i][j] == '1'){
				dy[i+1][j+1] = min(dy[i][j+1], min(dy[i+1][j],dy[i][j]))+1;
				cnt[dy[i+1][j+1]] ++;
			}
		}
	}
	
	int sum =0;
	for(int i=1; cnt[i] !=0; i++){
		sum += cnt[i];
	}

	for(int i=1; cnt[i] !=0; i++){
		cout << i << " " << sum << endl;
		sum -= cnt[i];
	}

	return 0;
}

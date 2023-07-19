#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;


int main(){

	cin >> n >> m;

	vector<vector <char>> board(n, vector<char>(m));
	vector<int> cnt(n*m);
	queue<pair<int,int>> q;

	int size = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
			if(board[i][j] == '1'){
				q.push(make_pair(i,j));
				cnt[size] ++;
			}
		}
	}
	
	while(!q.empty()){
		int t = q.size();
		size++;
		for(int i =0; i<t; i++){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int check =0;
			for(int j=0; j<=size; j++){
				if(x+size >= n || y+size >= m){
					check =1;
					break;
				}
				if(board[x+size][y+j] == '0'){
					check =1;
					break;
				}
				if(board[x+j][y+size] == '0'){
					check =1; 
					break;
				}	
			}
			if(check == 0){
				cnt[size] ++;
				q.push(make_pair(x,y));
			}
		}
	}
	for(int i=0; cnt[i] !=0; i++){
		cout << i+1 << " " << cnt[i] << endl;
	}
	return 0;
}

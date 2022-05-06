#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;
int _max = 10000000;
int board[16][16];
vector<vector<int>> dp(16,vector<int>(1<<16, _max));

int DFS(int x, int visited){
	if(visited == (1<<n)-1){
		if(board[x][0] != 0){
			return board[x][0];
		}
		return _max;
	}
	if(dp[x][visited] != _max){
		return dp[x][visited];
	}
	for(int i=1; i<n; i++){
		if(((visited | (1<<i))!= visited) && board[x][i] != 0){
			dp[x][visited] = min(dp[x][visited], DFS(i,visited | (1<<i)) + board[x][i]);		
		}
	}
	
	return dp[x][visited];
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}
	

	cout << DFS(0,1);
	return 0;
}

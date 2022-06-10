#include <iostream>

using namespace std;

int dp[100001][5][5];
int moves[100001];
int scores[5][5] = {{0,2,2,2,2},{0,1,3,4,3},{0,3,1,3,4},{0,4,3,1,3},{0,3,4,3,1}};

int main(){
	int n = 1;
	while(1){
		cin >> moves[n];
		if(moves[n++] == 0){
			break;
		}
	}
	dp[1][0][moves[1]] = 2;
	dp[1][moves[1]][0] = 2;
	
	for(int x=2; x<=n; x++){
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(dp[x-1][i][j] != 0){
					if(moves[x] != j)
						if(dp[x][moves[x]][j] == 0)
							dp[x][moves[x]][j] = dp[x-1][i][j] + scores[i][moves[x]];
						else
							dp[x][moves[x]][j] = min(dp[x][moves[x]][j], dp[x-1][i][j] + scores[i][moves[x]]);
					if(moves[x] != i)
						if(dp[x][i][moves[x]] == 0)
							dp[x][i][moves[x]] = dp[x-1][i][j] + scores[j][moves[x]];			
						else
							dp[x][i][moves[x]] = min(dp[x][i][moves[x]], dp[x-1][i][j] + scores[j][moves[x]]);
				}
			}
		}
	}
	int res = 400001;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(dp[n][i][j] != 0)
				res = min(res,dp[n][i][j]);
		}
	}
	if(res == 400001)
		res = 0;
	cout << res;
	return 0;
}

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> pw(9), team(3), sum(3);
int res = INT_MAX;

void DFS(int level){
	if(level ==9){
		int high = max(sum[0], max(sum[1], sum[2]));
		int low = min(sum[0], min(sum[1], sum[2]));
		res = min(res, high-low);
	}
	else{
		for(int i=0; i<3; i++){
			if(team[i] < 3){
				sum[i] += pw[level];
				team[i] ++;
				DFS(level+1);
				sum[i] -= pw[level];
				team[i] --;
			}
		}
	}
}
int main(){
	for(int i=0; i<9; i++){
		cin >> pw[i];
	}

	DFS(0);

	cout << res << endl;

	return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int cnt[32001];
vector<vector<int>> order(32001);

int main(){
	int n, m;

	cin >> n >> m;

	int x1, x2;
	for(int i=0; i<m; i++){
		cin >> x1 >> x2;
		cnt[x2]++;
		order[x1].push_back(x2);
	}
	
	queue<int> q;

	for(int i=1; i<=n; i++){
		if(cnt[i] == 0){
			q.push(i);
			cnt[i] = -1;
		}
	}

	while(!q.empty()){
		int x = q.front();
		cout << x << " ";
		q.pop();
		for(int i=0; i<order[x].size(); i++){
			if(--cnt[order[x][i]] == 0){
				q.push(order[x][i]);
				cnt[order[x][i]] = -1;
			}
		}
	}

	return 0;
}

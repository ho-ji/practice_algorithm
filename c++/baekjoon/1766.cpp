#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cnt[32001];
vector<vector<int>> order(32001);

int main(){
	int n, m;

	cin >> n >> m;


	int a,b;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		cnt[b]++;
		order[a].push_back(b);
	}

	priority_queue<int,vector<int>, greater<int>> q;
	for(int i=1; i<=n; i++){
		if(cnt[i] == 0){
			q.push(i);
			cnt[i] = -1;
		}
	}

	while(!q.empty()){
		int x = q.top();
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


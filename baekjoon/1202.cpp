#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
 	int n,k;

	cin >> n >> k;
	
	vector<pair<int,int>> jw(n);

	int m,v;
	for(int i=0; i<n; i++){
		cin >> m >> v;
		jw[i] = make_pair(m,v);
	}

	vector<int> c(k);

	for(int i=0; i<k; i++){
		cin >> c[i];
	}

	sort(c.begin(), c.end());
	sort(jw.begin(), jw.end());
	
	priority_queue<int> q;

	long long answer = 0;
	int pos = 0;
	for(int i=0; i<k; i++){
		while(pos<n &&jw[pos].first <= c[i]){
			q.push(jw[pos].second);
			pos++;
		}
		if(!q.empty()){
			answer += q.top();
			q.pop();
		}
	}
	cout << answer ;

	return 0;
}
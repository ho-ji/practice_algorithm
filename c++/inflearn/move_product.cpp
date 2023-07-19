#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, e;
vector<pair<int, int>> list[10001];

int CanMove(int weight){
	vector<int> check(n+1);
	queue<int> q;
	check[s] =1;
	q.push(s);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<list[x].size(); i++){
			if(list[x][i].second >= weight && check[list[x][i].first] ==0){
				check[list[x][i].first] = 1;
				q.push(list[x][i].first);
			}
		}
	}
	return check[e];
}

int main(){

	cin >> n >> m;
	
	int rt= -1;
	
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		list[a].push_back(make_pair(b,c));
		list[b].push_back(make_pair(a,c));
		rt = max(rt,c);
	}	

	cin >> s >> e;
	int lt = 0; 
	int res = 0;

	while(lt<= rt){
		int mid = (rt+lt)/2;
		
		if(CanMove(mid)){
			res = mid;
			lt = mid +1;
		}
		else{
			rt= mid -1;
		}
	}
	cout << res << endl;

	return 0;
}

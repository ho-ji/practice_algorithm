#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> edge;
vector<int> parent;

int find_root(int x){
	if(parent[x] == x)
		return x;
	else
		return parent[x] = find_root(parent[x]);
}

void union_root(int x, int y){
	x = find_root(x);
	y = find_root(y);

	if(x != y){
		parent[y] = x;
	}
}



int main(){
	
	int n,m;
	
	cin >> n >> m;

	for(int i=0; i<n; i++){
		parent.push_back(i);
	}

	int a, b, c;
	for(int i=0; i<m; i++){
		cin >> a >> b >> c;
		edge.push_back(make_pair(c, make_pair(a-1,b-1)));
	}

	sort(edge.begin(), edge.end());
	
	long long answer = 0;
	int	count = 0;
	for(int i=0; i < edge.size(); i++){
		int x = edge[i].second.first;
		int y = edge[i].second.second;
		int w = edge[i].first;
		


		if(find_root(x) != find_root(y)){
			answer += w;
			union_root(x,y);
			count ++;
		}

		if(count == n-1){
			break;
		}
	}
	cout << answer;

	return 0;
}

#include <iostream>

using namespace std;
using pp = pair<int,int>;

pp start_point[3001], end_point[3001];
int parent[3001], count[3001];

int ccw(pp a, pp b, pp c){
	int tmp = a.first*b.second + b.first*c.second + c.first*a.second - (a.second*b.first + b.second*c.first + c.second*a.first);
	if(tmp > 0)
		return 1;
	if(tmp < 0)
		return -1;
	else
		return 0;
}

bool check(pp a, pp b, pp c, pp d){
	int abc = ccw(a,b,c);
	int abd = ccw(a,b,d);
	int cda = ccw(c,d,a);
	int cdb = ccw(c,d,b);
	if(abc*abd == 0 && cda*cdb ==0)
		return max(a,b) >= min(c,d) && min(a,b) <= max(c,d);
	return abc*abd <=0 && cda*cdb <= 0;
}

int find_root(int a){
	if(a == parent[a])
		return a;
	return parent[a] = find_root(parent[a]);
}

void union_root(int a, int b){
	a = find_root(a);
	b = find_root(b);

	if(a!= b){
		parent[b] = a;
		count[a] += count[b];
		count[b] = 0;
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >>start_point[i].first;
		cin >>start_point[i].second;
		cin >>end_point[i].first;
		cin >>end_point[i].second;

		parent[i] = i;
		count[i] = 1;
	}
	
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(check(start_point[i],end_point[i],start_point[j],end_point[j])){
				union_root(i,j);
			}
		}
	}

	int group_cnt = 0, max_count = 0;
	for(int i=0; i<n; i++){
		if(count[i] != 0){
			group_cnt ++;
			max_count = max(max_count, count[i]);
		}
	}

	cout << group_cnt << "\n" << max_count;

	return 0;
}

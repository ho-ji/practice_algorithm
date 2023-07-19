#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int unf[1001];

struct Edge{
	int h1;
	int h2;
	double dis;
	
	Edge(int a, int b, double c){
		h1 = a;
		h2 = b;
		dis = c;
	}

	bool operator<(const Edge &e)const{
		return dis < e.dis;
	}
};

int find(int x){
	if(unf[x] == x)
		return x;
	else
		return unf[x] = find(unf[x]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a != b)
		unf[a] = b;
}

int main(){
	int n, m;
	double res = 0;

	cin >> n >> m;

	vector<double> x(n), y(n);
	vector<Edge> list;
	
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
		unf[i] = i;
	}

	for(int i=0; i<n; i++){
		for(int j= i+1; j<n; j++){
			double dis = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
			list.push_back(Edge(i,j,dis));
		}
	}
	
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		merge(a-1, b-1);
	}
	
	sort(list.begin(), list.end());

	for(int i=0; i<list.size(); i++){
		int a = find(list[i].h1);
		int b = find(list[i].h2);
		if(a != b){
			res += list[i].dis;
			merge(list[i].h1, list[i].h2);
		}
	}

	printf("%0.2f\n", res);
	return 0;

}

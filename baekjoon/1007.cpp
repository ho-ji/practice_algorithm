#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
using ll = long long;

int n, x[20],y[20];
ll total_x, total_y;
ll res;

void DFS(int l, int pos, ll sum_x, ll sum_y){
	if(l == n/2){
		res = min(res, (2*sum_x - total_x)*(2*sum_x - total_x) + (2*sum_y - total_y)*(2*sum_y - total_y));
		res = min(res, (total_x - 2*sum_x)*(total_x - 2*sum_x) + (total_y- 2*sum_y)*(total_y - 2*sum_y));
	}
	else{
		for(int i=pos; i<n; i++){
			DFS(l+1, i+1, sum_x + x[i], sum_y + y[i]);
		}
	}
}
int main(){
	int t;
	cin >> t;

	while(t--){
		cin >> n;

		total_x = 0;
		total_y = 0;
		res = LLONG_MAX;

		for(int i=0; i<n; i++){
			cin >> x[i] >> y[i];
			total_x += x[i];
			total_y += y[i];
		}

		DFS(0,0,0,0);

		double r = sqrt(res);

		printf("%.12lf\n",r);
	}

	return 0;
}

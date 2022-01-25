#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> dist(n), seat(n);

	int p = 1000;
	int res = -1;
	for(int i=0; i<n; i++){
		cin >> seat[i];
		if(seat[i] == 1){
			p=0;
			dist[i] = p;
		}
		else{
			p++;
			dist[i] = p;
		}
	}

	for(int i=n-1; i>=0; i--){
		if(seat[i] == 1){
			p=0;
			dist[i] = p;
		}
		else{
			p++;
			dist[i] = min(dist[i], p);
			if(dist[i] > res){
				res = dist[i];
			}
		}
	}

	cout << res << endl;

	return 0;
}

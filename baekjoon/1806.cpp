#include <iostream>

using namespace std;

int list[100000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	long long s;
	cin >> n >> s;

	for(int i=0; i<n; i++){
		cin >> list[i];
	}

	int pos = 0, len = 0, res = 100001;
	long long sum = 0;
	
	for(int i=0; i<n; i++){
		sum += list[i];
		len ++;
		while(sum >= s){
			res = min(len, res);
			sum -= list[pos];
			pos ++;
			len --;
		}
	}
	if(res == 100001)
		res = 0;
	cout << res;
	return 0;
}

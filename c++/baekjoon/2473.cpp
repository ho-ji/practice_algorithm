#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n;
	long long result[3];
	long long value = 9000000000;
	long long list[5000];
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> list[i];
	}

	sort(list, list + n);

	for(int x = 0; x < n-2; x++){
		int l = x + 1, r = n - 1;
		while(l < r){
			long long sum = list[x] + list[l] + list[r];
			if(abs(sum) < value){
				value = abs(sum);
				result[0] = list[x];
				result[1] = list[l];
				result[2] = list[r];
			}
			if(sum < 0)
				l++;
			else
				r--;
		}
	}

	cout << result[0] << " " << result[1] << " " << result[2] << endl;
	return 0;
}


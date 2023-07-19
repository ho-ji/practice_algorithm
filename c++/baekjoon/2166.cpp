#include <iostream>

using namespace std;

int x[10000], y[10000];

int main(){
	int n; 
	
	cin >>  n;
	
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
	}

	long long ret = 0;
	
	int i = n-1;

	for(int j=0; j<n; j++){
		ret += (long long)x[i]*y[j]  - (long long)x[j]*y[i];
		i = j;
	}
	

	ret = ret < 0? -ret : ret;
	
	printf("%.1f\n", (double)ret/2);
	
	return 0;
}
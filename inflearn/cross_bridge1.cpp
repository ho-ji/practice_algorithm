#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector <int> list(n), dy(n);

	for(int i=0; i<n; i++){
		cin >> list[i];
	}

	dy[0] = list[0];
	dy[1] = list[1];

	for(int i=2; i<n; i++){
		dy[i] = min(dy[i-1]+list[i], dy[i-2]+list[i]);
	}

	cout << min(dy[n-1], dy[n-2]) << endl;

	return 0;
}

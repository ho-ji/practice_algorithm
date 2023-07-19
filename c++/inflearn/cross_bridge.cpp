#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> list(47);
int n, res = INT_MAX;

void DFS(int l, int sum){
	if(l == n || l == n-1){
		if(res > sum)
			res = sum;
	}
	else{
		DFS(l+1, sum + list[l+1]);
		DFS(l+2, sum + list[l+2]);
	}	
}

int main(){
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> list[i];
	}

	DFS(0,0);

	cout << res << endl;

	return 0;
}

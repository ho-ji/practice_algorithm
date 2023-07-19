#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int l, n, res =0;
vector <int> len, cap;

void DFS(int level, int sum, int c){
	if(sum > l)
		return ;
	if(level == n){
		if(sum == l)
			if(res < c)
				res = c;
	}
	else{
		DFS(level+1, sum + len[level], min(c, cap[level]));
		DFS(level+1, sum, c);
	}
}
int main(){
	cin >> l >>  n;
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		len.push_back(a);
		cap.push_back(b);
	}

	DFS(0,0,INT_MAX);

	cout << res << endl;

	return 0;
}

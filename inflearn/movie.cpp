#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	
	int N;

	cin >> N;

	vector<int> list(N+1), res(N+1, 0);

	for(int i=1; i<=N; i++){
		cin >> list[i];
	}

	stack<int> s;

	for(int i=N; i>=1; i--){
		while(!s.empty() && list[s.top()] < list[i]){
			res[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	for(int i=1; i<=N; i++){
		cout << res[i] << " ";
	}

	return 0;
}

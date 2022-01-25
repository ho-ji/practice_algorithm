#include <iostream>
#include <map>

using namespace std;

int main(){
	int n;

	cin >> n;

	map<int, int> m;
	
	int res = -1;
	
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		if(m[a] == 0)
			m[a] ++;
	}
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		if(m[a] == 1)
			m[a] ++;
	}
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		if(m[a] == 2){
			m[a] ++;
			if(a > res)
				res = a;
		}
	}	

	cout << res << endl;

	return 0;
}

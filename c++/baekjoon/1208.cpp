#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> list;
int n,s;
long long res;
map<int, int> m;

void right(int pos, int sum){
	 if(pos == n){
	 	m[sum] ++;
	 }
	 else{
	 	right(pos+1, sum);
		right(pos+1, sum+list[pos]);
	 }
}
void left(int pos, int sum){
	if(pos==n/2){
		res += m[s-sum];
	}
	else{
		left(pos+1, sum);
		left(pos+1, sum+list[pos]);
	}
}
int main(){

	cin >> n >> s;

	int x;
	for(int i=0; i<n; i++){
	 	cin >> x;
		list.push_back(x);
	}
	right(n/2, 0);
	left(0, 0);
	
	if(s == 0)
		res --;
	cout << res;

	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int n, cnt=0;
string res= "(";

void DFS(int s, int e, string res){
	if(s > n || e > n || e > s) 
		return ;
	if(s == n &&  e == n){
		cout << res << endl;
		cnt ++;
	}
	else{
		DFS(s+1, e, res+"(");
		DFS(s, e+1, res+")");
	}
}
int main(){
	cin >> n;

	DFS(1,0,"(");

	cout << cnt << endl;

	return 0;

}

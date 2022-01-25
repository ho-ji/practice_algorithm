#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> pw(9),team(9);
int res = INT_MAX;

void DFS(int level,int a, int b, int c){
	if(a>3 || b>3 || c>3)
		return;
	if(a==3 && b==3 && c==3){
		int sum_a=0, sum_b=0, sum_c=0;
		for(int i=0; i<9; i++){
			if(team[i] == 1)
				sum_a += pw[i];
			else if(team[i]==2)
				sum_b += pw[i];
			else if(team[i]==3)
				sum_c += pw[i];
		}
		int x = max(sum_a,sum_b), y = min(sum_a,sum_b);
		x = max(x,sum_c);
		y = min(y,sum_c);

		res = min(res, x - y);
	}
	else{
		team[level] = 1;
		DFS(level+1,a+1,b, c);
		team[level] = 2;
		DFS(level+1,a,b+1, c);
		team[level] = 3;
		DFS(level+1,a,b,c+1);
	}
}

int main(){
	for(int i=0; i<9; i++){
		cin >> pw[i];
	}
	
	DFS(0,0,0,0);

	cout << res << endl;

	return 0;

}

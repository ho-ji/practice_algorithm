#include <iostream>

using namespace std;

int n, white_cnt, black_cnt;
int board[10][10];
bool l[20],r[20];

void DFS(int x, int y, int cnt, bool flag){
	if(y>= n){
		x++;
		if(y % 2 == 1)
			y = 0;
		else
			y = 1;
	}

	if(x == n){
		if(!flag){
			black_cnt = max(black_cnt, cnt);
		}
		else{
			white_cnt = max(white_cnt, cnt);
		}
		return;
	}
	if(board[x][y] == 1 && !l[x+y] && !r[x-y+n]){
		l[x+y] = true;
		r[x-y+n] = true;
		DFS(x, y+2, cnt+1, flag);
		l[x+y] = false;
		r[x-y+n] = false;
	}
	DFS(x, y+2, cnt, flag);
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}

	DFS(0,0,0,0);
	DFS(0,1,0,1);

	cout << black_cnt + white_cnt;

	return 0;
}

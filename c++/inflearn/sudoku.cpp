#include <iostream>
#include <vector>

using namespace std;

int board[9][9];

struct pos{
	int x;
	int y;
	pos(int a, int b){
		x =a;
		y =b;
	}
};
vector<pos> list;

void DFS(int level, int value){
	int nx =list[level].x;
	int ny =list[level].y;
	for(int i=0; i<9; i++)
		if(board[nx][i] == value || board[i][ny] == value ||
				board[nx/3*3+i/3][ny/3*3+i%3] == value)
			return;
	if(level == list.size()-1){
		board[nx][ny] = value;
		for(int i=0; i< 9; i++){
			for(int j=0; j<9; j++){
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	else{
		for(int i=1; i<=9; i++){
			board[nx][ny] = value;
			DFS(level+1, i);
			board[nx][ny] = 0;
		}
	}
}

int main(){

	for(int i=0; i< 9; i++){
		for(int j=0; j<9; j++){
			cin >> board[i][j];
			if(board[i][j]==0){
				list.push_back(pos(i,j));
			}
		}
	}
	for(int i=1; i<=9; i++){
		DFS(0, i);
	}
}

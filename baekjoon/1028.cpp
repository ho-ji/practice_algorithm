#include <iostream>

using namespace std;

int main(){
	int r, c, res =0;

	cin >> r >> c;

	int l_dia[r][c], r_dia[r][c];

	char input; 

	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++){
			cin >> input;
			if(input == '0'){
				l_dia[i][j] = 0;
				r_dia[i][j] = 0;
			}
			else{
				l_dia[i][j] = 1;
				r_dia[i][j] = 1;
			}
		}

	for(int i=r-2; i>=0; i--){
		for(int j=0; j<c; j++){
			if(l_dia[i][j] == 1 && j!= 0){
				l_dia[i][j] += l_dia[i+1][j-1];
			}
			if(r_dia[i][j] ==1 && j!= c-1){
				r_dia[i][j] += r_dia[i+1][j+1];
			}
		}
	}

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(l_dia[i][j] !=0 && r_dia[i][j] !=0){
				res = max(res, 1);
				if(l_dia[i][j] != 1 && r_dia[i][j] != 1){
					int n = min(l_dia[i][j], r_dia[i][j]);
					while(n > 1){
						if(r_dia[i+n-1][j-n+1] >= n && l_dia[i+n-1][j+n-1]>=n){
							res = max(res, n);
						}
						n --;
					}
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}

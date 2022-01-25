#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, list[17][2],check[17], res=INT_MAX;


void DFS(int L, int s){
	if(L == N/2){
		int sum_white =0, sum_black =0;
		for(int i=0; i<N; i++){
			if(check[i] == 0){
				sum_white += list[i][0];
			}
			else{
				sum_black += list[i][1];
			}
		}
		res = min(res,abs(sum_white - sum_black));
				
	}
	else{
		for(int i=s; i<N; i++){
			check[i] = 1;
			DFS(L+1, i+1);
			check[i] = 0;

		}
	}
}

int main(){
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> list[i][0] >> list[i][1];//white_power black_power
		check[i] = 0;
	}
	
	DFS(0,0);

	cout << res << endl;
	
	return 0;
}

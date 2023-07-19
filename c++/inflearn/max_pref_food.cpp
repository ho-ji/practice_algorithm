#include <iostream>
#include <vector>

using namespace std;


int n, d, k;
int res= -1;

void DFS(int L, int v, int bit, vector<int> &list, vector<int> &power){
	if(L == k){
		int count = 0;
		for(int i=1; i<=n; i++){
			if((bit & list[i]) == list[i])
				count++;
		}
		if(res < count)
			res = count;
	}
	else{
		for(int i=v; i<= d; i++){
			DFS(L+1, v+1,bit+power[i],list,power);
		}
	}

}

int main(){

	cin >> n >> d >> k;
	
	vector<int> list(n+1), power(16,1);

	for(int i=1; i<16; i++){
		power[i] = power[i-1]*2;
	}
	for(int i=1; i<=n; i++){
		int a;
		cin >> a;
		list[i] =0;
		for(int j=0; j<a; j++){
			int b;
			cin >> b;
			list[i] += power[b];
		}
	}

	DFS(0,1,0,list,power);

	cout << res << endl;

	return 0;
}

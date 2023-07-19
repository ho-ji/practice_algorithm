#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int l, n, res =0;
vector<int> len, cap, check;

void DFS(int l_sum, int c_sum,int v){
	if(l_sum > l)
		return;
	if(l_sum == l){
		if(c_sum > res)
			res = c_sum;
	}
	else{
		for(int i=v; i< n; i++){
			if(check[i] == 0){
				check[i] = 1;
				if(c_sum > cap[i])
					DFS(l_sum + len[i], cap[i],i+1);
				else
					DFS(l_sum + len[i], c_sum,i+1);
				check[i] = 0;
			}
		}
	}
}

int main(){
	cin >> l >> n;

	for(int i=0; i<n; i++){
		int a,b;
		cin >> a >> b;
		len.push_back(a);
		cap.push_back(b);
		check.push_back(0);
	}

	DFS(0,INT_MAX,0);

	cout << res << endl;

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long long n,k;
	
	cin >> n;

	vector<int> list(n+1);

	for(int i=1; i<=n; i++){
		cin >> list[i];
	}
	
	cin >> k;

	vector<int> slist(list);

	sort(slist.begin(), slist.end());

	long long cnt = n;
	for(int i=1; i<=n; i++){
		if(k < ((slist[i] - slist[i-1])*cnt)){
			int index = k % cnt;
			for(int j=1 ; j<=n; j++){
				if(list[j] >= slist[i]){
					if(index == 0){
						cout<< j << endl;
						return 0;
					}
					index--;
					
				}
				
			}
		}
		else{
			k -= ((slist[i] - slist[i-1]) * cnt);
			cnt--;
		}
	}
	cout << -1 << endl;
	return 0;
}	

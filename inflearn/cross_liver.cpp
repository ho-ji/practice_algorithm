#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	int n, sum=0;
		
	cin >> n;
	
	vector<int> list(n);

	for(int i=0; i<n; i++){
		cin >> list[i];
	}
	
	sort(list.begin(), list.end());

	int i;
	for(i=n-1; i>=3; i-=2){
		sum+= min(list[i]+list[0]+list[i-1]+list[0],list[1]+list[1]+list[i]+list[0]);

	}

	if(i==2)
		sum += list[0]+list[1]+list[2];
	else if(i==1)
		sum += list[1];
	else if(i==0)
		sum += list[0];

	cout << sum << endl;

	return 0;
}	

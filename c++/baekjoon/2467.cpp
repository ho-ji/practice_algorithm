#include <iostream>

using namespace std;

int list[100001];
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> list[i];
	}

	int left = 0, right = n-1;
	long long sum = (long long)list[right] + list[left];
	int ret1 = left, ret2 = right;

	while(left<right){
		long long tmp = (long long)list[right] + list[left];
		if(abs(tmp) < abs(sum)){
			sum = tmp;
			ret1 = left;
			ret2 = right;
		}
		if(abs(list[right-1] + list[left]) > abs(list[right] + list[left+1])){
			left++;
		}
		else{
			right--;
		}
	}
	
	cout << list[ret1] << " " << list[ret2];

	return 0;
}

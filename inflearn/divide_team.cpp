#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, m;
	int lt = -1, rt = 0, res;

	cin >> n >> m;
	
	vector<int> list(n);

	for(int i=0; i<n; i++){
		cin >> list[i];
		lt = max(lt, list[i]);
		rt += list[i];
	}

	while(lt<=rt){
		int mid = (lt+rt)/2;

		int sum = 0, cnt = 1;
		for(int i=0; i<n; i++){
			if(sum + list[i] > mid){
				sum = list[i];
				cnt ++;
			}
			else
				sum += list[i];
		}
		if(cnt <= m){
			res = mid;
			rt = mid -1;
		}
		else{
			lt = mid + 1;
		}
	}
	cout << res << endl;
	return 0;
}

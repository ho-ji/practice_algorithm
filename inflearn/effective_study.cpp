#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>


using namespace std;

struct Study{
	int start_time;
	int end_time;
	int ev;

	Study(int a, int b, int c){
		start_time = a;
		end_time = b;
		ev = c;
	}

	bool operator < (const Study &s)const{
		return end_time < s.end_time;		
	}

};

int main(){
	int n, m, r, res=INT_MIN;
	
	cin >> n >> m >> r;

	vector<Study> list;
	vector<int> sum(m,0);

	for(int i=0; i<m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		list.push_back(Study(x,y,z));
	}
	
	sort(list.begin(), list.end());
	for(int i=0; i<m; i++){
		sum[i] = list[i].ev;
		for(int j=i-1; j>=0; j--){
			if(list[j].end_time + r <= list[i].start_time && sum[j]+list[i].ev > sum[i])
				sum[i] = sum[j] + list[i].ev;
		}
		if(res < sum[i])
			res = sum[i];
	}

	cout << res << endl;

	return 0;
}


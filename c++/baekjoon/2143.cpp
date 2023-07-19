#include <iostream>
#include <map>

using namespace std;

int nlist[1000], mlist[1000];
int main(){
	int t;
	int n,m;
	cin >> t;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> nlist[i];
	}
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> mlist[i];
	}

	map<long long, long long> nmap, mmap;

	long long sum;
	for(int i=0; i<n; i++){
		sum = 0;
		for(int j=i; j<n; j++){
			sum += nlist[j];
			nmap[sum] ++;
		}
	}

	for(int i=0; i<m; i++){
		sum = 0;
		for(int j=i; j<m; j++){
			sum += mlist[j];
			mmap[sum] ++;
		}
	}

	long long  res = 0;
	for(auto x = nmap.begin(); x != nmap.end(); x++){
		if(mmap.find(t - x->first) != mmap.end()){
			res += x->second * mmap[t - x->first];
		}
	}

	cout << res;
	return 0;
}

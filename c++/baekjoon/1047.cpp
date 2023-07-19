#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;

	int res = n;

	vector<int> x(n), y(n), nfence(n), xsort(x), ysort(x);

	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i] >> nfence[i];
		xsort[i] = x[i];
		ysort[i] = y[i];
	}

	sort(xsort.begin(), xsort.end());
	sort(ysort.begin(), ysort.end());

	vector<int> in;

	for(int a=0; a<n; a++){ for(int b=a; b<n; b++){
		for(int c=0; c<n; c++){ for(int d=c; d<n; d++){
			int ntree = 0, out_sum =0, in_sum =0;
			int need = 2*(xsort[b] - xsort[a] + ysort[d] - ysort[c]);

			for(int i=0; i<n; i++){
				if(x[i] >= xsort[a] && x[i] <= xsort[b]
						&& y[i] >= ysort[c] && y[i] <= ysort[d]){
					 ntree ++;
					 in.push_back(nfence[i]);
					 in_sum += nfence[i];
				}
				else{
					out_sum += nfence[i];
				}	
			}//i

			if(out_sum >= need){
				res = min(res, n- ntree);
			}
			else{
				if(out_sum + in_sum >= need){
					sort(in.begin(), in.end(), greater<int>());
					for(int i=0; i<in.size(); i++){
						ntree--;
						out_sum += in[i];
						if(out_sum >= need){
							res = min(res, n- ntree);
							break;
						}
					}
				}
			}
			in.clear();
		}}
	}}

	cout << res << endl;

	return 0;
}

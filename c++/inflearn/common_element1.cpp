#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> a(n), b(n), c(n);

	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	for(int i=0;i<n;i++)
		cin >> c[i];

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	sort(c.begin(), c.end(), greater<int>());

	int p1=0, p2=0, p3=0;

	while(p1<n && p2<n && p3<n){
		int maxN = max(a[p1], max(b[p2], c[p3]));
		
		if(maxN == a[p1] && maxN == b[p2] && maxN == c[p3]){
			cout << maxN << endl;
			return 0;
		}
		else{
			if(maxN == a[p1])
				p1++;
			if(maxN == b[p2])
				p2++;
			if(maxN == c[p3])
				p3++;
		}
	}
	cout << -1 << endl;
	return 0;
}

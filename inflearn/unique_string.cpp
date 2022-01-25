#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;
	char c;
	
	cin >> n >> c;
	
	c = toupper(c);

	for(int i=0; i<n; i++){
		string a;
		cin >> a;
		transform(a.begin(), a.end(), a.begin(), ::toupper);

		if(a.find(c) != string::npos){
			string res ="";
			for(int j=0; j<a.size(); j++){
				if(a.find(a[j]) == j)
					res += a[j];
			}
			cout << res << endl;
		}
	}

	return 0;
}

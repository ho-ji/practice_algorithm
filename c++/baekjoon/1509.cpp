#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dp[2501][2501];

int main(){
	string s;

	cin >> s;

	for(int i=0; i<s.size(); i++){
		dp[i][i] = true;
	}

	for(int i=0; i<s.size()-1; i++){
		if(s[i] == s[i+1])
			dp[i][i+1] = true;
	}

	for(int n = 2; n < s.size(); n++){
		for(int i=0; i< s.size()-n; i++){
			int j=i+n;
			if(s[i] == s[j] && dp[i+1][j-1]){
				dp[i][j] = true;
			}
		}
	}

	int d[2501];
	d[0] = 0;

	for(int n=1; n<=s.size(); n++){
		int j = n-1;
		d[n] = d[j] + 1;
		for(int i=0; i<n-1; i++){
			if(dp[i][j]){
				if(d[n] > d[i] + 1)
					d[n] = d[i] +1;
			}
		}
	}

	cout << d[s.size()] << endl;
	return 0;
}

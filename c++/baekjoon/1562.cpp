#include <iostream>

using namespace std;

int dp[101][10][1<<10];

int main(){
	int n;
	int mod = 1000000000;
	
	cin >> n;

	for(int i=1; i<10; i++)
		dp[1][i][1<<i] = 1;

	for(int len=2; len<=n; len++){
		for(int num=0; num<10; num++){
			for(int i=0; i<1024; i++){
				if(num != 0)
					dp[len][num][i | (1<<num)] = (dp[len][num][i | (1<<num)] + dp[len-1][num-1][i]) % mod;
				if(num != 9)
					dp[len][num][i | (1<<num)] = (dp[len][num][i | (1<<num)] + dp[len-1][num+1][i]) % mod;
			}
		}
	}

	int count = 0;
	for(int i=0; i<10; i++){
		count = (count+dp[n][i][1023]) % mod;
	}

	cout << count;
	return 0;
}
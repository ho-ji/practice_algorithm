#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n1, n2, n3;
	string s1, s2;

	cin >> n1 >> n2 >> n3;
	cin >> s1 >> s2;

	int len1 = s1.size(), len2 = s2.size();

	vector<vector <int>> dy(len1+1, vector<int>(len2+1));
  
	for(int i=1; i<=len1; i++)
		dy[i][0] = dy[i-1][0] + n2;
	for(int i=1; i<=len2; i++)
		dy[0][i] = dy[0][i-1] + n2;

	for(int i=1; i<=len1; i++){
		for(int j=1; j<=len2; j++){
			if(s1[i-1] == s2[j-1]){
				dy[i][j] = dy[i-1][j-1] + n1;
			}
			else{
				int max = dy[i-1][j] + n2;
				if(max < dy[i][j-1] + n2)
					max = dy[i][j-1] + n2;
				if(max < dy[i-1][j-1] + n3)
					max = dy[i-1][j-1] + n3;
				if(max < dy[i-1][j-1] + 2*n2)
					max = dy[i-1][j-1] + 2*n2;
				dy[i][j] = max;
			}
		}
	}
	
	cout << dy[len1][len2] << endl;

	return 0;
}

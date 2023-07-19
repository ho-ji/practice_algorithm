#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string s1, s2;

	cin >> s1 >> s2;

	int len1 = s1.size(), len2 = s2.size();
	
	vector<vector <int>> dy(len1+1, vector<int>(len2+1));

	for(int i=1; i <= len1; i++){
		for(int j=1; j <= len2; j++){
			if(s1[i-1] == s2[j-1]){
				dy[i][j] = dy[i-1][j-1] + 1;
			}
			else{
				dy[i][j] = max(dy[i-1][j], dy[i][j-1]);
			}
		}
	}

	cout << dy[len1][len2] << endl;
	return 0;
}

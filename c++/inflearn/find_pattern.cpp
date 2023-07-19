#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	int n;
	
	cin >> s >> n;

	int cnt= 1;
	string pattern = s.substr(0,cnt);
	while(s.find(pattern,cnt+1)!=string ::npos){
		pattern = s.substr(0,++cnt);
	}
	int pattern_len= pattern.size();

	int res = 0;
	int len = pattern.size();
	
	for(int i=0; i<len; i++){
		res += pattern[i] - '0';
	}

	res = (n/len) * res;

	for(int i=0; i< n%len; i++){
		res += pattern[i] - '0';
	}

	cout << res << endl;
	return 0;
}

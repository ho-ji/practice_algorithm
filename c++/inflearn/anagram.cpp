#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	int res = 0;
	string s, t;

	cin >> s >> t;

	map<char,int> sH, tH;

	int L = t.size() -1;
	
	for(int i=0; i< L; i++){
		tH[t[i]]++;
		sH[s[i]]++;
	}

	tH[t[L]]++;
	
	int left = 0;
	
	for(int right = L; right < s.size(); ++right){
		sH[s[right]] ++;
		if(sH == tH) 
			res ++;
		sH[s[left]]--;
		if(sH[s[left]] ==0)
			sH.erase(s[left]);
		left++;
	}


	cout << res << endl;

	return 0;
}

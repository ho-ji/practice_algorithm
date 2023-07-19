#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	string s,res = "";
	cin >> s;

	transform(s.begin(), s.end(), s.begin(), ::toupper);

	map<char,int> m, check;

	for(int i=0; i<s.size(); i++){
		m[s[i]] ++;	
		check[s[i]] =0;
	}

	for(char c : s){
		m[c] --;
		if(check[c] ==1){
			continue;
		}
		else{
			while(!res.empty()&&c<res.back()&&m[res.back()] >0){
				check[res.back()] = 0;
				res.pop_back();
			}
			res += c;
			check[c] =1;
		}
	}
	cout << res << endl;
	return 0;
}

#include <iostream>
#include <string>

using namespace std;
int main(){
	string s, tmp= "";

	int sum = 0;

	cin >> s;

	for(int i=0; i<s.size(); i++){
		if(isdigit(s[i])!= 0){
			tmp.push_back(s[i]);
		}
		else if(!tmp.empty()){
			sum += stoi(tmp);
			tmp.clear();
		}
	}
	if(!tmp.empty()){
		sum +=stoi(tmp);
		tmp.clear();
	}
	cout <<sum << endl;

	return 0;
}

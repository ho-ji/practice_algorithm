#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n;
	string str;
	cin>>n;
	vector<string> words;

	for(int i=0;i<n;++i){
		cin>>str;
		words.push_back(str);
	}

	string res=words[0];
	for(int i=1; i<words.size();i++){
		while(words[i].find(res)!=0){
			res.pop_back();
		}
	}
	cout<<res;
	return 0;
}

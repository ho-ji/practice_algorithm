#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
	string s;
	int num = 0;
	queue<char> q;
	
	cin >> s;

	for(int i=0; i < s.size(); i++){
		if(isdigit(s[i])){
			num = num * 10 + (s[i] - '0');
		}
		else if(s[i] == '('){
			
		}
		else if(s[i] == ')'){
			string tmp = "";
			while(!q.empty()){
				tmp += q.front();
				q.pop();
			}
			if(num == 0)
				num =1;
			for(int j=0; j<num; ++j){
				cout << tmp;
			}
			num = 0;
		}
		else{
			q.push(s[i]);
		}
	}
	cout << endl;
	return 0;
}

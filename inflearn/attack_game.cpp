#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct student{
	int index;
	char team;
	int power;

	bool operator<(const student &s)const{
		return power < s.power;
	}
};


int main(){
	int n; 
	
	cin >> n;

	vector<student> list;

	for(int i=0; i<n; i++){
		student s;
		cin >> s.team >> s.power;
		s.index = i;
		list.push_back(s);
	}

	vector<student> slist(list);

	sort(slist.begin(), slist.end());
	
	map<char, int> team;

	vector<int> res(n);
	int j=0, sum =0;
	for(int i=1; i<n; i++){
		while(j<n){
			if(slist[i].power > slist[j].power){
					sum += slist[j].power;
					team[slist[j].team] += slist[j].power;
			
			}
			else 
				break;
			++j;
		}	
		res[slist[i].index] = sum - team[slist[i].team];
	}

	for(int i=0; i<n; i++){
		cout << res[i] << endl;
	}
	return 0;
}

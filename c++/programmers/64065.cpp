#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second > p2.second){
        return true;
    }
    else
        return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    string x ="";
    map<int,int> m;
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])){
            x += s[i];
        }
        else{
            if(x!= ""){
                m[stoi(x)] ++;
                x= "";
            }
        }
    }
    vector<pair<int,int>> list;
    for(auto it=m.begin(); it != m.end(); it++){
        list.push_back(make_pair(it->first,it->second));
    }
    sort(list.begin(), list.end(), cmp);
    
    for(int i=0; i<list.size(); i++)
        answer.push_back(list[i].first);
    return answer;
}
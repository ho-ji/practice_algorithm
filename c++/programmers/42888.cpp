#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> m;
    vector<pair<int,string>> list;
    
    for(int i=0 ; i< record.size(); i++){
        string act ="", uid ="",nick="";
        istringstream ss(record[i]);
        getline(ss,act,' ');
        getline(ss,uid,' ');
        if(act!= "Leave")
            getline(ss,nick,' ');
        if(act == "Enter"){
            list.push_back(make_pair(1,uid));
            m[uid]=nick;
        }
        else if(act == "Leave"){
            list.push_back(make_pair(2,uid));
        }
        else if(act == "Change"){
            m[uid]=nick;
        }
    }
    vector<string> answer;
    answer.assign(list.size(),"");
    for(int i=0; i<list.size(); i++){
      
        if(list[i].first== 1){
            answer[i] = m[list[i].second]+ "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        }
        else if(list[i].first == 2){
            answer[i] = m[list[i].second]+ "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        }
    }
    return answer;
}
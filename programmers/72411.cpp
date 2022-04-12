#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m;
int max_order = -1;

void DFS(string order, string list, int depth){
    if(list.size() == depth){
        int tmp = ++m[list];
        max_order = max(max_order,tmp);
    }   
    else{
        for(int i=0; i<order.size(); i++){
            DFS(order.substr(i+1), list+order[i], depth);
        }
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto &order:orders){
        sort(order.begin(),order.end());
    }
    for(int c:course){
        max_order = -1;
        for(auto &order:orders){
            if(order.size()>=c)
                DFS(order,"",c);
        }
        if(max_order>1){
            for(auto it = m.begin(); it!= m.end(); it++){
                if(it->second == max_order){
                    answer.push_back(it->first);
                }    
            }
        }
         m.clear();
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
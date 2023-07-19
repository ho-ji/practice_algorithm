#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
    vector<vector <int>> check(id_list.size(), vector<int>(id_list.size()));
    vector<int> cnt(id_list.size());
    map<string,int> m;
    
	for(int i=0; i<id_list.size(); i++){
        m[id_list[i]] = i;
        answer.push_back(0);
    }
    
	for(int i=0; i<report.size(); i++){
        string a, b;
        int x= report[i].find(' ');
        a = report[i].substr(0, x);
        b = report[i].substr(x+1);
        if(check[m[a]][m[b]] != 1){
            check[m[a]][m[b]] = 1;
            cnt[m[b]] ++;
        }
    }
    
	for(int i=0; i<id_list.size(); i++){
          if(cnt[i]>=k){
            for(int j=0; j<id_list.size(); j++){
                if(check[j][i] == 1){
                    answer[j] ++;
                }
            }
        }
    }
    return answer;
}

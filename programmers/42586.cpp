#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    
    vector<int> check(n+1);
    int cnt = 0;
    
    while(1){
        for(int i=0; i<n; i++){
            progresses[i] += speeds[i];
            if(progresses[i]>=100){
                if(check[i]== 0)
                    cnt++;
                check[i] ++;
            }
        }
        
        if(cnt == n){
            break;
        }
    }
    int x = check[0];
    int ret = 1;
    
    for(int i = 1; i<n+1; i++){
        if(x <= check[i]){
            ret++;
        }
        else{
            answer.push_back(ret);
            ret =1;
            x = check[i];
        }
    }
    
    return answer;
}
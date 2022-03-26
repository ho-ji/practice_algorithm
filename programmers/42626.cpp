#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0; i<scoville.size(); i++){
        q.push(scoville[i]);
    }
    
    while(!q.empty()){
        int n1 = q.top();
        q.pop();
        if(n1 >= K){
            break;
        }
        if(q.empty()){
            answer = -1;
            break;
        }
        int n2 = q.top();
        q.pop();
        
        n1 = n1+ 2*n2;
        q.push(n1);
        ++answer;
    }
    return answer;
}
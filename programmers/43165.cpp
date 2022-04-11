#include <string>
#include <vector>

using namespace std;

int answer =0;

void DFS(vector<int> &num, int &t, int depth, int sum){
    if(depth == num.size()){
        if(sum == t){
            answer++;
        }
    }
    else{
        DFS(num, t, depth+1, sum + num[depth]);
        DFS(num, t, depth+1, sum - num[depth]);
    }
}

int solution(vector<int> numbers, int target) {
    
    DFS(numbers, target, 0, 0);
    
    return answer;
}
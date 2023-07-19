#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = -200000;
    int len = sequence.size();
    int s1[len], s2[len];
    for(int i=0; i<len; i++){
        s1[i] = i%2 ? sequence[i] : -sequence[i];
        s2[i] = i%2 ? -sequence[i] : sequence[i];
    }
    
    long long cnt1[len], cnt2[len];
    cnt1[0] = s1[0];
    cnt2[0] = s2[0];
    answer = max(cnt1[0], cnt2[0]);
    for(int i=1; i<len; i++){
        cnt1[i] = max((long long)0, cnt1[i-1]) + s1[i];
        cnt2[i] = max((long long)0, cnt2[i-1]) + s2[i];
        
        if(answer < cnt1[i])
            answer = cnt1[i];
        if(answer < cnt2[i])
            answer = cnt2[i];
    }
    return answer;
}
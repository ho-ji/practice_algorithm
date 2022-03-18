#include <algorithm>

using namespace std;

long long solution(int w,int h) {
    long long a = max(w,h);
    long long b = min(w,h);
    long long answer = a*b;
    while(b!=0){
        int mod = a%b;
        a = b;
        b = mod;
    }   
    answer -= w + h - a;
    return answer;
}
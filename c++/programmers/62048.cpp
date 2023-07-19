#include <algorithm>

using namespace std;

long long solution(int w,int h) {
    long long answer =0;
    for(int i=0; i<w; i++){
        answer += (int)((long long)i*h/w);
    }
    return 2 * answer;
}
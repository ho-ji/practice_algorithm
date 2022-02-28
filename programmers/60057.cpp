#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int len = s.size();
    int answer = len;
    for(int n=1; n<= len/2; n++){
        string tmp = "", sub = s.substr(0,n);
        int cnt = 1;
        for(int i=n; i<=len; i+=n){
            if(sub==s.substr(i,n)){
                cnt ++;
            }
            else{
                if(cnt == 1){
                    tmp += sub;
                }
                else{
                    tmp += to_string(cnt);
                    tmp += sub;
                }
                sub = s.substr(i,n);
                cnt = 1;
            }
            if(i+n > len){
                tmp += s.substr(i, len);
                break;
            }
        }
        if(tmp.size() < answer)
            answer = tmp.size();
    }

    return answer;
}
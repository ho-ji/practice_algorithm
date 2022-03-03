#include <string>
#include <vector>


using namespace std;

int solution(string s) {
    int answer = 0;
    for(int pos = 0; pos < s.size(); pos++){
        if(isdigit(s[pos])){
            answer = answer*10 + (s[pos] - '0');
        }
        else{
            string tmp = s.substr(pos,3);
            int num = -1;
            if(tmp=="zer"){
                num = 0;
                pos += 1;
            }
            else if(tmp =="one"){
                num = 1;
            }
            else if(tmp == "two"){
                num = 2;
            }
            else if(tmp == "thr"){
                num = 3;
                pos += 2;
            }
            else if(tmp == "fou"){
                num = 4;
                pos += 1;
            }
            else if(tmp == "fiv"){
                num = 5;
                pos += 1;
            }
            else if(tmp == "six"){
                num = 6;
            }
            else if(tmp == "sev"){
                num = 7;
                pos += 2;
            }
            else if(tmp == "eig"){
                num = 8;
                pos +=2;
            }
            else if(tmp == "nin"){
                num = 9;
                pos +=1;
            }
            pos += 2;
            answer = answer*10 + num;
        }
    }
    return answer;
}
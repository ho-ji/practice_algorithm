#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    int i;
    string c = "ACFJMNRT";
    do{
        for(i=0; i<data.size(); i++){
            int diff = c.find(data[i][0]) - c.find(data[i][2]);
            diff = abs(diff) - 1;
            if(data[i][3]=='='){
                if(diff != data[i][4]-'0')
                    break;
            }
            else if(data[i][3] == '>'){
                if(diff <= data[i][4]-'0')
                    break;
            }
            else if(data[i][3] == '<'){
                if(diff >= data[i][4] - '0')
                    break;
            }
        }
        if(i==data.size())
            answer++;
    }while(next_permutation(c.begin(), c.end()));
    return answer;
}
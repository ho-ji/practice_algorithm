#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string c = "ACFJMNRT";
    vector<string> list;
    do{
        list.push_back(c);
    }while(next_permutation(c.begin(),c.end()));
    for(int i=0; i < list.size(); i++){
        bool flag = true;
        for(int j=0; j<n; j++){
            int diff = list[i].find(data[j][0]) - list[i].find(data[j][2]) ;
            diff = abs(diff) -1;
            if(data[j][3] == '='){
                if(diff != (data[j][4]-'0')){
                    flag = false;
                    break;
                }
            }
            else if(data[j][3] == '<'){
                if(diff >= (data[j][4]-'0')){
                    flag = false;
                    break;
                }
            }
            else if(data[j][3] == '>'){
                if(diff <= (data[j][4]-'0')){
                    flag = false;
                    break;
                }
            }
        }
        if(flag == true)
            answer++;
    }
    return answer;
}
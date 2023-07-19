#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> tmp;
    while(n >0){
        if(n%3 == 0){
            n = n/3;
            tmp.push_back(0);
        }
        else if(n%3 ==1){
            n = n/3;
            tmp.push_back(1);
        }
        else if(n%3 == 2){
            n = n/3;
            tmp.push_back(2);
        }
    }
    int i;
    for(i=0; i<tmp.size()-1; i++){
        if(tmp[i] == 0){
            answer = "4" + answer;
            tmp[i+1] --;
        }
        else if(tmp[i] == -1){
            answer = "2" + answer;
            tmp[i+1] --;
        }
        else{
            answer = to_string(tmp[i]) + answer;
        }
    }
    if(tmp[i] != 0)
        answer = to_string(tmp[i]) + answer;
    return answer;
}
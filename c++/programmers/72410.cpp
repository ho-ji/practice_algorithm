#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0; i<new_id.size(); i++){
        if(new_id[i] == '-'|| new_id[i] == '_'){
            answer += new_id[i];
        }
        else if(new_id[i] == '.'){
            if(answer != ""&&answer.back() != '.'){
                answer += new_id[i];
            }
        }
        else if(new_id[i] >='a'&&new_id[i] <='z'){
            answer += new_id[i];
        }
        else if(new_id[i] >='A'&&new_id[i] <='Z'){
            answer += (new_id[i]-('A'-'a'));
        }
        else if(new_id[i]>='0'&&new_id[i]<='9'){
            answer += new_id[i];
        }
    }//level 1,2;
    if(answer.front() == '.'){
        answer = answer.substr(1,answer.size()-1);
    }
    if(answer.back() == '.'){
        answer.pop_back();
    }
    if(answer == ""){
        answer = "a";
    }
    if(answer.size() > 15){
        answer = answer.substr(0,15);
        if(answer.back() == '.')
            answer.pop_back();
    }
    while(answer.size() < 3){
        answer.push_back(answer.back());
    }
    
    return answer;
}
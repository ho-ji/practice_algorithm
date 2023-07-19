#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int uni = 0, inter = 0;
    map<string,int> m1, m2;
    
    for(int i=0; i<str1.size()-1; i++){
        string s = "";
        if(str1[i]<='Z'&&str1[i]>='A'){
            s = str1[i];
        }
        else if(str1[i]<='z'&&str1[i]>='a'){
            s = toupper(str1[i]);
        }
        else{
            continue;
        }
        if(str1[i+1]<='Z'&&str1[i+1]>='A'){
            s += str1[i+1];
        }
        else if(str1[i+1]<='z'&&str1[i+1]>='a'){
            s += toupper(str1[i+1]);
        }
        else{
            continue;
        }
        m1[s]++;
        ++uni;
    }
    for(int i=0; i<str2.size()-1; i++){
        string s = "";
        if(str2[i]<='Z'&&str2[i]>='A'){
            s = str2[i];
        }
        else if(str2[i]<='z'&&str2[i]>='a'){
            s = toupper(str2[i]);
        }
        else{
            continue;
        }
        if(str2[i+1]<='Z'&&str2[i+1]>='A'){
            s += str2[i+1];
        }
        else if(str2[i+1]<='z'&&str2[i+1]>='a'){
            s += toupper(str2[i+1]);
        }
        else{
            continue;
        }
        m2[s]++;
        ++uni;
    }
    for(auto it=m1.begin(); it!=m1.end(); it++){
        if(m2.find(it->first) != m2.end()){
            inter += min(m2[it->first], it->second);
        }
    }
    uni -= inter;
    if(uni == 0 && inter == 0){
        answer = 65536;
    }
    else{
        answer = 65536*inter/uni;
    }
    return answer;
}
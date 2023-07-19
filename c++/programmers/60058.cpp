#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool correct_str(string p){
    int x=0;
    for(int i=0; i<p.size(); i++){
        if(p[i]== '('){
            x++;
        }
        else{
            x--;
        }
        if(x<0)
            return false;
    }
    if(x==0)
        return true;
    else
        return false;
}
string change_str(string p){
    string a ="";
    for(int i=1; i<p.size()-1; i++){
        if(p[i]=='(')
            a+=")";
        else
            a+="(";
    }
    return a;
}

string find(string w){
    string u="",v="", ret ="";
    if(w=="")
        return w;
    
    int pos=0;
    for(int i=0; i<w.size(); i++){
        if(w[i]=='(')
            pos++;
        else
            pos--;
        if(pos == 0){
            pos = i;
            break;
        } 
    }
    if(pos == w.size()-1){
        u = w;
        v = "";
    }
    else{
        u = w.substr(0,pos+1);
        v = w.substr(pos+1);
    }
    if(correct_str(u)){
        ret = u;
        ret += find(v);
    }
    else{
        ret = "(";
        ret += find(v);
        ret +=")";
        ret += change_str(u);
    }    
    
    return ret;
}
string solution(string p) {
    string answer = "";
    
    answer = find(p);
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    string x = phone_book[0];
    for(int i=1; i<phone_book.size(); i++){
        if(x.size()<=phone_book[i].size()){
            if(x==phone_book[i].substr(0,x.size())){
                answer = false;
                break;
            }
            else{
                x = phone_book[i];
            }
        }
        else{
            x = phone_book[i];
        }
    }
    return answer;
}
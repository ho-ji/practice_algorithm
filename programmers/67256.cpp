#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 12;
    for(int i=0; i < numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            left = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            right = numbers[i];
        }
        else{
            if(numbers[i] == 0)
                numbers[i] =11;
            int r_cnt = 0, l_cnt = 0;
            for(int j = -3; j<=3; j++){
                int x= numbers[i] + j*3;
                if(x >= 1 && x <= 12){
                    if(x == left){
                        l_cnt = abs(j);
                    }
                    else if(x - 1 == left){
                        l_cnt = abs(j) +1;
                    }
                    if(x == right){
                        r_cnt = abs(j);
                    }
                    else if(x + 1 == right){
                        r_cnt = abs(j) +1;
                    }
                }
            }
            if(l_cnt < r_cnt){
                left = numbers[i];
                answer += "L";
            }
            else if(l_cnt > r_cnt){
                right = numbers[i];
                answer += "R";
            }
            else{
                if(hand == "left"){
                    left= numbers[i];
                    answer += "L";
                }
                else{
                    right = numbers[i];
                    answer += "R";
                }
            }
        }
    }
    return answer;
}
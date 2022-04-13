#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<int> number, operand;
    string x= "";
    bool check_op[3] = {false, false, false};
    for(int i=0; i<expression.size(); i++){
        if(isdigit(expression[i]))
            x += expression[i];
        else{
            number.push_back(stoi(x));
            x = "";
            if(expression[i]=='+'){
                check_op[0] = true;
                operand.push_back(0);
            }
            else if(expression[i]=='-'){
                check_op[1] = true;
                operand.push_back(1);
            }
            else{
                check_op[2] = true;
                operand.push_back(2);
            }
        }
    }
    number.push_back(stoi(x));
    
    int count_op = 0;
    for(auto x:check_op)
        if(x)
            count_op++;
    if(count_op == 3)
        count_op = 6;
    
    int p[6][3] = {{0,1,2},{2,1,0},{1,0,2},{2,0,1},{1,2,0},{0,2,1}};
    stack<long long> num;
    stack<int> op;
    for(int i=0; i< count_op; i++){
        num.push(number[0]);
        for(int j=0; j<operand.size(); j++){
            if(op.empty()){
                num.push((long long)number[j+1]);
                op.push(operand[j]);
            }
            else{
                if(p[i][op.top()] >= p[i][operand[j]]){
                    while(!op.empty()){
                        int tmp_op = op.top();
                        long long tmp_num = num.top();
                        if(p[i][tmp_op]<p[i][operand[j]])
                            break;
                        num.pop();
                        if(tmp_op == 0){
                            tmp_num += num.top();
                        }   
                        else if(tmp_op == 1){
                            tmp_num = num.top() - tmp_num;
                        }
                        else{
                            tmp_num *= num.top();
                        }
                        num.pop();
                        op.pop();
                        num.push(tmp_num);
                        if(tmp_op == operand[j]){
                            break;
                        }
                    }
                }
                num.push((long long)number[j+1]);
                op.push(operand[j]);
            }
        }
        while(!op.empty()){
            long long tmp = num.top();
            num.pop();
            if(op.top() == 0)
                tmp += num.top();
            else if(op.top() == 1)
                tmp = num.top() - tmp;
            else
                tmp *= num.top();
            num.pop();
            op.pop();
            num.push(tmp);
        }
        long long res = abs(num.top());
        cout << res << " ";
        num.pop();
        answer = max(res, answer);
    }
    
    return answer;
}
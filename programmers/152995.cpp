#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp1(vector<int> &v1, vector<int> &v2){ 
    if(v1[0] > v2[0]){
        return true;
    }
    else if(v1[0] == v2[0]){
        if(v1[1] < v2[1])
            return true;
    }
    return false;
}
bool cmp2(vector<int> &v1, vector<int> &v2){
    return v1[0]+v1[1] < v2[0] + v2[1];
}


int main(){
  vector<vector<int>> scores = {{2,2}};

  int wanho_score1 = scores[0][0], wanho_score2 = scores[0][1];
    
    sort(scores.begin(), scores.end(), cmp1);
    
    int s1 = scores[0][0], s2 = scores[0][1];
    
    for(int i=0; i<scores.size(); i++){
        if(s1 > scores[i][0] && s2 > scores[i][1]){
            if(scores[i][0] == wanho_score1 && scores[i][1] == wanho_score2){
                cout << "-1" << endl;
                return 0;
            }
            scores[i][0] = -1;
            scores[i][1] = -1;
        }
        else{
            s1 = scores[i][0];
            s2 = scores[i][1];
        }
    }
    sort(scores.begin(), scores.end(), cmp2);
    
    for(auto score : scores)
      cout << score[0] << "  "<<score[1] << endl;
    int prize = 0, same_prize = 1, sum = 200001;
    
    for(int i=scores.size()-1; i >= 0; i--){
      cout << scores[i][0] << "????";
        if(sum > scores[i][0] + scores[i][1]){
            sum = scores[i][0] + scores[i][1];
            prize += same_prize;
            same_prize = 1;
        }
        else
            same_prize++;
        if(scores[i][0] == wanho_score1 && scores[i][1] == wanho_score2)
            cout <<  prize;
    }
}
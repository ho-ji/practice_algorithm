#include <string>
#include <vector>

using namespace std;

int room[9][9];

int find(){
    int xx[4] = {2,0,-2,0};
    int yy[4] = {0,2,0,-2};
    int x[4] = {1,0,-1,0};
    int y[4] = {0,1,0,-1};
    int dx[4] = {-1,-1,1,1};
    int dy[4] = {-1,1,-1,1};
    for(int i=2; i<7; i++){
        for(int j=2; j<7; j++){
            if(room[i][j] == 'P'){
                for(int k=0; k<4; k++){
                    if(room[i+xx[k]][j+yy[k]]=='P'){
                        if(room[i+x[k]][j+y[k]] != 'X')
                            return 0;
                    }
                    if(room[i+x[k]][j+y[k]] == 'P')
                        return 0;
                    if(room[i+dx[k]][j+dy[k]] == 'P'){
                        if(room[i+dx[k]][j]!='X' || room[i][j+dy[k]]!='X')
                            return 0;
                    }
                }
            }
        }
    }  
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int k=0; k<5; k++){
        for(int i=2; i<7;i++){
            for(int j=2; j<7; j++){
                room[i][j] = places[k][i-2][j-2];
            }
        }
        answer.push_back(find());
    }
            
    return answer;
}
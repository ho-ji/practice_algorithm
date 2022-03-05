#include <vector>

using namespace std;
vector<vector<int>> p;
int cnt;
void check(int x, int y, int c){
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<p.size()&&ny>=0&&ny<p[0].size()){
            if(p[nx][ny] == c){
                cnt++;
                p[nx][ny] = 0;
                check(nx,ny,c);
            }
        }
    }       
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    p.assign(m,vector<int>(n));
    copy(picture.begin(), picture.end(), p.begin());
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(p[i][j] != 0){
                cnt = 0;
                check(i,j,p[i][j]);
                if(cnt > max_size_of_one_area)
                    max_size_of_one_area = cnt;
                ++number_of_area;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
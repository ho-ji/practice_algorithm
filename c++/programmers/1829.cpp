#include <vector>
#include <queue>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    queue<pair<int,int>> q;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j] != 0){
                ++number_of_area;
                int cnt = 0;
                int paint_color = picture[i][j];
                picture[i][j]=0;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    ++cnt;
                    int x= q.front().first;
                    int y= q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(nx>=0 && nx<m && ny>=0 && ny<n && picture[nx][ny] == paint_color){
                            picture[nx][ny] = 0;
                            q.push(make_pair(nx,ny));
                        }
                    }
                }
                if(max_size_of_one_area < cnt)
                    max_size_of_one_area = cnt;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
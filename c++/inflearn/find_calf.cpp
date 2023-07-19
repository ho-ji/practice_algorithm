#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int line[10001];
int main(){
	int s, e, k;

	cin >> s >> e >> k;

	for(int i=0; i<k; i++){
		int x;
		cin >> x;
		line[x] = -1;
	}
	
	queue <int> q;
	
	int cnt = 0;
	q.push(s);

	while(!q.empty()){
		int s = q.size();

		for(int i=0; i<s; i++){
			int pos = q.front();
			q.pop();
			for(int nx : {pos+1, pos-1, pos+5}){
				if(nx == e){
					cout << cnt+1 << endl;
					return 0;
				}
				if(nx > 0 && nx <= 10000 && line[nx] == 0){
					line[nx] = 1;
					q.push(nx);
				}
			}
		}
		cnt++;
	}
	return 0;
}

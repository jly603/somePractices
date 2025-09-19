#include<bits/stdc++.h>
using namespace std;
int sum = 0, entry;
struct room {
	bool isStair;
	int times;
}tower[10001][101];
int main() {
	int N, M, floor = 1;
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		for(int j = 0; j < M; j++) {
			cin >> tower[i][j].isStair >> tower[i][j].times;
		}
	cin >> entry;
	int atRoom = entry;
	int times;
	while(floor < N) {
	    times = tower[floor][atRoom].times;
	    sum += times;
		while (times){
	        if(atRoom == M)
				atRoom = 0;
	        if(tower[floor][atRoom].isStair) times--;
			atRoom++;
		}
	    atRoom -= 1;
	    floor++;
	}
	cout << sum;
	return 0;
} 

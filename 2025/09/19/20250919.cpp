#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
#define ll long long
ll sum = 0, entry;
=======
int sum = 0, entry;
>>>>>>> ff8f549f06bbb3b1150ed81aa557c8dc17d41d5f
struct room {
	bool isStair;
	int times;
}tower[10001][101];
int main() {
	int N, M, floor = 1;
	cin >> N >> M;
<<<<<<< HEAD
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++) {
			cin >> tower[i][j].isStair >> tower[i][j].times;
			if (tower[i][j].isStair) tower[i][M].times++;
=======
	for(int i = 1; i <= N; i++)
		for(int j = 0; j < M; j++) {
			cin >> tower[i][j].isStair >> tower[i][j].times;
>>>>>>> ff8f549f06bbb3b1150ed81aa557c8dc17d41d5f
		}
	cin >> entry;
	int atRoom = entry;
	int times;
<<<<<<< HEAD
	while (floor <= N) {
		times = tower[floor][atRoom].times;
		sum += times;
		if (times % tower[floor][M].times)
			times %= tower[floor][M].times;
		else
			times = tower[floor][M].times;
		while (times) {
			if (atRoom == M)
				atRoom = 0;
			if (tower[floor][atRoom].isStair) times--;
			atRoom++;
		}
		atRoom -= 1;
		floor++;
	}
	cout << sum % 20123;
	return 0;
}
=======
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
>>>>>>> ff8f549f06bbb3b1150ed81aa557c8dc17d41d5f

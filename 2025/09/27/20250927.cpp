#include<iostream>
#define ll long long
using namespace std;
int m, n;
ll sum = 0;
struct node {
	int num;
	int step;
	ll path;
}sheet[31][31];
int main() {
	cin >> n >> m;
	//打表(num)
	for (int i = 1; i <= 30; i++) {
		int j = i % n, k = 1;
		while (k <= 30) {
			if (!j) j = n;
			sheet[i][k].num = j;
			k++; j--;
		}
	}
	//打表(step)
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			sheet[i][j].step = i + j - 1;
		}
	}
	//打表(path)
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			if (i == 1 || j == 1)
				sheet[i][j].path = 1;
			else {
				sheet[i][j].path = sheet[i - 1][j].path + sheet[i][j - 1].path;
			}
		}
	}
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			if (sheet[i][j].num == 1 && sheet[i][j].step == m)
			sum += sheet[i][j].path;
		}
	}
	cout << sum;
	return 0;
}

#include<iostream>
using namespace std;
int holes[21][21]; //有最多20个洞 
int tempPath[21], savePath[21];
int holeWent[21];
int n, mx = 0;
void saveResult() {
	int i = 1;
	while (savePath[i]) {
		savePath[i] = 0;
		i++;
	}
	i = 1;
	while (tempPath[i]) {
		savePath[i] = tempPath[i];
		i++;
	}
}
void merge(int atHole, int isPath, int sum, int path) {
	tempPath[path] = atHole;
	if (isPath) {
		holeWent[atHole] = 1;
		sum += holes[atHole][0];
		if (n - atHole)
		for (int i = 1; i <= n - atHole; i++) {
			merge(i + atHole, holes[atHole][i], sum, path + 1);
		}
		else {
			if (sum > mx) {
				saveResult();
				mx = sum;
			}
			tempPath[path] = 0;
			return;
		}
	}
	else {
		tempPath[path] = 0;
		if (sum > mx) {
			saveResult();
			mx = sum;
		}
		return;
	}
	tempPath[path] = 0;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> holes[i][0];
	}
	for (int i = 1; i <= n; i++) {
		if (n - i)
			for (int j = 1; j <= n - i; j++) {
				cin >> holes[i][j];
			}
	}
	int i = 1;
	while (i <= n) {
		while (holeWent[i]) i++;
		if (i <= n) merge(i, 1, 0, 1);
	}
	i = 1;
	while (savePath[i]) {
		cout << savePath[i] << " ";
		i++;
	}
	cout << endl << mx << endl;
	return 0;
}

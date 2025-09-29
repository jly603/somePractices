#include<iostream>
using namespace std;
int number[100001], min = 10000;
int main() {
	int n;
	cin >> n;
	int k = 1;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		if (i < 3) {
			k = i - 1;
			number[k] = num;
		}
		else {
			if((number[k] - num) * (number[k] - number[k - 1]) < 0) {
				k++; number[k] = num;
			}
		}
	}
	return 0;
}

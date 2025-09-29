#include<iostream>
using namespace std;
int n, k, sum = 0;
int number[10];
int saveData[7][201][201]; //remainNum, remainSum, num
void printNum() {
	for (int i = k; i > 0; i--)
		cout << number[i] << " ";
	cout << endl;
}
void merge(int remainNum, int remainSum, int num) {
	if (saveData[remainNum][remainSum][num])
		sum += saveData[remainNum][remainSum][num];
	else {
		number[remainNum] = num;
		if (remainNum == 1) {
			if (remainSum == num) {
				sum++;
				//printNum();
			}
			number[remainNum] = 0;
			return;
		}
		else {
			remainSum -= num;
			while (remainSum / (remainNum - 1) >= num) {
				merge(remainNum - 1, remainSum, num);
				num++;
			}
		}
		number[remainNum] = 0;
	}
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n / k; i++)
		merge(k, n, i);
	cout << sum << endl;
	return 0;
}

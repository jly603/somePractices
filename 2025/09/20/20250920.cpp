#include<iostream>
using namespace std;
#define ll long long
int main() {
	ll n, num = -1, sum = 0;
	ll back = -1, front = -1;
	ll p;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p;
		if (p != front) {
			back = num;
			num = front;
			front = p;
			if (back != -1 && (back - num) * (front - num) > 0)
				sum++;
		}
	}
	if (n == 1) cout << 1;
	else if (n == 2) {
		if (front == num) cout << 1;
		else cout << 2;
	}
	else if (sum + 2 > n) cout << n;
	else cout << sum + 2;
	return 0;
}

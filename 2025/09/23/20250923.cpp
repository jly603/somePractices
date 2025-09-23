#include<iostream>
#include<algorithm>
#define ll long long
#define MAX 0xFFFFFFFF
using namespace std;
ll a[10001];
void chg(int p, int q) {
	int temp = a[p]; 
	a[p] = a[q]; a[q] = temp;
}
int main() {
	ll n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int times = 0;
	while (times < n - 1) {
		sum += a[times] + a[times + 1];
		a[times + 1] += a[times];
		int t = times + 1;
		while ((a[t] > a[t + 1]) && (t < n - 1)) {
			chg(t, t + 1);
			t++;
		}
		times++;
	}
	cout << sum << endl;
	return 0;
}

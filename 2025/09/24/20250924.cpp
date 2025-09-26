#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int nodeLink[200001][1001];
// int calc(int node, int num) {
// 	return;
// }
int main() {
	cin >> n;
	int node1, node2;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &node1, &node2);
		nodeLink[node1][0]++;
		nodeLink[node2][0]++;
		nodeLink[node1][nodeLink[node1][0]] = node2;
		nodeLink[node2][nodeLink[node2][0]] = node1;
	}
	return 0;
}

今天再做一道题。

<hr>

> # P1025 [NOIP 2001 提高组] 数的划分
>
> ## 题目描述
>
> 将整数 $n$ 分成 $k$ 份，且每份不能为空，任意两个方案不相同（不考虑顺序）。
>
> 例如：$n=7$，$k=3$，下面三种分法被认为是相同的。
>
> $1,1,5$;   
> $1,5,1$;   
> $5,1,1$.
>
> 问有多少种不同的分法。
>
> ## 输入格式
>
> $n,k$ （$6<n \le 200$，$2  \le k  \le  6$）
>
> ## 输出格式
>
> $1$ 个整数，即不同的分法。
>
> ## 输入输出样例 #1
>
> ### 输入 #1
>
> ```
> 7 3
> ```
>
> ### 输出 #1
>
> ```
> 4
> ```
>
> ## 说明/提示
>
> 四种分法为：  
> $1,1,5$;  
> $1,2,4$;  
> $1,3,3$;  
> $2,2,3$.
>
> **【题目来源】**
>
> NOIP 2001 提高组第二题

<hr>

好像有点摸不明白。

这道题应该是用递归去做，且后出现的数只会比前出现的数大。

具体分为两个变量：

`num` ：到这一步最小是什么数字。

`step` ：一个分了几个数字（到k为止）。

草。甚至不用减脂。

```c++
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
```

要减脂就似了，用的是 `void` 写的递归。


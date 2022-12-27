[题目传送门](https://www.luogu.com.cn/problem/P8377)

## 题意简述

本题是求斐波那契数列前 $n$ 项的数字之和对 $9$ 取余数之后的运算结果。

## 题目分析

这道题明显是一道数学题，涉及到了**递推**算法。

设 $g_i$ 为 $(S(fib(1))+S(fib(2))+S(fib(3))+...+S(fib(i)))$ 的值，$f_i$ 为 $g_i \bmod 9$ 的值。

$i=[1,10]$ 时，$fib(i)$、$S(fib(i))$、$f_i$ 的值分别如下：

$i=1,fib(i)=1,S(fib(i))=1,g_i=1,f_i=1$

$i=2,fib(i)=1,S(fib(i))=1,g_i=2,f_i=2$

$i=3,fib(i)=2,S(fib(i))=2,g_i=4,f_i=4$

$i=4,fib(i)=3,S(fib(i))=3,g_i=7,f_i=7$

$i=5,fib(i)=5,S(fib(i))=5,g_i=12,f_i=3$

$i=6,fib(i)=8,S(fib(i))=8,g_i=20,f_i=2$

$i=7,fib(i)=13,S(fib(i))=4,g_i=33,f_i=6$

$i=8,fib(i)=21,S(fib(i))=3,g_i=54,f_i=0$

$i=9,fib(i)=34,S(fib(i))=7,g_i=88,f_i=7$

$i=10,fib(i)=55,S(fib(i))=10,g_i=143,f_i=8$

我们很容易发现，$f$ 数组的第 $1$ 项是 $1$，第 $2$ 项是 $2$，从第 $3$ 项开始，每一个数都是前两项之和加 $1$ 并对 $9$ 取余数，即：

$f_1=1,f_2=2,f_i=(f_{i-1}+f_{i-2}) \bmod 9$

**代码实现**

```cpp
f[1] = 1, f[2] = 2;	//初始化
for (int i = 3; i <= n; i++)	f[i] = (f[i - 1] + f[i - 2] + 1) % 9;	//递推
```

由于每个测试点有**多组测试数据**，下面的优化技巧使时间复杂度从 $O(\Sigma{n})$ 降为 $O(max(n))$。

设 $maxn$ 为已经更新的 $f_i$ 的个数。因为我们已经知道 $f_1=1,f_2=2$，所以 $maxn$ 的初始值为 $2$。

- 如果新输入的 $n$ 大于 $maxn$，就需要从 $f_{maxn+1}$ 递推到 $n$，并更新 $maxn$ 的值为 $n$。

- 如果新输入的 $n$ 小于或等于 $maxn$，直接输出 $f_n$ 即可。

## 参考代码

```cpp
#include <cstdio>
int T, n, maxn = 2, f[1000005];
int main() {
	scanf("%d", &T);
	f[1] = 1, f[2] = 2;	//初始化
	while (T--) {
		scanf("%d", &n);
		if (n > maxn) {
			for (int i = maxn + 1; i <= n; i++)	f[i] = (f[i - 1] + f[i - 2] + 1) % 9;	//递推
			maxn = n;	//更新 maxn 的值
		}
		printf("%d\n", f[n]);
	}
	return 0;
}
```

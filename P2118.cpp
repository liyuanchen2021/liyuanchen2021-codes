#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
	if (b == 0)	return a;
	return gcd(b, a % b);
}
int main() {
	int a, b, l;
	cin >> a >> b >> l;
	int t = gcd(a, b);
	a /= t, b /= t;
	double base = 1.0 * a / b;
	if (a > l || b > l) {
		double MIN = 1e9;
		int A, B;
		for (int i = 1; i <= l; i++)
			for (int j = 1; j <= l; j++)
				if (1.0 * i / j > base && 1.0 * i / j - base < MIN)
					MIN = 1.0 * i / j - base, A = i, B = j;
		a = A, b = B;
	}
	cout << a << ' ' << b << endl;
	return 0;
}

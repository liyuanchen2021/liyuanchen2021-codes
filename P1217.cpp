#include <iostream>
#include <cmath>
using namespace std;
void sum(int &a, int b) {
    a = a * 10 + b;
}
bool isprime(int n) {
	if (n == 1)	return false;
	if (n == 2)	return true;
	for (int i = 2; i <= sqrt(n); ++i)
		if (n % i == 0)	return false;
	return true;
}
int main() {
	int a, b, d1, d2, d3, d4, n1;
	int zhi[4] = {1, 3, 7, 9};
	cin >> a >> b;
	if (a <= 5 && b >= 5)   cout << 5 << endl;
	if (a <= 7 && b >= 7)   cout << 7 << endl;
	if (a <= 11 && b >= 11) cout << 11 << endl;
	for (d1 = 0; d1 < 4; d1++) {
		for (d2 = 0; d2 <= 9; d2++) {
			n1 = 0;
			sum(n1, zhi[d1]);
			sum(n1, d2);
			sum(n1, zhi[d1]);
			if (n1 > b)	return 0;
			if (n1 < a)	continue;
			if (isprime(n1))    cout << n1 << endl;
		}
	}
	for (d1 = 0; d1 < 4; d1++) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				n1 = 0;
				sum(n1, zhi[d1]);
				sum(n1, d2);
				sum(n1, d3);
				sum(n1, d2);
				sum(n1, zhi[d1]);
				if (n1 > b)	return 0;
				if (n1 < a)	continue;
				if (isprime(n1))    cout << n1 << endl;
			}
		}
	}
	for (d1 = 0; d1 < 4; d1++) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				for (d4 = 0; d4 <= 9; d4++) {
					n1 = 0;
					sum(n1, zhi[d1]);
					sum(n1, d2);
					sum(n1, d3);
					sum(n1, d4);
					sum(n1, d3);
					sum(n1, d2);
					sum(n1, zhi[d1]);
					if (n1 > b)	return 0;
					if (n1 < a)	continue;
					if (isprime(n1))    cout << n1 << endl;
				}
			}
		}
	}
	return 0;
}

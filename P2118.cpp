#include <iostream>
using namespace std;
int main() {
	int a, b, l;
	cin >> a >> b >> l;
	int nowa = 1, nowb = 1, ansa = l, ansb = 1;
	while (nowa <= l && nowb <= l) {
		if (nowa * b >= a * nowb) {
			if (nowa * ansb < ansa * nowb)
				ansa = nowa, ansb = nowb;
			nowb++;
		}
		else	nowa++;
	}
	cout << ansa << ' ' << ansb << endl;
	return 0;
}

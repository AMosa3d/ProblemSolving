//Problem Link : https://codeforces.com/problemset/problem/1221/C

#include<iostream>

using namespace std;

long long min(long long a, long long b, long long c) {
	return a < b ? a < c ? a : c : b < c ? b : c;
}

long long min1(long long a, long long b) {
	return a < b ? a : b;
}

long long max1(long long a, long long b) {
	return a > b ? a : b;
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		long long c, m, x; cin >> c >> m >> x;
		long long mi = min(c, m, x);
		c -= mi, x -= mi, m -= mi;
		if (!c || !m) cout << mi << endl;
		else {
			if (m == c)
				cout << mi + (c / 3) * 2 + (c % 3 == 2) << endl;
			else
			{
				long long mn = min1(c, m);
				long long mx = max1(c, m);
				long long diff = mx - mn;
				long long f = (max1(0, mn - diff) / 3) * 2 + (max1(0, mn - diff) % 3 == 2);
				cout << mi + min1(diff, mn) + f << endl;
			}
		}
	}


	return 0;
}

// Problem Link : https://codeforces.com/contest/166/problem/C

#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<fstream>
#include<algorithm>
#include<math.h>
#include<iomanip>

#define ll long long

using namespace std;

int n, x;
int a[502];

int calculateDiffrence(int pos) {
	int r = n - pos;
	int l = pos - 1;
	int res = 0;

	if ((n + 1) / 2 >= pos)
		res += r - l - 1;
	else
		res += l - r;

	return res;
}

int main() {
	bool found = false;
	cin >> n >> x; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		found = a[i] == x || found ? true : false;
	}
	if (!found)
		a[n + 1] = x, n++;
	sort(a, a + n + 1);

	int sPos = -1, ePos = -1;
	for (int i = 1; i <= n; i++) {
		if (x == a[i] && sPos < 0)
			sPos = i;
		if (x == a[i])
			ePos = i;
	}

	int res = !found;

	if (sPos <= ((n + 1) / 2) && ePos >= ((n + 1) / 2))
		cout << res << endl;
	else
		cout << res + min(calculateDiffrence(sPos), calculateDiffrence(ePos)) << endl;

	return 0;
}

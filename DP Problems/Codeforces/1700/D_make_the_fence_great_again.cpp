// Problem Link : https://codeforces.com/problemset/problem/1221/D

#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<fstream>
#include<algorithm>
#include<math.h>
#include<iomanip>

#define ull unsigned long long
#define ll long long

using namespace std;

const int MAX_SIZE = 300001;
ull INF = 1000000000000000000;
ull a[MAX_SIZE], b[MAX_SIZE];
ull dp[MAX_SIZE][3];
int n;

ull min(ull a, ull b) {
	return a < b ? a : b;
}

ull solve() {

	dp[0][0] = 0;
	dp[0][1] = b[0];
	dp[0][2] = 2 * b[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = INF;
		dp[i][1] = INF;
		dp[i][2] = INF;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (a[i] + j == a[i - 1] + k) {
					continue;
				}
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j * b[i]));
			}
		}
	}

	ull res = INF;
	for (int j = 0; j < 3; j++) {
		 res = min(res, dp[n - 1][j]);
	}

	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a[j] >> b[j];
		}

		cout << solve() << endl;
	}

	return 0;
}

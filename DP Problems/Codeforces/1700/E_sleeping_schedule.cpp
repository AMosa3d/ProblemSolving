// Problem Link : https://codeforces.com/problemset/problem/1324/E

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

int n, h, l, r;
int dp[2001][2001];

int max(int a, int b) {
	return a > b ? a : b;
}

int solveByDP(int arr[], int i, int current) {
	if (i >= n)
		return (current >= l && current <= r);

	if (dp[i][current] == -1) {
		int a = solveByDP(arr, i + 1, (current + arr[i]) % h);
		int b = solveByDP(arr, i + 1, (-1 + current + arr[i]) % h);

		dp[i][current] = max(a, b);
		if (current >= l && current <= r)
			dp[i][current]++;
	}
	return dp[i][current];
}

int main() {
	cin >> n >> h >> l >> r;
	int *arr = new int[n];
	memset(dp, -1, sizeof(dp[0][0]) * 2001 * 2001);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << max(solveByDP(arr, 1, arr[0]%h), solveByDP(arr, 1, (arr[0] - 1)%h)) << endl;
	return 0;
}

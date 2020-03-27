// Problem Link : https://codeforces.com/problemset/problem/474/D
 
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
 
const int MAX = 100001;
ll mod = 1000000007;
ll dp[MAX];
 
ll calculate_eats_with_mod(ll prev, ll prev_k, int k, int i) {
	if (k == 1)
		return (prev * 2) % mod;
 
	return (prev + prev_k) % mod;
}
 
void build_dp_array(int k) {
	//calculate simply
	dp[k] = 2;
	for (int i = 1; i < k; i++)
		dp[i] = 1;
 
	for (int i = k + 1; i < MAX; i++)
		dp[i] = calculate_eats_with_mod(dp[i - 1], dp[i - k], k, i);
 
 
	for (int i = 1; i < MAX; i++) {
		dp[i] = (dp[i - 1] + dp[i]) % mod;
	}
}
 
int main() {
	memset(dp, 0, sizeof(dp[0]) * MAX);
	int t, k; cin >> t >> k;
	build_dp_array(k);
	for (int i = 0, a, b; i < t; i++) {
		cin >> a >> b;
		cout << (dp[b] - dp[a-1] + mod) % mod << endl;
	}
	return 0;
}

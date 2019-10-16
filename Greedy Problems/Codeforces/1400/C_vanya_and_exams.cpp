// Problem Link : https://codeforces.com/problemset/problem/492/C

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
 
struct exam {
	int x_, y_;
};
exam arr[100001];
 
int main() {
	ll n, avg; ll r; cin >> n >> r >> avg;
	for (int i = 0; i < n; i++)cin >> arr[i].x_ >> arr[i].y_;
	sort(arr, arr + n, [](const auto&l, const auto&r) {
		return l.y_ < r.y_;
	});
	ll sum = 0;
	for (int i = 0; i < n; i++)sum += arr[i].x_;
	ll miin = 0;
	for (int i = 0; i < n && sum < avg * n; i++) {
		ll needed = min(avg*n - sum, r-arr[i].x_);
		sum += needed;
		miin += needed * arr[i].y_;
	}
	cout << miin << endl;
	return 0;
}

// Problem Link : https://codeforces.com/problemset/problem/1301/C
 
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
 
ll getMaxOfAyoubFunction(ll n, ll m) {
	ll numberOfZeros = n - m; ll numberOfOptimalZeroGroups = m + 1; ll numberOfZerosPerGroup = numberOfZeros / numberOfOptimalZeroGroups;
	return (n * (n+1) / 2)
			- ((numberOfZerosPerGroup + 1) * (numberOfZerosPerGroup + 2) / 2) * (numberOfZeros % numberOfOptimalZeroGroups)
			- (numberOfZerosPerGroup * (numberOfZerosPerGroup + 1) / 2) * (numberOfOptimalZeroGroups - numberOfZeros % numberOfOptimalZeroGroups);
}
 
int main() {
	int t; ll n, m; cin >> t;
	for (int i = 0; i < t && cin >> n >> m; i++)
		cout << getMaxOfAyoubFunction(n, m) << endl;
	return 0;
}

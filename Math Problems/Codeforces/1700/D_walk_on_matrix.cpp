// Problem Link : https://codeforces.com/problemset/problem/1332/D
 
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
 
#define ll long long
 
using namespace std;
 
/*
	the solution is to get number let's call mx = 2^17 or = 2^x such that 2^x > k
	then mx should be :
	- mx > k and
	- mx & k = 0
 
	this would force you to take a path that not the max but k at cell(1,1) 
	so you can and it with cell(2,1) which equal to k to get then k difference
*/
 
int get_mx(int k) {
	int res = 1;
	while (res <= k) {
		res *= 2;
	}
	return res;
}
 
int main() {
	int k;
	cin >> k;
 
	cout << "2 3" << endl;
	int mx = get_mx(k);
	cout << (mx^k) << " " << mx << " 0" << endl;
	cout << k << " " << (mx^k) << " " << k << endl;
 
	return 0;
}

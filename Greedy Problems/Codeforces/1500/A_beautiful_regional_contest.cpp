// Problem Link : https://codeforces.com/problemset/problem/1264/A
 
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
 
int sizeOfTrimmedArr(int n);
 
int a[4 * 100001];
 
int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		int g = 1, s = 0, index = 1, gp = a[0], sp;
		
		//count max number coocurence
		for (; index < n && a[index] == gp; index++, g++);
		
		
		index = index + g;
		if (index >= n) {
			cout << "0 0 0" << endl;
			continue;
		}
		sp = a[index++];
		s = g + 1;
		//count coocurence of the last silver
		for (; index < n && a[index] == sp; index++, s++);
 
		
		int half = n / 2;
		for (int k = half - 1; k >= 0 && a[k] == a[k + 1]; k--, half--);
		if (s + 2 * g + 1 > half) {
			cout << "0 0 0" << endl;
			continue;
		}
 
 
		cout << g << " " << s << " " << half - s - g << endl;
	}
	return 0;
}

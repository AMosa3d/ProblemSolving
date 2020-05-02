// Problem Link : https://codeforces.com/problemset/problem/1348/A

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
 
int main() {
	int t;
	cin >> t;
	for(int i=0;i < t;i ++) {
        int n;
        cin >> n;
        ll a = 0, b = 0;
        ll twos = 1;
        for (int i = 0; i < n/2 - 1;i++) {
            twos*=2;
            a+= twos;
        }
        for (int i = 0; i < n/2;i++) {
            twos*=2;
            b+= twos;
        }
        twos*=2;
        a+= twos;
        cout << a-b << endl;
	}
 
	return 0;
}

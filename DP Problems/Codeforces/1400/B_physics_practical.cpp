// Problem Link : https://codeforces.com/problemset/problem/253/B

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
 
const int MAX = 5001;
int dp[MAX][MAX];
int arrCount[MAX];
 
int solveWithDP(int startIndex, int endIndex) {
 
	if (startIndex > endIndex)
		return 100001;
	if (arrCount[startIndex] == 0)
		return solveWithDP(startIndex + 1, endIndex);
	if (arrCount[endIndex] == 0)
		return solveWithDP(startIndex, endIndex - 1);
	if (endIndex <= 2 * startIndex)
		return 0;
 
	if (dp[startIndex + 1][endIndex] == -1)
		dp[startIndex + 1][endIndex] = solveWithDP(startIndex + 1, endIndex);
 
	if (dp[startIndex][endIndex - 1] == -1)
		dp[startIndex][endIndex - 1] = solveWithDP(startIndex, endIndex - 1);
 
	return min(
		arrCount[startIndex] + dp[startIndex + 1][endIndex],
		arrCount[endIndex] + dp[startIndex][endIndex - 1]
	);
}
 
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		fin >> x;
		arrCount[x]++;
	}
 
	memset(dp, -1, sizeof dp);
 
	fout << solveWithDP(1, 5000) << endl;
	return 0;
}

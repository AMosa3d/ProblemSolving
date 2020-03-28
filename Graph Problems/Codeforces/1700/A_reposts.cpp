// Problem Link : https://codeforces.com/problemset/problem/522/A

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

int n, graph[201][201];
string s;
map<string, int> user_index_map;

int max(int a, int b) {
	return a > b ? a : b;
}

int insert_user_and_get_index(string name) {
	int index = user_index_map.size();
	user_index_map[name] = index;
	return index;
}

int get_user_index(string name) {
	if (user_index_map.find(name) == user_index_map.end())
		return insert_user_and_get_index(name);
	return user_index_map[name];
}

// leads to MLE
int solve_by_DFS(int root, int i) {
	if (i >= user_index_map.size())
		return 0;

	int res = 0;

	for (int j = 0; j < user_index_map.size(); j++) {
		if (graph[i][j] == 0)
			res = max(solve_by_DFS(i, j), res);
	}
	graph[root][i] = res + 1;
	return graph[root][i];
}

// leads to TLE
int solve_by_BFS() {
	int current_level = -1;
	int res = 0;

	// pair of <index of user, it's level>
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		if (current_level != current.second) {
			res++;
			current_level++;
		}

		for (int j = 0; j < user_index_map.size(); j++) {
			if (!graph[current.first][j]) {
				q.push(make_pair(j, current.second + 1));
			}
		}
	}

	return res;
}

int main() {
	user_index_map.emplace(pair<string, int>("polycarp", 0));
	memset(graph, -1, sizeof(int) * 201 * 201);
	graph[0][0] = 1;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, s);	
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		
		string names[2];
		names[0] = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1, s.length());
		names[1] = s.substr(s.find(" ") + 1, s.length());

		int posted_user_index = get_user_index(names[1]), reposted_user_index = get_user_index(names[0]);
		graph[posted_user_index][reposted_user_index] = 0;
		graph[reposted_user_index][0] = graph[posted_user_index][0] + 1;
	}

	int res = 0;

	for (int i = 0; i < user_index_map.size(); i++)
		for (int j = 0; j < user_index_map.size(); j++)
			res = max(res, graph[i][j]);

	cout << res << endl;

	return 0;
}

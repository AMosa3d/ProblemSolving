// Problem Link : https://codeforces.com/problemset/problem/852/G

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

class TrieNode {
public:
	char c;
	int count = 0;
	int visited_pattern = -1;
	TrieNode* childs[5] = {};

	TrieNode(char c) {
		this->c = c;
	}
};

TrieNode* get_node_ptr(TrieNode* parent, char c) {
	TrieNode* ptr = parent->childs[c - 'a'];
	
	if (ptr == NULL) {
		ptr = new TrieNode(c);
		parent->childs[c -'a'] = ptr;
	}

	return ptr;
}

void insert_in_tree(TrieNode* root, string s) {
	TrieNode* ptr = root;
	int i;

	for (i = 0; i < s.size() - 1; i++) {
		ptr = get_node_ptr(ptr, s[i]);
	}

	get_node_ptr(ptr, s[i])->count++;
}

ll find_matches_in_tree(TrieNode* root, string s, int pattern_index) {

	ll res = 0;
	int s_size = s.size();
	queue<pair<TrieNode*, int>> q;
	q.push(pair<TrieNode*, int>(root, 0));
	while (!q.empty()) {
		TrieNode* ptr = q.front().first;
		int i = q.front().second;
		q.pop();

		if (i > s_size) {
			continue;
		}

		if (i == s_size) {
			if (ptr->visited_pattern != pattern_index) {
				res += ptr->count;
				ptr->visited_pattern = pattern_index;
			}
			continue;
		}

		if (s[i] == '?') {
			for (int j = 0; j < 5; j++) {
				if (ptr->childs[j] == NULL) {
					continue;
				}

				q.push(make_pair(ptr->childs[j], i+1));
			}

			q.push(make_pair(ptr, i + 1));
			continue;
		}

		if (ptr->childs[s[i] - 'a'] == NULL) {
			continue;
		}

		q.push(make_pair(ptr->childs[s[i] - 'a'], i+1));
	}

	return res;
}

int main() {
	TrieNode* root = new TrieNode('0');
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		insert_in_tree(root, s);
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		cout << find_matches_in_tree(root, s, i) << endl;
	}
	return 0;
}

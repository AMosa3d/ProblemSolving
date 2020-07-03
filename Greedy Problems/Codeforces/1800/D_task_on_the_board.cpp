// Problem Link : https://codeforces.com/contest/1367/problem/D
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const int CHAR_SET_BEFORE = -1;

string build_string(vector<char> chars_arr) {
    string res = "";
    for(int i=0;i < chars_arr.size();i++) {
        res += chars_arr[i];
    }
    return res;
}

bool has_zeros(vector<int>& arr) {
    for(int i=0;i<arr.size();i++) {
        if(arr[i] == 0)
            return true;
    }

    return false;
}

vector<int> get_zeros_positions(vector<int>& arr) {
    vector<int> res;
    for(int i = 0;i < arr.size();i++) {
        if(arr[i] == 0) {
            res.push_back(i);
        }
    }
    return res;
}

bool is_zero_position(vector<int>& zeros_pos, int pos) {
    for(int i = 0;i < zeros_pos.size();i++) {
        if(zeros_pos[i] == pos)
            return 1;
    }
    return 0;
}

void subtract_zero_distances(vector<int>& arr, vector<int>& zeros_pos) {
    for(int i=0;i < arr.size();i++) {
        if(is_zero_position(zeros_pos, i) || arr[i] == CHAR_SET_BEFORE) {
            continue;
        }
        for(int j = 0;j < zeros_pos.size();j++) {
            arr[i] -= abs(i - zeros_pos[j]);
        }
    }
}

void set_zeros_to_unusable(vector<int>& arr, vector<int>& zeros_pos) {
    for(int i = 0;i < zeros_pos.size();i++) {
        arr[zeros_pos[i]] = CHAR_SET_BEFORE;
    }
}

void fill_vector(vector<char>& arr, vector<int>& zeros_pos, char c) {
    for(int i=0;i < zeros_pos.size();i++)
        arr[zeros_pos[i]] = c;
}

char get_last_correct_char(vector<int>& chars_count, int needed_count) {
    for(int i = 25;i>-1;i--) {
        if(chars_count[i] >= needed_count) {
            chars_count[i] = 0;
            return 'a' + i;
        }
        chars_count[i] = 0;
    }
}

string solve(string s, int n, vector<int>& arr) {
    vector<int> chars_count(26, 0);
    for(int i=0;i< s.length();i++) {
        chars_count[s[i] - 'a']++;
    }

    vector<char> res_arr(n);
    while(has_zeros(arr)) {
        vector<int> zeros_pos = get_zeros_positions(arr);
        char c = get_last_correct_char(chars_count, zeros_pos.size());
        fill_vector(res_arr, zeros_pos, c);
        subtract_zero_distances(arr, zeros_pos);
        set_zeros_to_unusable(arr, zeros_pos);
    }

    return build_string(res_arr);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
        string s;
        int n;
        cin>>s>>n;
        vector<int> arr(n);
        for(int j=0;j < n;j++) {
            cin>>arr[j];
        }
        cout << solve(s, n, arr) << endl;
	}

	return 0;
}

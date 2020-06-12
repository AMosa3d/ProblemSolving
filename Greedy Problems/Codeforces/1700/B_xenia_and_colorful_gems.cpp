// Problem Link : https://codeforces.com/problemset/problem/1336/B
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll ans = 3e18;

ll bs_lower_bound(vector<ll>& a, ll v, int s, int e) {
    if(s >= e) {
        if(a[e] <= v) {
            return a[e];
        } if(e != 0) {
            return a[e-1];
        }
        return 0 * ans;
    }

    int mid = s + (e-s)/2;

    if(a[mid] < v) {
        s = mid+1;
    } else {
        e = mid;
    }
    return bs_lower_bound(a, v, s, e);
}

ll bs_upper_bound(vector<ll>& a, ll v, int s, int e) {
    if(e <= s) {
        if(a[s] >= v) {
            return a[s];
        } else if(s != a.size() - 1) {
            return a[s+1];
        }
        return 0;
    }

    int mid = e - (e-s)/2;

    if(a[mid] > v) {
        e = mid-1;
    } else {
        s = mid;
    }
    return bs_upper_bound(a, v, s, e);
}

ll min(ll a, ll b) {
    return a < b ? a : b;
}

ll eq(ll x, ll y, ll z) {
    if(x == 0 || z == 0) {
        return ans;
    }
    ll res1 = (x-y) * (x-y);
    ll res2 = (y-z) * (y-z);
    return (res1) +
        res2 +
        ((z - x) * (z - x));
}

ll solve(vector<ll>& a, vector<ll>& b, vector<ll>& c) {
    ll res = ans;
    int n = b.size();
    int ea = a.size()-1;
    int ec = c.size()-1;
    for(int i = 0; i < n; i++) {
        ll lb = bs_lower_bound(a, b[i], 0, ea);
        ll ub = bs_upper_bound(c, b[i], 0, ec);
        res = min(res, eq(lb, b[i], ub));
    }

    return res;
}

int main() {
	int t,nr,nb,ng;
	cin >> t;
	ll res;
	for(int i=0;i < t;i++) {
        res = ans;
        cin>>nr>>nb>>ng;
        vector<ll> r(nr);
        vector<ll> b(nb);
        vector<ll> g(ng);

        for(int j = 0;j < nr;j++) cin >> r[j];
        for(int j = 0;j < nb;j++) cin >> b[j];
        for(int j = 0;j < ng;j++) cin >> g[j];
        sort(r.begin(), r.end());
        sort(b.begin(), b.end());
        sort(g.begin(), g.end());

        res = min(res, solve(r, b, g));
        res = min(res, solve(r, g, b));
        res = min(res, solve(b, r, g));
        res = min(res, solve(b, g, r));
        res = min(res, solve(g, r, b));
        res = min(res, solve(g, b, r));

        cout << res << endl;
	}

	return 0;
}

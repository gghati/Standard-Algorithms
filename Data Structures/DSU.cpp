//Struct Implementation :
struct DSU
{
    int connected;
    vector<int> par, sz;

    void init(int n)
    {
        par = sz = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
        connected = n;
    }

    int getPar(int k)
    {
        while (k != par[k])
        {
            par[k] = par[par[k]];
            k = par[k];
        }
        return k;
    }

    int getSize(int k)
    {
        return sz[getPar(k)];
    }

    void unite(int u, int v)
    {
        int par1 = getPar(u), par2 = getPar(v);

        if (par1 == par2)
            return;

        connected--;

        if (sz[par1] > sz[par2])
            swap(par1, par2);

        sz[par2] += sz[par1];
        sz[par1] = 0;
        par[par1] = par[par2];
    }
};

/*Example
Problem : https://codeforces.com/contest/1559/problem/D1
Solution : 

 
#include <bits/stdc++.h>
using namespace std;

#define bolt ios::sync_with_stdio(0);cin.tie(0);
#define test int t; cin>>t; while(t--)
#define int long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<=b;i++)
#define REPI(i,a,b) for(ll i=b;i>=a;i--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define db pop_back
#define F first
#define S second
#define I insert
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define lb lower_bound
#define ub upper_bound
#define ms(s, n) memset(s, n, sizeof(s))
const ld PI = acos(-1);
const ll N = 2e6 + 10;
const ll mod = 1e9 + 7;
const int mod1 = 998244353;
const ll inf = 2e18;

struct DSU
{
    int connected;
    vector<int> par, sz;
 
    void init(int n)
    {
        par = sz = vector<int> (n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
        connected = n;
    }
 
    int getPar(int k)
    {
        while (k != par[k])
        {
            par[k] = par[par[k]];
            k = par[k];
        }
        return k;
    }
 
    int getSize(int k)
    {
        return sz[getPar(k)];
    }
 
    void unite(int u, int v)
    {
        int par1 = getPar(u), par2 = getPar(v);
 
        if (par1 == par2)
            return;
 
        connected--;
 
        if (sz[par1] > sz[par2])
            swap(par1, par2);
 
        sz[par2] += sz[par1];
        sz[par1] = 0;
        par[par1] = par[par2];
    }
};
 
void solve() {
    int n , m , m1; cin >> n >> m >> m1;
    DSU diana, mocha;
    diana.init(n);
    mocha.init(n);
    while (m--) {
        int x, y; cin >> x >> y;
        diana.unite(x, y);
    }
 
    while (m1--) {
        int x, y; cin >> x >> y;
        mocha.unite(x, y);
    }
    vector<pll> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n ; j++) {
            if ((diana.getPar(i) != diana.getPar(j)) && (mocha.getPar(i) != mocha.getPar(j))) {
                ans.pb({i, j});
                diana.unite(i, j);
                mocha.unite(i, j);
            }
        }
    }
 
    cout << (int)ans.size() << endl;
    for (auto it : ans) {
        cout << it.F << " " << it.S << endl;
    }
}
 
void init() {
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
}
 
signed main()
{
    // init();
    bolt; cout << fixed << setprecision(10);
    //test
    {
        solve();
    }
    return 0;
}
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

// typedef long long ll;
#define ll long long
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll int, ll int> pll;
typedef pair<double, double> pdd;
typedef vector<ll int> vll;
typedef vector<int> vii;
typedef vector<bool> vb;
typedef vector<vector<int>> vvii;
typedef vector<vector<ll int>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vp;
typedef vector<pii> vpii;
#define forn(i, s) for (ll i = 0; i < s; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define dbg(x) cout << #x << " = " << x << endl
#define mp make_pair
#define pb push_back
// #define F first
// #define S second
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const double eps = 1e-12;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const ll INF = 1e18;
#define endl "\n"
#define Endl "\n"


void Union(ll int parent[], ll int x, ll int y)
{
    parent[x] = y;
}

ll int find(ll int parent[], ll int x)
{
    if(parent[x] == -1)
    return x;
    return find(parent, parent[x]);
}

bool isCycle(ll int n, vp &edges)
{
    ll int i;
    ll int parent[n+1];

    for(i=0;i<=n;i++)parent[i] = -1;

    for(i=0;i<edges.size();i++)
    {   

        ll int x = find(parent, edges[i].first);
        ll int y = find(parent, edges[i].second);

        if(x == y)
        return true;

        Union(parent, x, y);
    }

    return false;
}


int main()
{
    ll int n, m, i;
    cin >> n >> m;
    
    vp edges;


    for(i=0;i<m;i++)
    {
        ll int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.pb({u,v});
    }

    if(isCycle(n, edges))
    cout << "Cycle present\n";
    else
    cout << "graph doesn't contain cycle\n";

    return 0;
}
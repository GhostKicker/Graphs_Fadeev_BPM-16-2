#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <sstream>
#include <string>
#include <algorithm>
#include <tuple>
#ifdef _DEBUG
#include <Windows.h>
#endif
#define endl "\n"
#define fs first
#define sd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define deb(x) cout<<(x).size()<<": ";for(auto mew : (x))cout<<mew<<" ";cout<<endl;
#define deb_pair(x) cout<<(x).size()<<": ";for(auto mew : (x))cout<<mew.fs<<" "<<mew.sd<<endl;
#define cin_ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef double db;
typedef tuple<ll, ll, ll> t3;
typedef vector<string> vstr;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pli;
typedef pair<ll, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<db> vdb;
ll inf = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct Graph
{
    struct dsu
    {

        vector<ll> p, r;
        dsu() {};
        dsu(ll n)
        {
            p.resize(n);
            r.assign(n, 1);
            for (ll i = 0; i < n; i++) p[i] = i;
        }
        ll root(ll v)
        {
            ll res = v;

            while (res != p[res])
                res = p[res];

            while (v != res)
            {
                ll tmp = v;
                v = p[v];
                p[tmp] = res;
            }

            return res;
        }
        void unite(ll a, ll b)
        {
            a = root(a);
            b = root(b);
            if (a == b) return;
            if (r[a] < r[b]) swap(a, b);
            p[b] = a;
            r[a] += r[b];
        }
    };

    vector<t3> edges;
    ll n;
    Graph(vector<t3>& e, ll n_)
        : edges(e)
        , n(n_)
    {
    }

    ll kruscal()
    {
        ll res = 0;
        ll remaining = n - 1;
        dsu d(n);
        auto ed = edges;
        sort(all(ed));
        for (ll i = 0; i < ed.size(); i++)
        {
            ll from = get<2>(ed[i]);
            ll to = get<1>(ed[i]);
            ll weight = get<0>(ed[i]);
            if (d.root(from) != d.root(to))
            {
                res += weight;
                d.unite(from, to);
                remaining--;
            }

        }
        return res;
    }



};


int main() {
    cin_;

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n, m;
    cin >> n >> m;
    vector<t3> edges(m);
    for (ll i = 0; i < m; i++)
    {
        ll from, to, weight;
        cin >> from >> to >> weight;
        from--;
        to--;
        edges[i] = tie(weight, from, to);
    }

    Graph g(edges, n);

    cout << g.kruscal();


    return 0;
}
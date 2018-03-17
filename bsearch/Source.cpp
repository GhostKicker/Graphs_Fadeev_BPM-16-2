#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <algorithm>
#include <tuple>
#define endl "\n"
#define fs first
#define sd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define deb(x) for(auto mew : (x))cout<<mew<<" ";cout<<endl;
#define debs(x) cout<<(x).size()<<": ";for(auto mew : (x))cout<<mew<<" ";cout<<endl;
#define deb_pair(x) cout<<(x).size()<<": ";for(auto mew : (x))cout<<mew.fs<<" "<<mew.sd<<endl;
#define cin_ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
typedef tuple<int, int, int> t3;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<db> vdb;
int inf = 1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

vl le;

bool pos(int curle, int k)
{
    for (int i = 0; i < le.size(); i++)
        k -= le[i] / curle;

    return (k <= 0);
}

ll bin_search(int k)
{
    int l = -1;
    int r = 10000001;

    while (l < r - 1)
    {
        int m = (l + r) / 2;

        if (pos(m, k))
            l = m;
        else
            r = m;
    }
    return l;
}


int main() {
    cin_;

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n, k;

    cin >> n >> k;

    le.resize(n);

    ll sumle = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> le[i];
        sumle += le[i];
    }

    if (sumle < k)
    {
        cout << 0;
        return 0;
    }

    if (sumle == k)
    {
        cout << 1;
        return 0;
    }

    cout << bin_search(k);

    return 0;
}
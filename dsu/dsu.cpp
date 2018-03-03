#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct dsu
{
    vector<int> p, r;
    dsu() {};

    void reass(int n)
    {
        p.resize(n);
        r.assign(n, 1);
        for (int i = 0; i < n; i++) p[i] = i;
    }

    dsu(int n)
    {
        p.resize(n);
        r.assign(n, 1);
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int root(int v)
    {
        if (v != p[v])
            p[v] = root(p[v]);
        return p[v];
    }
    void unite(int a, int b)
    {
        a = root(a);
        b = root(b);
        if (a == b) return;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        r[a] += r[b];
    }
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x = 0;

    string str;

    dsu u(1);

    while (cin >> str)
    {
        if (str == "RESET")
        {
            int n;
            cin >> n;
            u.reass(n);
            cout << "RESET DONE" << endl;
        }

        if (str == "JOIN")
        {
            int from, to;
            cin >> from >> to;
            if (u.root(from) != u.root(to))
            {
                u.unite(from, to);
            }
            else
            {
                cout << "ALREADY " << from << " " << to << endl;
            }
        }

        if (str == "CHECK")
        {
            int from, to;
            cin >> from >> to;
            if (u.root(from) == u.root(to))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }




    return 0;
}
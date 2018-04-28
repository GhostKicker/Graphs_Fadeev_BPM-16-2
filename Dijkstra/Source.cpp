#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int inf = 1e9 + 7;
int n;


vector<tuple<int, int, int> > edges; //w, i, j
vector<int> l;
vector<int> h;

vector<int> Dijkstra(int s)
{
    vector<int> res(n, inf);
    res[s] = 0;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, s));

    for (; !q.empty(); )
    {
        int dw = -q.top().first;
        int v = q.top().second;
        q.pop();

        if (dw > res[v]) continue;

        for (int i = h[v]; i != -1; i = l[i])
        {
            int w, from, to;
            tie(w, from, to) = edges[i];

            if (res[to] > res[from] + w)
            {
                res[to] = res[from] + w;
                q.push(make_pair(-res[to], to));
            }
        }
    }

    return res;

}



int main()
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int s, f;
    cin >> n >> s >> f;

    --s;
    --f;

    h.resize(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int w;
            cin >> w;

            if (i != j && w != -1)
            {
                edges.push_back(tie(w, i, j));
                l.resize(edges.size(), -1);
                l[edges.size() - 1] = h[i];
                h[i] = edges.size() - 1;
            }
        }
    }


    vector<int> d = Dijkstra(s);

    cout << (d[f] == inf ? -1 : d[f]);


}
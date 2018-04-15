#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

inline ptrdiff_t p(ptrdiff_t cur)
{
    return (cur - 1) / 2;
}

template <typename T>
void heapsort(vector<T>& v)
{
    ptrdiff_t n = v.size();

    // heaping array
    for (ptrdiff_t adding = 0; adding < n; ++adding)
        for (ptrdiff_t cur = adding; cur != 0; cur = p(cur))
            if (v[cur] > v[p(cur)])
                swap(v[cur], v[p(cur)]);
    //-----------

    for (ptrdiff_t deleting = n - 1; deleting > 0;)
    {
        swap(v[0], v[deleting--]);

        for (ptrdiff_t k = 0;;)
        {
            int state = 0;
            if (2 * k + 1 <= deleting && v[k] < v[2 * k + 1] && (2 * k + 2 > deleting || v[2 * k + 1] >= v[2 * k + 2]))
                state = 1; //will swap with left son
            if (2 * k + 2 <= deleting && v[k] < v[2 * k + 2] && (2 * k + 1 > deleting || v[2 * k + 1] <= v[2 * k + 2]))
                state = 2; //will swap with right son

            if (state == 0) break; // no need for continuation

            swap(v[k], v[2 * k + state]);
            k = 2 * k + state;
        }
    }

}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ptrdiff_t n;
    cin >> n;

    vector<int> v(n);

    for (ptrdiff_t i = 0; i < n; ++i)
        cin >> v[i];

    heapsort(v);

    for (auto it : v)
        cout << it << " ";

}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vv(ll);

#define o(x) cout << (x) << " ";
#define o2(x, y) cout << (x) << " " << (y) << " ";
#define o3(x, y, z) cout << (x) << " " << (y) << " " << (z) << " ";
#define oe(x) cout << (x) << endl;
#define oe2(x, y) cout << (x) << " " << (y) << endl;
#define oe3(x, y, z) cout << (x) << " " << (y) << " " << (z) << endl;

#define fl(i, n) for (ll i = 0; i < n; i++)
#define inarr(arr, n)          \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]

class DisJoint
{
    vector<int> rank;
    vector<int> parent;

public:
    DisJoint(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findParent(int node)
    {
        if (node != parent[node])
        {
            parent[node] = findParent(parent[node]); // Recursive compression
        }
        return parent[node];
    }

    bool connected(int a, int b) {
    return findParent(a) == findParent(b);
    }

    void unionByRank(int u, int v)
    {
        int ulPu = findParent(u);
        int ulPv = findParent(v);
        if (ulPu == ulPv)
            return;
        if (rank[ulPu] < rank[ulPv])
        {
            parent[ulPu] = ulPv;
        }
        else if (rank[ulPu] > rank[ulPv])
        {
            parent[ulPv] = ulPu;
        }
        else
        {
            parent[ulPv] = ulPu;
            rank[ulPu]++;
        }
    }
};
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int>> F;
    vector<pair<int, int>> G;
    DisJoint F1(n + 1);
    DisJoint G1(n + 1);
    for (int i = 0; i < a; i++)
    {
        int u, v;
        cin >> u >> v;
        F.push_back({u - 1, v - 1});
    }
    for (int i = 0; i < b; i++)
    {
        int u, v;
        cin >> u >> v;
        G.push_back({u - 1, v - 1});
    }
    for (pair<int, int> p : G)
    {
        G1.unionByRank(p.first, p.second);
    }
    int cnt = 0;
    for (pair<int, int> p : F)
    {
        if (G1.connected(p.first, p.second))
        {
            F1.unionByRank(p.first, p.second);
        }
        else
        {
            cnt++;
        }
    }
    set<ll> s1, s2;
    fl(i, n)
    {
        s1.insert(F1.findParent(i));
        s2.insert(G1.findParent(i));
    }
    cnt += (s1.size() - s2.size());
    cout << cnt << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

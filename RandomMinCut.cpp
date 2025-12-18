#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &parent) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x], parent);
}

void Union(int a, int b, vector<int> &parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b)
        parent[b] = a;
}

int RandomMinCut(int n, vector<pair<int,int>> edges) {
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int v = n;

    while (v>2) {
        int idx = rand() % edges.size();
        int u = edges[idx].first;
        int v = edges[idx].second;

        int pu = find(u, parent);
        int pv = find(v, parent);

        if (pu == pv)
            continue;

        Union(pu, pv, parent);
        v--;
    }

    int cut = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (find(edges[i].first, parent) !=
            find(edges[i].second, parent)) {
            cut++;
        }
    }

    return cut;
}

int main() {
    int n, m;
    cin>>n>>m;

    vector<pair<int,int>>edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;
        edges.push_back({u, v});
    }

    srand(time(0));


    int minCut = INT_MAX;

    for (int i = 0;i<n*n;i++) {
        minCut = min(minCut, RandomMinCut(n, edges));
    }

    cout << "Minimum Cut: " <<minCut<<endl;
    return 0;
}

/*
4
5
1 2
2 4
1 4
3 4
1 3
*/
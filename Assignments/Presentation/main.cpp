#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> intP;

// Structure to represent a graph
struct Graph
{
    int V, E;
    vector<pair<int, intP>> edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    // Function returns weight of the MST
    int kruskalMST();
};

// represent disjoint sets
struct Disjoint
{
    int *parent, *rnk;
    int n;

    Disjoint(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rnk = new int[n + 1];

        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            // every element is parent of itself
            parent[i] = i;
        }
    }

    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path
        from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        /* Make tree with smaller height
        a subtree of the other tree */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};


/*  
    1. Sort all the edges in non-decreasing order of their weight.
    2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
    If cycle is not formed, include this edge. Else, discard it. 
    Repeat step#2 until there are (V-1) edges in the spanning tree. 
*/
int Graph::kruskalMST()
{
    int mst_wt = 0; // Initialize result

    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    Disjoint ds(V);

    // Iterate through all sorted edges
    vector<pair<int, intP>>::iterator it;

    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Update MST weight
            mst_wt += it->first;

            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;
}

int main()
{
    int m;        // # of junctions (vertices)
    int n;        // # of roads (edges)
    int x;        // intial junction (starting point)
    int y;        // terminal junction (ending point)
    int z;        // length of road (weight)
    int initCost; // initial cost

    // Terminate program when m == n == 0
    while (cin >> m && cin >> n && m && n)
    {
        Graph G(m, n);
        initCost = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            G.addEdge(x, y, z);
            initCost += z;
        }
        cout << initCost - G.kruskalMST() << '\n';
    }
    return 0;
}
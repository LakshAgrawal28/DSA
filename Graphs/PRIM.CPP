#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        // {wt, node, parent}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<int> vis(V, 0);
        vector<pair<int,int>> mstEdges; // {parent, node}
        int sum = 0;

        pq.push({0, 0, -1}); // wt, node, parent

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it[0];
            int node = it[1];
            int parent = it[2];

            if (vis[node]) continue;

            vis[node] = 1;
            sum += wt;

            if (parent != -1) {
                mstEdges.push_back({parent, node});
            }

            for (auto edge : adj[node]) {
                int adjNode = edge[0];
                int edW = edge[1];

                if (!vis[adjNode]) {
                    pq.push({edW, adjNode, node});
                }
            }
        }

        // Print MST
        cout << "MST edges:\n";
        for (auto it : mstEdges) {
            cout << it.first << " - " << it.second << "\n";
        }

        return sum;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0,1,2},{0,2,1},{1,2,1},
        {2,3,2},{3,4,1},{4,2,2}
    };

    vector<vector<int>> adj[V];
    for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    Solution obj;
    int sum = obj.spanningTree(V, adj);

    cout << "The sum of all the edge weights: " << sum << endl;
    return 0;
}

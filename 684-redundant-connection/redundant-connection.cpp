class Solution {
public:

    bool f(int src, int target, vector<int> adj[], int n) {

        queue<int> q;
        vector<int> vis(n + 1, 0);

        q.push(src);
        vis[src] = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            if (node == target) {
                return true;
            }

            for (auto adjNode : adj[node]) {

                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        // +1 because nodes are numbered from 1 to n
        vector<int> adj[n + 1];

        for (auto it : edges) {

            int src = it[0];
            int target = it[1];

            // First check whether a path already exists
            if (f(src, target, adj, n)) {
                return {src, target};
            }

            // If no path exists, add this edge
            adj[src].push_back(target);
            adj[target].push_back(src);
        }

        return {};
    }
};
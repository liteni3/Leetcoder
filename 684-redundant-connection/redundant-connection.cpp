class Solution {
public:
    bool f(int src, int target,vector<vector<int>> edges, vector<int> adj[] ){
        queue<int> q;
        vector<int> vis(edges.size()+1,-1); // n+1 size of visited array because the edges starts from 1 number 
        q.push(src);
        vis[src]=1; 
        while(!q.empty()){
            int ref= q.front();
            q.pop();
            if(ref==target)return true;
            for(auto it : adj[ref]){
                if(vis[it]==-1){
                q.push(it);
                vis[it]=1;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // The idea is start building the graph and check every time while iterating through edges if there is any path that exists between source and target where src= 0th endex and target = 1st index of every edge 
        int n=edges.size();
        vector<int> adj[n + 1];
        for(int i=0;i<edges.size();i++){
            int src= edges[i][0];
            int target= edges[i][1];
            if(f(src,target,edges,adj)== true){
                return {src,target};
          }else {
            adj[src].push_back(target);
            adj[target].push_back(src);
          }
        }
        return {-1,-1};
    }
};
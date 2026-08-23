class Solution {
public:
    bool bfs(vector<int>& color,int i,vector<vector<int>> &adj){
        color[i]=1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto it : adj[top]){
                if(color[it]==-1){
                    color[it]=1-color[top];
                    q.push(it);
                }
                else if(color[it]==color[top]){
                  return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> color(n,-1); 
        for(int i=0;i<color.size();i++){
            if(color[i]==-1){
                if(bfs(color,i,adj)==false)return false;
            }
        }
        return true;
    }
};
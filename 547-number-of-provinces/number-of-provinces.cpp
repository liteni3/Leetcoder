class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        //create a visited array
        vector<int> vis(n+1,0);
        queue<int> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                     int k = q.front();
                     q.pop();
                     for(auto it : adj[k]){
                        if(vis[it]==0){
                            vis[it]=1;
                            q.push(it);
                        }
                        
                     }
                }
            }
        }
        return cnt;
    }
};
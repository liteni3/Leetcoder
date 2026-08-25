class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        int row[]={1,-1,0,0};
        int col[]={0,0,1,-1};
        grid[i][j]='0';
        q.push({i,j});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int r1=r+row[k];
                int c1=c+col[k];
                if(r1>=0 && r1<grid.size() && c1>=0 && c1<grid[0].size() && grid[r1][c1]=='1'){
                    q.push({r1,c1});
                    grid[r1][c1]='0';
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        //BFS
        // iterate through whole grid using bfs and keep on updating grid[i][j]==1 then grid[i][j]='0'
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};
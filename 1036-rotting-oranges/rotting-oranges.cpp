class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int r=grid.size(); // number of rows
        int c=grid[0].size(); //number of colomns
        int vis[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else vis[i][j]=0;
            }
        }

        //bfs
        // (-1,0) , (1,0) , (0,1) , (0,-1)
        int row[]={-1,1,0,0};
        int col[]={0,0,1,-1};
        int tm=0;
        while(!q.empty()){
            int r1=q.front().first.first;
            int c1=q.front().first.second;
            tm=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r2=r1+row[i];
                int c2=c1+col[i];
                if(r2>=0 && r2<r && c2>=0 && c2<c && grid[r2][c2]==1 && vis[r2][c2]!=2){
                    q.push({{r2,c2},tm+1});
                    vis[r2][c2]=2;
                }
            }

        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0 && grid[i][j]==1)return -1;
            }
        }
        return tm;

    }
};
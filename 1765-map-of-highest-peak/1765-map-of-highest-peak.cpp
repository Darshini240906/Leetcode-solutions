class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(auto& d:dirs){
                int nr=r+d[0], nc=c+d[1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && height[nr][nc]==-1){
                    height[nr][nc]=height[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return height;
    }
};
